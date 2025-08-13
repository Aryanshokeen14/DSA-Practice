#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left=right=NULL;
    }
};

static int indx = -1;

Node* buildTree(vector<int> nodes){
    indx++;
    if(nodes[indx]==-1){
        return NULL;
    }

    Node* currNode = new Node(nodes[indx]);
    currNode->left = buildTree(nodes);//left subtree
    currNode->right = buildTree(nodes);//right subtree

    return currNode;
};

void preOrder(Node* root){
    if(root ==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
};

void inOrder(Node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);

}

void postOrder(Node* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";

}

void levelOrder(Node* root){ //O(n)
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* curr= q.front();
        q.pop();
        if(curr == NULL){
            cout<<endl;
            if(q.empty()){
                break;
            }
            q.push(NULL);
        }
        else{
            cout<<curr->data<<" ";
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            };
        }
    }
};

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftht= height(root->left);
    int rightht= height(root->right);
    int curr = max(leftht,rightht)+1;
    return curr;
};

int count(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftCount = count(root->left);
    int rightCount = count(root->right);
    return leftCount+rightCount+1;
};

int sumOfNodes(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);
    return leftSum+rightSum+root->data;
};

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);
    // cout<<"root node : "<<root->data<<endl;

    // cout<<"preOrder: ";
    // preOrder(root);cout<<endl;
  
    // cout<<"inOrder: ";
    // inOrder(root);cout<<endl;

    // cout<<"postOrder: ";
    // postOrder(root);cout<<endl;

    //  levelOrder(root);
    
    // cout<<"height Of tree: "<<height(root)<<endl;

    // cout<<"no. of nodes are: "<<count(root);

    cout<<"sum of nodes: "<<sumOfNodes(root);

return 0 ;
}