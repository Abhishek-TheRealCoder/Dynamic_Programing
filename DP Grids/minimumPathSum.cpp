// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum 
// of all numbers along its path.

// Note: You can only move either down or right at any point in time.

#include<bits/stdc++.h>
using namespace std;


// DP ->

int solve(int i,int j,int m,int n,vector<vector<int>>& grid, vector<vector<int>>&dp){
    if(i == m-1 && j == n-1) return grid[i][j];
    if(i > m-1 || j > n-1) return INT_MAX;
    if(dp[i][j] != -1) return dp[i][j];

    int bottom = solve(i+1,j,m,n,grid,dp);
    int right = solve(i,j+1,m,n,grid,dp);

    int ans = grid[i][j] + min(bottom,right);   
    dp[i][j] = ans;
    return dp[i][j];
}

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>>dp(m,vector<int>(n,-1));
    return solve(0,0,m,n,grid,dp);
}

int main(){
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    int mini = minPathSum(grid);
    cout<<mini;
    return 0;
}


// recursive way-> but shows TLE as there are overlapping subproblems

bool isPoss(int i,int j,int m,int n,vector<vector<int>>&grid){
    if(i >= 0 && i < m && j >= 0 && j < n) return true;
    return false;
}
void solve(int i,int j,int m,int n, vector<vector<int>>& grid,int &mini,int &sum){
    if(i == m-1 && j == n-1){
        sum += grid[i][j];
        mini = min(mini,sum);
        sum -= grid[i][j];
        return ;
    }

    sum += grid[i][j];
    int x = i + 1;
    int y = j;
    if(isPoss(x,y,m,n,grid)){
        solve(x,y,m,n,grid,mini,sum);
    }
    x = i;
    y = j+1;
    if(isPoss(x,y,m,n,grid)){
        solve(x,y,m,n,grid,mini,sum);
    }
  
    sum -= grid[i][j];  
    return ;  
}
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int mini = INT_MAX;
    int sum = 0;
    solve(0,0,m,n,grid,mini,sum);
    return mini == INT_MAX ? 0 : mini;
}
