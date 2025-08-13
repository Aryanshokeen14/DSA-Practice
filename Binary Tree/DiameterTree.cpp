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

int height(Node* root){
    if(root==NULL){
        return 0 ;
    }
    int leftHt = height(root->left);
    int rightHt = height(root->right);
    int curr = max(leftHt,rightHt)+1;
    return curr;
}

int diameter1(Node* root){ //O(n^2)
    if(root==NULL){
        return 0;
    }
    int currDiam = height(root->left) + height(root->right) +1; //O(n)
    int leftDiam = diameter1(root->left);
    int rightDiam = diameter1(root->right);
    int ans = max(max(currDiam,leftDiam),rightDiam);
    return ans;
};

pair<int,int> diam2(Node* root){ //O(n)
    if(root==NULL){
        return make_pair(0,0);
    }
    //(diameter,height)
    pair<int,int> leftInfo = diam2(root->left);//(LD,LH)
    pair<int,int> rightInfo = diam2(root->right);//(RD,RH)

    int currDiam = leftInfo.second + rightInfo.second +1;
    int fianalDiam = max(currDiam,max(leftInfo.first,rightInfo.first));
    int finalHt = max(leftInfo.second , rightInfo.second) +1;
    return make_pair(fianalDiam,finalHt);
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    // cout<<"diameter = "<<diameter1(root);
    cout<<"diameter : "<<diam2(root).first<<endl;
}