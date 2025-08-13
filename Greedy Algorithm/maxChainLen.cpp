#include<iostream>
#include<vector>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int>p2){
    return p1.second<p2.second;
};

int maxChainLen(vector<pair<int,int>>pair){
    int n =pair.size();
    sort(pair.begin(),pair.end(),compare);
    int ans=1;
    int currend= pair[0].second;
    for(int i =0;i<n;i++){
        if(pair[i].first>currend){//non overlapping
            ans++;
            currend = pair[i].second;
        }
    }
    return ans;
};

int main(){
    vector<pair<int,int>> pair(5,make_pair(0,0));
    pair[0] = make_pair(5,24); 
    pair[1] = make_pair(39,60); 
    pair[2] = make_pair(5,28); 
    pair[3] = make_pair(27,40); 
    pair[4] = make_pair(50,90); 
    cout<< "max chain len : "<<maxChainLen(pair)<<endl;
}