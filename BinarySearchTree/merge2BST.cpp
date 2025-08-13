#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left=right=NULL;
    };
};

void getInorder(Node* root , vector<int>& nodes){
    if(root==NULL){
        return;
    }
    getInorder(root->left,nodes);
    nodes.push_back(root->data);
    getInorder(root->right,nodes);
}

Node* balancedBSTfromSorted(vector<int> arr, int st , int end){
    if(st>end){
        return NULL;
    }
    int mid = st + (end-st)/2;
    Node* curr = new Node(arr[mid]);
    curr->left = balancedBSTfromSorted(arr,st,mid-1);
    curr->right = balancedBSTfromSorted(arr,mid+1,end);

    return curr;
};

Node* mergeBST(Node* root1 , Node* root2){
    vector<int> nodes1;
    vector<int> nodes2;
    vector<int> merge;
    getInorder(root1,nodes1);
    getInorder(root2,nodes2);

    int i=0,j=0;
    while(i<nodes1.size() && j<nodes2.size()){
        if(nodes1[i] < nodes2[j]){
            merge.push_back(nodes1[i]);
            i++;
        }else{
            merge.push_back(nodes2[j]);
            j++;
        }
    }
    while(i<nodes1.size()){
        merge.push_back(nodes1[i++]);
    }
    while(j<nodes2.size()){
        merge.push_back(nodes2[j++]);
    }
    return balancedBSTfromSorted(merge , 0 , merge.size()-1);
}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
};

int main(){
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    Node* root2 = new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(12);

    Node* root = mergeBST(root1,root2);
    preOrder(root);
    cout<<endl;
return 0;
}