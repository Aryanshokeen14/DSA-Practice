#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverse(queue<int>& q , int k ){
    stack<int> s;
    for(int i=0;i<k;i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    for(int i=0;i<q.size()-k;i++){
        q.push(q.front());
        q.pop();
    }
    return;
};

int main(){
    int k =8;
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);

    reverse(q,k);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }cout<<endl;
return 0;
}