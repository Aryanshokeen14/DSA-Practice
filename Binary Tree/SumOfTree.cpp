#include <iostream>
#include<queue>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

Node *buildTree(vector<int> &nodes, int &indx)
{
    if (indx >= nodes.size() || nodes[indx] == -1)
    {
        indx++;
        return NULL;
    }

    Node *currNode = new Node(nodes[indx++]);
    currNode->left = buildTree(nodes, indx);
    currNode->right = buildTree(nodes, indx);
    return currNode;
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


int transform(Node *root){
    if(root==NULL){
        return 0;
    }
    int leftOld = transform(root->left);
    int rightOld = transform(root->right);
    int currOld = root->data;

    root->data = leftOld + rightOld ;
    if(root->left != NULL){
        root->data += root->left->data;
    }
    if(root->right != NULL){
        root->data += root->right->data;
    }
   
    return currOld;
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5,-1,-1,3,-1,6,-1,-1};
    int indx = 0;
    Node *root = buildTree(nodes, indx);

    levelOrder(root);
    transform(root);
    levelOrder(root);
    return 0;
}