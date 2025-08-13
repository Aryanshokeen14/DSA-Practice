#include<iostream>
using namespace std;

int xpowerN(int x , int n){
    if(n==0){
        return 1;
    }
    int xhalfpower = pow(x,n/2);
    int XpowerN = xhalfpower*xhalfpower;
    if(n%2!=0){
        return x*XpowerN;
    }else{

        return XpowerN;
    }
};

int main(){
    cout<<xpowerN(2,10);
}