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

void inOrder(Node* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

bool Search(Node* root, int key){// O(h).  ,  in avg case O(logn)
    if(root==NULL){
        return false;
    }
    if(root->data ==key){
        return true;
    }
    else if(root->data < key){// go for right subtree
        return Search(root->right,key);
    }else{ //go for left subtree
        return Search(root->left,key);
    }
};

Node* getInorderSuccessor(Node* root){
    while(root->left !=NULL){
        root = root->left;
    }
    return root;
};

Node* delNode(Node* root, int val){
    if(root == NULL){
        return NULL;
    }
    
    if(val < root->data){// go to left subtree
        root->left = delNode(root->left,val);
    }else if(val> root->data){ // got to right subtree
        root->right = delNode(root->right , val);
    }else{ // when root == val
        // case1: when root has 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // case2: when 1 child
        else if(root->left == NULL || root->right == NULL){
            return root->left == NULL ? root->right : root->left;
        }
        
        //case 3 when 2 child
        Node* IS = getInorderSuccessor(root->right);
        root->data = IS->data;
        root->right = delNode(root->right , IS->data);
        return root;
    }
    return root;
}

void printInRange(Node* root , int start , int end){
    if(root == NULL){
        return;
    }

    if( start<= root->data && root->data<=end){//case1
        printInRange(root->left,start,end);
        cout<<root->data<<" ";
        printInRange(root->right,start,end);
    }else if(root->data < start){//case2
        printInRange(root->right,start,end);
    }else{//case3
        printInRange(root->left,start,end);
    }
};

void rootToLeafPath(Node* root , vector<int> &path){
    if(root==NULL){
        return;
    }
    
    path.push_back(root->data);
    if(root->left == NULL && root->right == NULL){ // leaf node
        for(auto i:path){
            cout<<i<<" ";
        }cout<<endl;
        path.pop_back();
        return;
    }
    
    rootToLeafPath(root->left,path);
    rootToLeafPath(root->right,path);

    path.pop_back();
};

bool valideBST(Node* root , int min , int max){
    if(root == NULL){
        return true;
    }
    if(root->data <= min || root->data >= max){
        return false;
    }
    
    return valideBST(root->left,min,root->data) && valideBST(root->right,root->data,max);
};

int main(){
    int arr[9] = {8,5,3,1,4,6,10,11,14};
    Node* root =  buildBST(arr,9);
    
    // inOrder(root);
    // cout<<endl;
    
    // vector<int>path;
    // rootToLeafPath(root ,path);


    // root->data = 15;
    // cout<<valideBST(root,INT_MIN,INT_MAX);


return 0;
}