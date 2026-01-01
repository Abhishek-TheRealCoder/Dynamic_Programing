// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. 
// All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, 
// adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken 
// into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight 
// without alerting the police.

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

#include<bits/stdc++.h>
using namespace std;

// a) Recursive Approach
// int solve(int i,int n,vector<int>&arr){
//     if(i >= n){
//         return 0;
//     }

//     int include = arr[i] + solve(i+2,n,arr);
//     int exclude = solve(i+1,n,arr);

//     return max(include,exclude);
// }
// TC-> O(2^n)

// b) Memoization + Recursion
int solve(int i,int n,vector<int>&arr,vector<int>&dp){
    if(i >= n){
        return 0;
    }

    if(dp[i] != -1) return dp[i];

    int include = arr[i] + solve(i+2,n,arr,dp);
    int exclude = solve(i+1,n,arr,dp);

    return dp[i] = max(include,exclude);
}
// TC-> O(2^n)

// c) Bottom-up


int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 1)return nums[0];

    vector<int>dp1(n+1,-1);
    vector<int>dp2(n+1,-1);
    int firstTaken = solve(0,n-1,nums,dp1);
    int lastTaken = solve(1,n,nums,dp2);
    return max(firstTaken,lastTaken);
}

int main(){
    vector<int>arr = {1,2,3,1};
    cout<<rob(arr);
}