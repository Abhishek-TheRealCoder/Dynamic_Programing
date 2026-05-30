// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) 
// with the following restrictions:

// After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// Example 1:

// Input: prices = [1,2,3,0,2]
// Output: 3
// Explanation: transactions = [buy, sell, cooldown, buy, sell]

// Example 2:

// Input: prices = [1]
// Output: 0
 

// Constraints:

// 1 <= prices.length <= 5000
// 0 <= prices[i] <= 1000

#include<bits/stdc++.h>
using namespace std;

// A) Recursion
int solve(int idx,int n,vector<int>& prices,bool buy)
{
    if(idx >= n) return 0;

    int profit = 0;
    if(buy)
    {
        int buy_stock = solve(idx + 1 , n , prices,false) - prices[idx];
        int not_buy_stock = solve(idx + 1 , n , prices,true);

        profit = max({profit,buy_stock,not_buy_stock});
    }
    else
    {
        int sell_stock = prices[idx] + solve(idx + 2 , n , prices,true);
        int not_sell_stock = solve(idx + 1 , n , prices,false);

        profit = max({profit,sell_stock,not_sell_stock});
    }

    return profit;
}


int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int buy = true;
    return solve(0,n,prices,buy);
}

// b) Memoization + Recursion

int dp[5001][2];
int solve(int idx,int n,vector<int>& prices,bool buy)
{
    if(idx >= n) return 0;
    if(dp[idx][buy] != -1) return dp[idx][buy];

    int profit = 0;
    if(buy)
    {
        int buy_stock = solve(idx + 1 , n , prices, false) - prices[idx];
        int not_buy_stock = solve(idx + 1 , n , prices, true);

        profit = max({profit,buy_stock,not_buy_stock});
    }
    else
    {
        int sell_stock = prices[idx] + solve(idx + 2 , n , prices, true);
        int not_sell_stock = solve(idx + 1 , n , prices, false);

        profit = max({profit,sell_stock,not_sell_stock});
    }

    return dp[idx][buy] = profit;
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    bool buy = true;
    memset(dp,-1,sizeof(dp));
    return solve(0,n,prices,buy);
}

int main()
{
    vector<int>prices = {1,2,3,0,2};
    cout << maxProfit(prices);
    return 0;
}