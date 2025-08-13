#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverse(queue<int> &Queue){
    stack<int> Stack;

    while(!Queue.empty()){
        Stack.push(Queue.front());
        Queue.pop();
    }
    while(!Stack.empty()){
        Queue.push(Stack.top());
        Stack.pop();
    }
    
    return;
};

int main(){
    queue<int> Queue;
    Queue.push(1);
    Queue.push(2);
    Queue.push(3);
    Queue.push(4);
    Queue.push(5);
  
    reverse(Queue);
    while(!Queue.empty()){
        cout<<Queue.front()<<" ";
        Queue.pop();
    }cout<<endl;
}