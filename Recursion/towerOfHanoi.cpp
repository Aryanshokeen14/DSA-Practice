#include<iostream>
using namespace std;

void towerHanoi(int n , string src , string helper , string dest){
    //base case
    if(n==1){
        cout<<"trnsf disk "<<n<<" from "<<src<<" to "<<dest<<endl;
        return;
    }

    //trnsf top(n-1)disk from src to helper using dest
    towerHanoi(n-1, src , dest , helper);

    cout<<"trnsf disk "<<n<<" from "<<src<<" to "<<dest<<endl;
    
    //tnsf n-1 disk from helper to dest using src
    towerHanoi(n-1, helper , src , dest);
}

int main(){
   
    towerHanoi(3 , "A" , "B" , "C" );
return 0;
}