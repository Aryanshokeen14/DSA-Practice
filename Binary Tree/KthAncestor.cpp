#include <iostream>
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

int KthAncestor(Node *root , int node , int k ){
    if(root==NULL){
        return -1;
    }
    if(root->data == node){
        return 0;
    }
    int leftDist = KthAncestor(root->left , node , k);
    int rightDist = KthAncestor(root->right , node , k);

    if(leftDist == -1 && rightDist == -1){
        return -1;
    }
    int validVal = (leftDist != -1) ? leftDist : rightDist;
    if(validVal +1 == k){
        cout<< root->data << " ";
    }
    return validVal +1;
}



int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5,-1,-1,3,-1,6,-1,-1};
    int indx = 0;
    Node *root = buildTree(nodes, indx);

    int node = 6 , k=1;
    cout<< "Kth Ancestor of node " << node << " is: ";
    KthAncestor(root, node, k);
    cout << endl;

    return 0;
}