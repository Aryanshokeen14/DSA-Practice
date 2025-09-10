#include<iostream>
using namespace std;

void binStr(string ans , int n , int lastPlace){
    if(n == 0){
        cout<<ans<<endl;
        return;
    }

    if(lastPlace!=1){
        binStr(ans+'0', n-1 , 0);
        binStr(ans+'1', n-1 , 1);
    }else{
        binStr(ans+'0', n-1 , 0);
    }
}

int main(){
    string ans = "";
    binStr(ans,5,0);
}