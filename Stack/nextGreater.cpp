#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

void nextGreater(vector<int> arr,vector<int> ans){
    stack<int> s;
    int indx = arr.size()-1;
    ans[indx] = -1;
    s.push(arr[indx]);

    for(indx=indx-1;indx>=0;indx--){
        int curr = arr[indx];
        while(!s.empty() && curr>=s.top()){
            s.pop();
        }
        if(s.empty()){
            ans[indx] = -1;
        }else{
            ans[indx] = s.top();
        }
        s.push(curr);

    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {6,8,0,1,3};
    vector<int> ans = {0,0,0,0,0};
    nextGreater(arr,ans);
return 0 ;
}