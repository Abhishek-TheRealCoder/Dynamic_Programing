// Given an array arr and target sum k, check whether there exists a subsequence such that the sum of all elements in the 
// subsequence equals to k.

// Examples:

// Input: arr = [10, 1, 2, 7, 6, 1, 5], k = 8.
// Output: true
// Explanation: Subsequences like [2, 6], [1, 7] sum upto 8

// Input: arr = [2, 3, 5, 7, 9], k = 100. 
// Output: false
// Explanation: No subsequence can sum upto 100

// Constraints:
// 1 ≤ arr.length ≤ 2000
// 1 ≤ arr[i] ≤ 1000
// 1 ≤ target ≤ 2000

#include<bits/stdc++.h>
using namespace std;
// a) Recursion
bool solve(int i,int n,vector<int>& arr,int k)
{
    if(k == 0)
        return true;

    if(i >= n)
        return false;
        
    bool include = false;
    if(arr[i] <= k)
    {
        include = solve(i + 1,n,arr,k - arr[i]);
    }
    bool exclude = solve(i + 1,n,arr,k);
    
    return include || exclude;
}
bool checkSubsequenceSum(vector<int>& arr, int k) {
    int n = arr.size();
    return solve(0,n,arr,k);
}

// b) Memoization + Recursion

int dp[2001][2001];
bool solve(int i,int n,vector<int>& arr,int k)
{
    if(k == 0)
        return true;
    
    if(i >= n)
        return false;
        
    if(dp[i][k] != -1) return dp[i][k];
    
    bool include = false;
    if(arr[i] <= k)
    {
        include = solve(i + 1,n,arr,k - arr[i]);
    }
    bool exclude = solve(i + 1,n,arr,k);
    
    return dp[i][k] = include || exclude;
}
bool checkSubsequenceSum(vector<int>& arr, int k) {
    int n = arr.size();
    memset(dp,-1,sizeof(dp));
    return solve(0,n,arr,k);
}

int main()
{
    vector<int>arr = {10, 1, 2, 7, 6, 1, 5};
    int k = 8;
    cout<<checkSubsequenceSum(arr,k);
    return 0;
}