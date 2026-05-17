// You are given an integer array coins representing coins of different denominations and an integer amount representing 
// a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up 
// by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

 

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1

// Example 2:

// Input: coins = [2], amount = 3
// Output: -1
// Example 3:


// Input: coins = [1], amount = 0
// Output: 0
 

// Constraints:

// 1 <= coins.length <= 12
// 1 <= coins[i] <= 2^31 - 1
// 0 <= amount <= 10^4



#include<bits/stdc++.h>

using namespace std;

int dp[13][10001];

// a) Recursion + Memoization
int solve(int idx,int n,vector<int>& coins, int amount)
{
    if(idx >= n)
    {
        if(amount == 0)
        {
            return 0;
        } 
        return 1e9;
    }
    if(dp[idx][amount] != -1) return dp[idx][amount];

    if(amount == 0) return 0;

    int include = 1e9;
    if(coins[idx] <= amount)
    {
        include = 1 + solve(idx,n,coins,amount - coins[idx]);
    }

    int exclude = solve(idx + 1,n,coins,amount);

    return dp[idx][amount] = min(include ,exclude);
}

// int coinChange(vector<int>& coins, int amount) {
//     int n = coins.size();
//     memset(dp,-1,sizeof(dp));
//     int res = solve(0,n,coins,amount);
//     return res == 1e9 ? -1 : res;
// }


// b) Bottom-up dp[i][amount] = minimum number of coins required to make up the amount using coins from index i to n-1
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>>dp(n+1,vector<int>(amount+1,1e9));

    // amount zero needs zero coins
    for(int i = 0;i <= n;i++)
    {
        dp[i][0] = 0;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int amt = 1; amt <= amount; amt++)
        {
            int include = 1e9;
            if(coins[i-1] <= amt)
            {
                include = 1 + dp[i][amt - coins[i-1]];
            }
            int exclude = dp[i-1][amt];
            dp[i][amt] = min(include,exclude);
        }
    }
    int res = dp[n][amount];
    return res == 1e9 ? -1 : res;
}
int main()
{
    vector<int> coins = {1,2,5};
    int amount = 11;
    cout<<coinChange(coins,amount);
    return 0;
}

