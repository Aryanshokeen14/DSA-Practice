#include<iostream>
#include<vector>
using namespace std;

bool compare(pair<double,int>p1 , pair<double,int>p2){
    return p1.first > p2.first; //descending based on ratio   
}

int fractionalKnapsack(vector<int> val,vector<int>wt,int W){ //O(nlogn)
    int n =val.size();
    vector<pair<double,int>> ratio(n,make_pair(0.0,0)); //pair(ratio,idx)->(double,int)
    for(int i =0;i<n;i++){
        double r=val[i]/(double)wt[i];
        ratio[i]=make_pair(r,i);
    };
    sort(ratio.begin(),ratio.end(),compare);
    int ans=0;
    for(int i=0;i<n;i++){
        int indx = ratio[i].second;
        if(wt[indx] <= W){
            ans+=val[indx];
            W -= wt[indx];
        }else{
            ans+=ratio[i].first*W;
            W=0;
            break;
        }
    }
    cout<<"max value = "<< ans<<endl;
    return ans;
}


int main(){
    vector<int> val = {60,100,120};
    vector<int> wt = {10,20,30};
    int w =50;
    // fractionalKnapsack(val,wt,w);
    
    vector<int> A = {60,130,120};
    vector<int> B = {10,20,30};
    sort(A.begin() , A.end());
    sort(B.begin() , B.end());
    int absDiff = 0;
    for(int i =0;i<A.size();i++){
        absDiff += abs(A[i]-B[i]);
    }
    cout<<"MIN abs diff = "<<absDiff<<endl;

return 0;
}