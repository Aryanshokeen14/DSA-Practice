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

void KthLevel(Node* root , int k, vector<int>& ans){
    if(root==NULL){
        return;
    }
    if(k==1){
        ans.push_back(root->data);
        return;
    }
    KthLevel(root->left,k-1,ans);
    KthLevel(root->right,k-1,ans);
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,7,-1,-1};
    Node* root = buildTree(nodes);
    int k =3;   
    vector<int> ans;
    KthLevel(root,k,ans);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    return 0;
}