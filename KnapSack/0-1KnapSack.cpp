// Given two arrays, val[] and wt[], where each element represents the value and weight of an 
// item respectively, and an integer W representing the maximum capacity of 
// the knapsack (the total weight it can hold).

// The task is to put the items into the knapsack such that the total value obtained is maximum 
// without exceeding the capacity W.

// Note: You can either include an item completely or exclude it entirely — fractional selection 
// of items is not allowed. Each item is available only once.

// Examples :
// Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1]
// Output: 3
// Explanation: Choose the last item, which weighs 1 unit and has a value of 3.


// Input: W = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6] 
// Output: 0
// Explanation: Every item has a weight exceeding the knapsack's capacity (3).

// Input: W = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 2, 3] 
// Output: 80
// Explanation: Choose the third item (value 30, weight 2) and the last item (value 50, weight 3) for a total value of 80.

#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];

// a) Recursive Approach
// int solve(int i,int W, vector<int> &val, vector<int> &wt,int n)
// {
//     if(W == 0 || i >= n) return 0;
    
//     int include = 0;
//     if(wt[i] <= W)
//     {
//         include = val[i] + solve(i+1,W - wt[i],val,wt,n);
//     }
//     int exclude = solve(i+1,W,val,wt,n);
    
//     return max(include,exclude);
// }

// b) Memoization + Recursion
int solve(int i,int W, vector<int> &val, vector<int> &wt,int n)
{
    if(W == 0 || i >= n) return 0;
    if(dp[i][W] != -1) return dp[i][W];
    
    int in = 0;
    if(wt[i] <= W)
    {
        in = val[i] + solve(i+1,W - wt[i],val,wt,n);
    }
    int excl = solve(i+1,W,val,wt,n);
    
    return dp[i][W] = max(in,excl);
}


// int knapsack(int W, vector<int> &val, vector<int> &wt) {
//     int n = val.size();
//     memset(dp,-1,sizeof(dp));
//     return solve(0,W,val,wt,n);
// }

// c) Bottom-up
int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    
}



int main()
{
    int W = 5;
    vector<int> val = {10, 40, 30, 50};
    vector<int> wt = {5, 4, 2, 3};
    cout<< knapsack(W,val,wt);
    return 0;
}