#include<iostream>
using namespace std;

int fbDP(int n , vector<int> &f){
    if( n ==1 || n==0){
        return n;
    }
    if(f[n] != -1){
        return f[n];
    }
    f[n] = fbDP(n-1 , f) + fbDP(n-2 , f);
    cout<<f[n]<<" ";
    return f[n];
};

int main(){
    int n =6;
    vector<int> f (n+1,-1);
    cout<<"0 1 ";
    fbDP(n,f);
return 0;
}