#include<iostream>
using namespace std;

void allOccurences(int arr[] , int key , int i , int size){
    // base case
    if(i== size){
        return;
    }
    if(arr[i]==key){
        cout<<i<<" ";
    }
    return allOccurences(arr,key,i+1 ,size);
}

int main(){
    int arr[] = {3,2,4,5,6,2,4,7,2,2,4,4};
    int key = 4;
    int size = sizeof(arr)/sizeof(arr[0]);
    allOccurences(arr , key , 0 , size);
}

