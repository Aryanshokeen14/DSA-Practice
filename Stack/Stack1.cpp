#include<iostream>
#include<vector>
#include<list>
using namespace std;

template<class T>

//create stack using vector
// class Stack{
//     vector<T> stack;
//     public:
//     void push(T val){  //O(1)
//         stack.push_back(val);
//     }
//     void pop(){ //O(1)
//         if(isEmpty()){
//             cout<<"stack is empty"<<endl;
//             return ;
//         }
//         stack.pop_back();
//     }
//     T top(){ //O(1)
//         // if(isEmpty()){
//         //     cout<<"stack is empty"<<endl;
//         //     return -1;
//         // }
//         int lastindx = stack.size()-1;
//         return stack[lastindx];
//     }
//     bool isEmpty(){ //O(1)
//         return stack.size()==0;
//     }
// };


//create stack using linked list
class Stack{
    list<T> ll;
    public:
    void push(T val){
        ll.push_front();
    }
    void pop(){
        ll.pop_front();
    }
    T top(){
        return ll.front();
    };
    bool isEmpty(){
        return ll.size()==0;
    }
};

template<class T>
class  Node{
    public:
    T data;
    Node* next;
    Node(T val){
        data=val;
        next=NULL;
    }
};

int main(){
    // Stack<int> s;

    //stl stack "stack"
    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

}