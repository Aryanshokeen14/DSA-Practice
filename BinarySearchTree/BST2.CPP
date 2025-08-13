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

Node* buildBSTfromSorted(int arr[], int st , int end){
    if(st>end){
        return NULL;
    }
    int mid = st + (end-st)/2;
    Node* curr = new Node(arr[mid]);
    curr->left = buildBSTfromSorted(arr,st,mid-1);
    curr->right = buildBSTfromSorted(arr,mid+1,end);

    return curr;
};

void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
};

Node* insert(Node* root, int val){
    if(root==NULL){
        root= new Node(val);
        return root;
    }
    if(val< root->data){//insert at left subtree
        root->left = insert(root->left,val);
    }
    else if(val>root->data){//insert at right subtree
        root->right = insert(root->right ,val);
    }
    return root;
};

Node* buildBST(int arr[] , int n){
    Node* root = NULL;
    for(int i =0;i<n;i++){
        root=insert(root,arr[i]);
    }
    return root;
};

void inOrder(Node* root , vector<int> &arr){
    if(root == NULL){
        return;
    }
    inOrder(root->left,arr);
    arr.push_back(root->data);
    inOrder(root->right,arr);
    
    return;
};

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

Node* BSTtoBalancedBST(Node* root){
    vector<int> arr;
    inOrder(root , arr);
    return balancedBSTfromSorted(arr,0,8);
};

int main(){
    int arr[7] = {3,4,5,6,7,8,9};
   
    // Node* root = buildBSTfromSorted(arr,0,6);
    // preOrder(root);
    // cout<<endl;

    int arr2[8] = {8,5,4,3,1,10,11,14};
    Node* root = buildBST(arr2,8);
    Node* ans = BSTtoBalancedBST(root);
    cout<<ans->data;
return 0;
}
