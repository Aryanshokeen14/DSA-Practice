#include<iostream>
#include<vector>
using namespace std;

//this problem is also called house robber

//memoization solution - function f and rob
//tabulation soln - function solve and solveUtil
class Solution {
public:
    int f(int indx , vector<int> &nums , vector<int> &dp){
        if(indx == 0) return nums[indx];
        if(indx<0) return 0;

        if(dp[indx] != -1){
            return dp[indx];
        }

        int pick = nums[indx] + f(indx - 2 , nums , dp);
        int notpick = 0 + f(indx-1 , nums , dp);

        return dp[indx] =  max(pick , notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return f(n-1,nums , dp);
    }

    int solveUtil(int n , vector<int> &nums , vector<int> &dp){
        dp[0] = nums[0];
        for(int i=1;i<n;i++){
            int pick = nums[i];
            if(i>1){
                pick += dp[i-2];
            };
            int notpick = dp[i-1];
            dp[i] = max(pick , notpick);
        }
        return dp[n-1];
    };

    int solve(int n , vector<int> &nums){
        vector<int> dp(n,0);
        return solveUtil(n,nums,dp);
    };

    // this code below is for space optimization O(1)
    int spaceOptimization(int n, vector<int>& arr) {
        int prev = arr[0];   // Initialize the maximum sum ending at the previous element
        int prev2 = 0;       // Initialize the maximum sum ending two elements ago
        for (int i = 1; i < n; i++) {
        int pick = arr[i];  // Maximum sum if we pick the current element
        if (i > 1)
            pick += prev2;  // Add the maximum sum two elements ago
        
        int nonPick = 0 + prev;  // Maximum sum if we don't pick the current element
        
        int cur_i = max(pick, nonPick);  // Maximum sum ending at the current element
        prev2 = prev;   // Update the maximum sum two elements ago
        prev = cur_i;   // Update the maximum sum ending at the previous element
        }
    return prev;  // Return the maximum sum
    }
};

int main(){
    Solution ans;
    vector<int> nums = {1,2,3,1};

    cout<<ans.rob(nums)<<endl; // memoization soln   TC= O(N). SC=O(N)

    cout<<ans.solve(nums.size(),nums)<<endl; // tabulation soln   TC = O(N).  SC=O(N)

    cout<<ans.spaceOptimization(nums.size() , nums); // space optimization soln  TC=O(N)  SC = O(1)
return 0;
}

