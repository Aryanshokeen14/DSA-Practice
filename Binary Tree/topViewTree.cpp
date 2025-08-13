#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        right=left=NULL;
    }
};

static int indx =-1;

Node* buildTree(vector<int> nodes){
    indx++;
    if(nodes[indx]==-1){
        return NULL;
    }
    Node* currNode = new Node(nodes[indx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);
    return currNode;
}

void topViewTree(Node* root){
    queue<pair<int , Node*>> q; //(horizontal distance , node)
    map<int,int> m; //(hd, node->data) = (key,value)

    q.push(make_pair(0,root));
    while(!q.empty()){
        pair<int , Node*> curr = q.front();
        q.pop();

        int currHD = curr.first;
        Node* currNode = curr.second;

        if(!m.count(currHD)){ // if not present count will give 0 value
            m[currHD] = currNode->data;
        }
        if(currNode->left != NULL){
            pair<int,Node*> left = make_pair(currHD-1 , currNode->left);
            q.push(left);
        }
        if(currNode->right != NULL){
            pair<int,Node*> right = make_pair(currHD+1 , currNode->right);
            q.push(right);
        }
    }
    for(auto it: m){
        cout<<it.second<<" ";
    }cout<<endl;

};


int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    topViewTree(root);
return 0;
}