// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only 
// constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically 
// contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight
// without alerting the police.

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

#include<bits/stdc++.h>
using namespace std;

// a) Recursive Approach
// int solve(int i,int n,vector<int>&arr){
//     if(i >= n) return 0;

//     int include = arr[i] + solve(i+2,n,arr); 
//     int exclude = solve(i+1,n,arr);
    
//     return max(include,exclude);
// }
// TC-> 2^n

// b) Memoization + Recursion
// int solve(int i,int n,vector<int>&arr,vector<int>&dp){
//     if(i >= n) return 0;
//     if(dp[i] != -1) return dp[i];

//     int include = arr[i] + solve(i+2,n,arr,dp); 
//     int exclude = solve(i+1,n,arr,dp);
    
//     return dp[i] = max(include,exclude);
// }
// TC-> O(2^n)

int solve(int n,vector<int>&arr){
    if(n == 0) return 0;
    if(n == 1) return arr[0];

    vector<int>dp(n+1,-1);
    dp[0] = 0;
    dp[1] = arr[0];
    for(int i = 2;i <= n;i++){
        dp[i] = max(dp[i-1],arr[i-1]+dp[i-2]);
    }
    return dp[n];
}
// TC-> O(n)
// SC-> O(n)

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int>dp(n+1,-1);
    // return solve(0,n,nums,dp);
    return solve(n,nums);
}
int main(){
    vector<int>arr = {1,2,3,1};
    cout<<rob(arr);
    return 0;
}