// You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

// Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction 
// fee for each transaction.

// Note:

// You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
// The transaction fee is only charged once for each stock purchase and sale.
 

// Example 1:

// Input: prices = [1,3,2,8,4,9], fee = 2
// Output: 8
// Explanation: The maximum profit can be achieved by:
// - Buying at prices[0] = 1
// - Selling at prices[3] = 8
// - Buying at prices[4] = 4
// - Selling at prices[5] = 9
// The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

// Example 2:

// Input: prices = [1,3,7,5,10,3], fee = 3
// Output: 6
 

// Constraints:

// 1 <= prices.length <= 5 * 104
// 1 <= prices[i] < 5 * 104
// 0 <= fee < 5 * 104

#include <bits/stdc++.h>
using namespace std;

int dp[50001][2];
int FEE ;
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
    int sell_stock = prices[idx] + solve(idx + 1 , n , prices, true) - FEE;
    int not_sell_stock = solve(idx + 1 , n , prices, false);

    profit = max({profit,sell_stock,not_sell_stock});
}

return dp[idx][buy] = profit;
}
int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    bool buy = true;
    FEE = fee;
    memset(dp,-1,sizeof(dp));
    return solve(0,n,prices,buy); 
}


int main(){
    vector<int>prices = {1,3,2,8,4,9};
    int fee = 2;
    cout<<maxProfit(prices,fee);
    return 0;
}