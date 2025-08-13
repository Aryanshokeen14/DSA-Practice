#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int getMinChange(vector<int> coins , int v , queue<int>& requiredCoins){
    int ans =0;
    int n = coins.size();
    for(int i = n-1 ;i>=0;i-- && v>0){
        if(v>=coins[i]){
            ans += v / coins[i]; //this tells no. of coins or notes required of that particular value
            requiredCoins.push(coins[i]);
            v = v % coins[i];
        }
    }
    return ans;
};

int main(){
    vector<int> coins = {1,2,5,10,20,50,100,500,2000};
    int v =590;
    queue<int> requiredCoins ;
    cout<<"min no. of coins or notes required is : "<<getMinChange(coins,v ,requiredCoins)<<endl;
    cout<<"required coins or notes are : ";
    while(!requiredCoins.empty()){
        cout<<requiredCoins.front()<<" ";
        requiredCoins.pop();
    }cout<<endl;

}