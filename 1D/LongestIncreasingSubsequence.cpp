// Given an integer array nums, return the length of the longest strictly increasing subsequence.
// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4
// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1
 

// Constraints:

// 1 <= nums.length <= 2500
// -104 <= nums[i] <= 104

#include <bits/stdc++.h>
using namespace std;

// a) Recursion
// int solve(int i,int n,vector<int>& arr,int prevIdx){
//     if(i >= n) return 0;

//     int include = INT_MIN;
//     if(prevIdx == -1 || arr[i] > arr[prevIdx]){
//         include = 1 + solve(i+1,n,arr,i);
//     }
//     int exclude = solve(i+1,n,arr,prevIdx);
//     return max(include,exclude);
// }
// TC-> O(2^n)

// b) Memoization + Recursion
// int solve(int i,int n,vector<int>& arr,int prevIdx,vector<vector<int>>&dp){
//     if(i >= n) return 0;
//     if(prevIdx !=-1 && dp[i][prevIdx] != -1) return dp[i][prevIdx];

//     int include = INT_MIN;
//     if(prevIdx == -1 || arr[i] > arr[prevIdx]){
//         include = 1 + solve(i+1,n,arr,i,dp);
//     }
//     int exclude = solve(i+1,n,arr,prevIdx,dp);
//     if(prevIdx != -1) return dp[i][prevIdx] = max(include,exclude);
//     return max(include,exclude);
// }
// TC-> O(2^n)

// c) Bottom-up
int solve(int n,vector<int>&arr){
    vector<int>dp(2501,1);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < i;j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i] , 1 + dp[j]);
            }
        }
    }
    return dp[n+1];
}
// TC-> O(n^2)



int lengthOfLIS(vector<int>& arr) {
    int n = arr.size();
    // vector<vector<int>>dp(2501,vector<int>(2501,-1));
    // return solve(0,n,arr,-1,dp);
    return solve(n,arr);
}

int main(){
    vector<int>arr = {10,9,2,5,3,7,101,18};
    cout<<lengthOfLIS(arr);
}