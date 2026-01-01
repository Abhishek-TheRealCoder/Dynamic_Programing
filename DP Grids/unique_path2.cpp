// You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). 
// The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at 
// any point in time.

// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any
// square that is an obstacle.
// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
// The testcases are generated so that the answer will be less than or equal to 2 * 109

#include<bits/stdc++.h>
using namespace std;

int solve(int i,int j,int m,int n,vector<vector<int>>&dp,vector<vector<int>>&grid){
    if(i == m-1 && j == n-1) return 1;
    if(i < 0 || i > m - 1 || j < 0 || j > n - 1) return 0;
    if(grid[i][j] == 1) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int bottom =  solve( i + 1 , j , m , n , dp , grid);
    int right =  solve( i , j + 1 , m , n , dp , grid);

    return bottom + right;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>>dp(m,vector<int>(n,-1));
    return solve(0,0,m,n,dp,obstacleGrid);
}

int main(){
    vector<vector<int>>obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    int paths = uniquePathsWithObstacles(obstacleGrid);
    cout<<paths;
    return 0;
}