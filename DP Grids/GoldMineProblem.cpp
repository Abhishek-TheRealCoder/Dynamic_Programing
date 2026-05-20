// Given a gold mine called mat[][]. Each field in this mine contains a positive integer which is the amount of gold in tons. 
// Initially, the miner can start from any row in the first column. From a given cell, the miner can move -

// to the cell diagonally up towards the right
// to the right
// to the cell diagonally down towards the right
// Find out the maximum amount of gold that he can collect until he can no longer move.

// Examples:

// Input: mat[][] = [[1, 3, 3], [2, 1, 4], [0, 6, 4]]
// Output: 12
// Explaination: The path is (1, 0) -> (2, 1) -> (2, 2). Total gold collected is 2 + 6 + 4 = 12.

// Input: mat[][] = [[1, 3, 1, 5], [2, 2, 4, 1], [5, 0, 2, 3], [0, 6, 1, 2]]
// Output: 16
// Explaination: The path is (2, 0) -> (3, 1) -> (2, 2) -> (2, 3) or (2, 0) -> (1, 1) -> (1, 2) -> (0, 3). 
// Total gold collected is (5 + 6 + 2 + 3) or (5 + 2 + 4 + 5) = 16.

// Input: mat[][] = [[1, 3, 3], [2, 1, 4], [0, 7, 5]]
// Output: 14
// Explaination: The path is (1,0) -> (2,1) -> (2,2). Total gold collected is 2 + 7 + 5 = 14.
// Constraints:
// 1 ≤ mat.size(), mat[0].size() ≤ 500
// 0 ≤ mat[i][j] ≤ 100

#include<bits/stdc++.h>
using namespace std;

// a)Recursive Approach
// int dp[501][501];
// int solve(int i,int j,int n,int m,vector<vector<int>>& mat)
// {
//     if(i >= n || j >= m || i < 0)
//     {
//         return 0;
//     }
    
//     if(j == m - 1)
//     {
//         return mat[i][j];
//     }
        
//     int right        = mat[i][j] + solve(i , j + 1, n , m , mat);
//     int right_bottom = mat[i][j] + solve(i + 1,j + 1, n , m ,mat);
//     int right_up     = mat[i][j] + solve(i - 1,j + 1, n , m ,mat);
    
//     return max({right,right_bottom,right_up});
// }

// // b) Recursion + Memoization
// int solve(int i,int j,int n,int m,vector<vector<int>>& mat)
// {
//     if(i >= n || j >= m || i < 0)
//     {
//         return 0;
//     }
    
//     if(j == m - 1)
//     {
//         return mat[i][j];
//     }
    
//     if(dp[i][j] != -1)return dp[i][j];
    
//     int right        = mat[i][j] + solve(i , j + 1, n , m , mat);
//     int right_bottom = mat[i][j] + solve(i + 1,j + 1, n , m ,mat);
//     int right_up     = mat[i][j] + solve(i - 1,j + 1, n , m ,mat);
    
//     return dp[i][j] = max({right,right_bottom,right_up});
// }
// int maxGold(vector<vector<int>>& mat) 
// {
//     int n = mat.size();
//     int m = mat[0].size();
//     int ans = 0;
//     for(int i = 0;i < n;i++)
//     {
//         ans = max(ans,solve(i,0,n,m,mat));
//     }
//     return ans;
// }

// c) Bottom-up
int maxGold(vector<vector<int>>& mat) 
{
    int n = mat.size();
    int m = mat[0].size();
    int maxi = 0;
    vector<vector<int>>dp(n,vector<int>(m,0));
        
    for(int j = 0;j < m;j++)
    {
        for(int i = 0; i < n;i++)
        {
            if(j == 0)
            {
                dp[i][j] = mat[i][j];
            }
            else
            {   
                int left = dp[i][j-1];
                
                int left_top = 0;
                if(i > 0)left_top = dp[i-1][j-1];
    
                int left_bottom = 0;
                if(i < n-1)
                    left_bottom = dp[i+1][j-1];
                
                dp[i][j] = mat[i][j] + max({left,left_bottom,left_top});
                }
        }
    }
    // int maxi = 0; 
    for(int i = 0; i < n;i++)
    {
        maxi = max(maxi,dp[i][m-1]);
    }
    return maxi;
}

int main()
{
    vector<vector<int>> mat = {{1, 3, 3}, {2, 1, 4}, {0, 6, 4}};
    int n = mat.size();
    int m = mat[0].size();
    int ans = maxGold(mat);
    cout << ans << endl;
}