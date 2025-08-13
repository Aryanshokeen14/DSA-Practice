#include<iostream> 
using namespace std;

int gridWays(int r , int c, int n , int m ){
    if(r==n-1 && c==m-1){
        return 1;
    }
    if(r>=n || c>=m){
        return 0;
    }
    //for rigth turn 
    int v1 = gridWays(r,c+1,n,m);
    //for down turn 
    int v2 = gridWays(r+1,c,n,m);
    
    return v1+v2;
}

int main(){
    int n=3 ;
    int m=3;
    cout<<gridWays(0,0,n,m);
} 