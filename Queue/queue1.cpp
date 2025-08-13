#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Queue{
    Node* head;
    Node* tail;
public:
    Queue(){
        head=tail=NULL;
    }
    void push(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    void pop(){
        if(isempty()){
            cout<<"queue is empty"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    int front(){
        if(isempty()){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        return head->data;
    }
    bool isempty(){
        return head==NULL;
    }

};

int main()
{
    Queue q;
    q.push(4);
    q.push(3);
    q.push(2);
    q.push(1);

    while(!q.isempty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}