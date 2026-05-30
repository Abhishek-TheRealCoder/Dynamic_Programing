// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. 
// However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.

// Find and return the maximum profit you can achieve.

 

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
// Total profit is 4 + 3 = 7.

// Example 2:

// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Total profit is 4.

// Example 3:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 

// Constraints:

// 1 <= prices.length <= 3 * 104
// 0 <= prices[i] <= 104


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
        int sell_stock = prices[idx] + solve(idx + 1 , n , prices,true);
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

int dp[30001][2];
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
        int sell_stock = prices[idx] + solve(idx + 1 , n , prices, true);
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
    vector<int> prices = {7,1,5,3,6,4};
    int profit = 0;
    cout<<maxProfit(prices)<<endl;
    return 0;
}