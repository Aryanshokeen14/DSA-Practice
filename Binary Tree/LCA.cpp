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
        right = left = NULL;
    }
};

static int indx = -1;

Node *buildTree(vector<int> nodes)
{
    indx++;
    if (nodes[indx] == -1)
    {
        return NULL;
    }
    Node *currNode = new Node(nodes[indx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);
    return currNode;
}

class Solution
{
public:
    Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
    {
        // base case
        if (root == NULL || root == p || root == q)
        {
            return root;
        }
        Node *left = lowestCommonAncestor(root->left, p, q);
        Node *right = lowestCommonAncestor(root->right, p, q);

        // result
        if (left == NULL)
        {
            return right;
        }
        else if (right == NULL)
        {
            return left;
        }
        else
        { // both left and right are not null, we found our result
            return root;
        }
    }

    int LCA(Node *root, int n1, int n2)
    {
        if (root == NULL)
        {
            return -1;
        }
        if (root->data == n1 || root->data == n2)
        {
            return root->data;
        }

        int leftLCA = LCA(root->left, n1, n2);
        int rightLCA = LCA(root->right, n1, n2);

        if (leftLCA != -1 && rightLCA != -1)
        {
            return root->data;
        }
        
        return (leftLCA != -1) ? leftLCA : rightLCA;
    }
};

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(nodes);
    Solution sol;

    int n1 = 4, n2 = 5;
    sol.LCA(root, n1, n2) != -1 ? cout << "LCA of " << n1 << " and " << n2 << " is: " << sol.LCA(root, n1, n2) << endl : cout << "LCA not found" << endl;

    Node *p = root->left;         // Assuming p is the node with value 2
    Node *q = root->right->right; // Assuming q is the node with value 6
    Node *lca = sol.lowestCommonAncestor(root, p, q);
    if (lca != NULL)
    {
        cout << "LCA of " << p->data << " and " << q->data << " is: " << lca->data << endl;
    }
    else
    {
        cout << "LCA not found" << endl;
    }
}