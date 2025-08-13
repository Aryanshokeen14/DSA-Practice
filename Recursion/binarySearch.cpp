#include<iostream>
using namespace std;

int binarySearch(int arr[], int key , int s , int e){
    int mid = (s+e)/2;
    //base case
    if(s>e){
        return -1;
    }
    else if(arr[mid]==key){
        return mid;
    }
    else if(arr[mid]>key){
        e =  mid-1;  
        // mid = (s+e)/2;
        binarySearch(arr,key,s,e); 
    }
    else if(arr[mid]<key){
        s = mid+1;
        // mid = (s+e)/2;
        binarySearch(arr,key,s,e); 
    }
    return binarySearch(arr,key,s,e); 
}

int main(){
    int arr[7] ={1,2,3,4,5,6,7};
    int s=0 , e=6 ;
    cout<<binarySearch(arr,2,s,e);
return 0; 
}
