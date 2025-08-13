#include<iostream>
#include<stack>
#include<string>
using namespace std;

void pushAtBottom(stack<int> &s , int val){
    if(s.empty()){
        s.push(val);
        return ;
    }
    int temp = s.top();
    s.pop();
    pushAtBottom(s,val);
    s.push(temp);
};

void stackReverse(stack<char> &a ){
    if(a.empty()){
        return ;
    }
    char temp = a.top();
    a.pop();
    stackReverse(a);
    cout<<temp<<" ";
};

string reverseString(string str){
    string ans;
    stack<char> s;
    for(int i=0;i<str.size();i++){
        s.push(str[i]);
    }
    while(!s.empty()){
        char top = s.top();
        ans+=top;
        s.pop();
    }
    return ans;
};

void reverse(stack<int> &s){
    if(s.empty()){
        return;
    }
    int temp = s.top();
    s.pop();
    reverse(s);
    pushAtBottom(s,temp);
};
void printStack(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
int main(){
    // stack<int> s;
    // s.push(30);
    // s.push(20);
    // s.push(10);
    // pushAtBottom(s,40);
    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // };
    // cout<<endl;

    
    // stack printing in same order of push 
    // stack<char> a;
    // a.push('a');
    // a.push('b');
    // a.push('c');
    // stackReverse(a);
    // while(!a.empty()){
    //     cout<<a.top()<<" ";
    //     a.pop();
    // }


    // string str = "abcd";
    // cout<<"reverse : "<< reverseString(str)<<endl;
    // return 0;

    stack<int> b;
    b.push(3);
    b.push(2);
    b.push(1);
    printStack(b);
    reverse(b);
    printStack(b);

    return 0;
}