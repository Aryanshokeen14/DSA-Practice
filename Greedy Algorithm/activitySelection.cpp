#include<iostream>
#include<vector>
using namespace std;

int maxActivites(vector<int> start , vector<int> end){
    //sort end time 
    //already sorted

    //select A0
    cout<<"selecting activity A0"<<endl;
    int count =1;
    int currtime = end[0];
    for(int i =1; i<start.size();i++){//non overlapping
        if(start[i]>=currtime){
            count++;
            currtime = end[i];
            cout<<"selecting activity A"<<i<<endl;
        }
    }
    return count;
};

int main(){
    vector<int> start = {1,3,0,5,8,5};
    vector<int> end = {2,4,6,7,9,9};
    cout<<maxActivites(start,end);
return 0;
}