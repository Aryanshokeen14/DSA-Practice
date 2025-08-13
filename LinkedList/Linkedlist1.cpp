#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
    ~Node(){
        if(next!=NULL){
            delete next;
            next = NULL;
        }
    }
};

class List{
    Node* head;
    Node* tail;
public:
    List(){
        head=NULL;
        tail=NULL;
    }
    ~List(){
        if(head!=NULL){
            delete head;
            head=NULL; 
        }
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = tail = newNode;
        }
        else{
            newNode->next= head;
            head = newNode;
        }
    }
    
    void push_back(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = tail = newNode;
        }
        else{
            tail->next= newNode;
            tail = newNode;
        }
    }
    void pop_front(){
        if(head!=NULL){
            Node* temp = head;
            head=head->next;
            temp->next=NULL;
            delete temp;
        }
    }
    void pop_back(){
        Node* temp = head;
        for(int i=0;;i++){
            temp=temp->next;
            if(temp->next==tail){
                temp->next = NULL;
                delete tail;
                tail=temp;
                return;
            }
        }
    }
    void insert(int val , int pos){
        Node* newNode = new Node(val);
        Node* temp = head;
        for(int i=0;i<pos-1;i++){
            if(temp==NULL){
                cout<<"invalid pos"<<endl;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;

    }
    void printlist(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    int searchKey(int key){
        Node* temp = head;
        int indx=0;
        while(temp != NULL){
            if(temp->data == key){
                return indx;
            }
            temp=temp->next;
            indx++;
        }
        return -1;

    }
    int helper(Node* temp,int key){
        if(temp==NULL){
            return -1;
        }
        if(temp->data==key){
            return 0;
        }
        int index = helper(temp->next,key);
        if(index==-1){
            return -1;
        }
        return index+1;
    }
    int searchRecursive(int key){
        cout<<"found at: ";
        return helper(head,key);
    }
    void reverse(){
        Node* curr = head;
        Node* prev = NULL;
        tail=prev;
        while(curr!=NULL){
            Node* next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
    }
    int getsize(){
        Node* temp = head;
        int size=0;
       while(temp!=NULL){
        temp=temp->next;
        size++;
       }
        return size;
    }
    void removenth(int n){
        int size = getsize();
        Node* prev = head;
        for(int i =1;i<size-n;i++){
            prev=prev->next;
        }
        Node* todel = prev->next;
        cout<<"going to delte "<<todel->data<<endl;
        prev->next = prev->next->next;
    }
};

int main(){
    List ll;
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printlist();

    // cout<<ll.searchKey(-5)<<endl;
    // cout<<ll.searchRecursive(6);
    // ll.reverse();

    ll.removenth(3);
    ll.printlist();
    return 0;
}