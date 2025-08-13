#include<iostream>
using namespace std;

int friendsPairing(int n){
    //base case
    if(n==1 || n==2){
        return n;
    }
    //single+pair
    return friendsPairing(n-1) + (n-1)*friendsPairing(n-2);
}

int main(){
    cout<<friendsPairing(5);
}