#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        right = left = NULL;
    }
};

Node *buildTree(vector<int> &nodes , int &indx){
    if(indx>= nodes.size() || nodes[indx] == -1){
        indx++;
        return NULL;
    }
    Node *currNode = new Node(nodes[indx++]);
    currNode->left = buildTree(nodes,indx);
    currNode->right = buildTree(nodes,indx);
    return currNode;
};

vector<int> bottomView(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    queue<pair<int , Node*>> q; //horizontal distance and node
    map<int , int> m; // HD and node->data

    q.push(make_pair(0,root));
    while(!q.empty()){
        pair<int,Node*> curr = q.front();
        q.pop();

        int currHD = curr.first;
        Node* currNode = curr.second;
        
        m[currHD] = currNode->data;
        if(currNode->left != NULL){
            q.push(make_pair(currHD-1,currNode->left));
        }
        if(currNode->right != NULL){
            q.push(make_pair(currHD+1 , currNode->right));
        }
    }
    for(auto it:m){
        ans.push_back(it.second);
    }
    return ans;
};

int main(){
    vector<int> nodes= {1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,7,-1,-1};
    int indx=0;
    Node* root = buildTree(nodes,indx);

    vector<int> result = bottomView(root);

    for(auto it: result){
        cout<<it<<" ";
    }cout<<endl;
return 0;
}