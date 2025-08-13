#include<iostream>
#include<queue>
using namespace std;

void interleave(queue<int> &org){
    queue<int> first;
    int n =org.size();
    for(int i=0;i<n/2;i++){
        first.push(i+1);
    }
    for(int i =0;i<n/2;i++){
        org.pop();
    }
    while(!first.empty()){
        org.push(first.front());
        first.pop();
        org.push(org.front());
        org.pop();
    }
};

int main(){
    queue<int> org;
    for(int i=0;i<10;i++){
        org.push(i+1);
    } 
    interleave(org);
    while(!org.empty()){
        cout<<org.front()<<" ";
        org.pop();
    }cout<<endl;
}