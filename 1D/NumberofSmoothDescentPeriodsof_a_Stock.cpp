// You are given an integer array prices representing the daily price history of a stock, where prices[i] is the stock price on the ith day.

// A smooth descent period of a stock consists of one or more contiguous days such that the price on each day is lower than the price on the
//  preceding day by exactly 1. The first day of the period is exempted from this rule.

// Return the number of smooth descent periods.


// Example 1:

// Input: prices = [3,2,1,4]
// Output: 7
// Explanation: There are 7 smooth descent periods:
// [3], [2], [1], [4], [3,2], [2,1], and [3,2,1]
// Note that a period with one day is a smooth descent period by the definition.

// Example 2:

// Input: prices = [8,6,7,7]
// Output: 4
// Explanation: There are 4 smooth descent periods: [8], [6], [7], and [7]
// Note that [8,6] is not a smooth descent period as 8 - 6 ≠ 1.
// Example 3:

// Input: prices = [1]
// Output: 1
// Explanation: There is 1 smooth descent period: [1]
 

// Constraints:

// 1 <= prices.length <= 105
// 1 <= prices[i] <= 105



#include <bits/stdc++.h>
using namespace std;


// a) Recursion
long long solve(int idx,int curr,int n,vector<int>&arr)
{
    if(idx >= n)
    {
        return 0;
    }

    long long ans = 0;
    if(idx == curr || arr[idx] + 1 == arr[idx-1])
    {
        ans = 1 + solve(idx + 1, curr ,n ,arr);
    }

    return ans;

}

// b) Recursion + Memoization
long long dp[100001];
long long solve(int idx,int curr,int n,vector<int>&arr)
{
    if(idx >= n)
    {
        return 0;
    }

    if(idx != curr && dp[idx] != -1) return dp[idx];

    long long ans = 0;
    if(idx == curr || arr[idx] + 1 == arr[idx-1])
    {
        ans = 1 + solve(idx + 1, curr ,n ,arr);
    }

    return dp[idx] = ans;
}

long long getDescentPeriods(vector<int>& prices) {

    int n = prices.size();
    if(n == 1) return 1;
    vector<int>dp(n,1);
    for(int i = 1;i < n;i++)
    {
        if(prices[i] + 1 == prices[i-1])
        {
            dp[i] = 1 + dp[i-1];
        }
    }

    long long sum = 0;
    for(auto x : dp)
    {
        sum += x;
    }
    return sum;
}
int main()
{
    vector<int> prices = {3,2,1,4};
    cout << getDescentPeriods(prices) << endl;
    return 0;
}