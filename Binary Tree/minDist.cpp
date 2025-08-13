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

int dist(Node *root, int n)
{
    if (root == NULL)
        return -1;
    if (root->data == n)
        return 0;

    int leftDist = dist(root->left, n);
    if (leftDist != -1)
        return leftDist + 1;

    int rightDist = dist(root->right, n);
    if (rightDist != -1)
        return rightDist + 1;

    return -1;
}

Node *LCA(Node *root, int p, int q)
{
    if (root == NULL)
        return NULL;
    if (root->data == p || root->data == q)
        return root;

    Node *left = LCA(root->left, p, q);
    Node *right = LCA(root->right, p, q);

    if (left && right)
        return root;

    return (left != NULL) ? left : right;
}

int minDist(Node *root, int n1, int n2)
{
    Node *lca = LCA(root, n1, n2);
    if (!lca)
        return -1;

    int d1 = dist(lca, n1);
    int d2 = dist(lca, n2);

    if (d1 == -1 || d2 == -1)
        return -1; // one of the nodes doesn't exist

    return d1 + d2;
}

int main()
{
    vector<int> nodes = {1, 2, 3, -1, -1, 4, 5, -1, -1, -1};
    int indx = 0;
    Node *root = buildTree(nodes, indx);

    int n1 = 4;
    int n2 = 5;
    cout << "Minimum distance between " << n1 << " and " << n2 << " is: " << minDist(root, n1, n2) << endl;

    return 0;
}
