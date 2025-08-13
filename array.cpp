#include<iostream>
using namespace std;
int power(int x , int n){
    if(n == 0 ){
        return 1;
    }
    int halfpow = power(x,n/2);
    int halfpowSq = halfpow * halfpow;
    if(n%2 != 0){
        return  x * halfpowSq;
    };
    return halfpowSq;
};
int main(){
    cout<<power(2,10);
}