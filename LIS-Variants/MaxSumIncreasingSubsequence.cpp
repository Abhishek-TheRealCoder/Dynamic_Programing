// Given an array of positive integers arr[], find the maximum sum of a subsequence such that the elements of the 
// subsequence form a strictly increasing sequence.
// In other words, among all strictly increasing subsequences of the array, return the one with the largest possible sum.

// Examples:

// Input: arr[] = [1, 101, 2, 3, 100]
// Output: 106
// Explanation: The maximum sum of an increasing sequence is obtained from [1, 2, 3, 100].

// Input: arr[] = [4, 1, 2, 3]
// Output: 6
// Explanation: The maximum sum of an increasing sequence is obtained from [1, 2, 3].

// Input: arr[] = [4, 1, 2, 4]
// Output: 7
// Explanation: The maximum sum of an increasing sequence is obtained from [1, 2, 4].

// Constraints:
// 1 ≤ arr.size() ≤ 103
// 1 ≤ arr[i] ≤ 105


#include<bits/stdc++.h>
using namespace std;

int maxSumIS(vector<int>& arr) {
    int n = arr.size();
    vector<int>dp(n,0);
    for(int  i = 0;i < n;i++)
    {
        dp[i] = arr[i];
    }
    int maxi = arr[0];
    for(int i = 1;i < n;i++)
    {
        int prev = arr[i];
        for(int j = 0;j < i ;j++)
        {
            if(arr[i] > arr[j] && dp[j] + prev > dp[i])
            {
                dp[i] = prev + dp[j];
                maxi = max(dp[i],maxi);
            }
        }
    }
    return maxi;
}

int main()
{
    vector<int>arr = {1, 101, 2, 3, 100};
    cout<<maxSumIS(arr);
    return 0;
}