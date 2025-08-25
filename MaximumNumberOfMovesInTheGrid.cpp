// You are given a 0-indexed m x n matrix grid consisting of positive integers.
// You can start at any cell in the first column of the matrix, and traverse 
// the grid in the following way:
// From a cell (row, col), you can move to any of the cells: (row - 1, col + 1), 
// (row, col + 1) and (row + 1, col + 1) such that the value of the cell you move to, 
// should be strictly bigger than the value of the current cell.
// Return the maximum number of moves that you can perform.

// Example 1:
// Input: grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
// Output: 3
// Explanation: We can start at the cell (0, 0) and make the following moves:
// - (0, 0) -> (0, 1).
// - (0, 1) -> (1, 2).
// - (1, 2) -> (2, 3).
// It can be shown that it is the maximum number of moves that can be made.

// Example 2:
// Input: grid = [[3,2,4],[2,1,9],[1,1,7]]
// Output: 0
// Explanation: Starting from any cell in the first column we cannot perform any moves.

#include<bits/stdc++.h>
using namespace std;

bool isPoss(int i,int j,int n, int m,vector<vector<int>>& grid,int old_i,int old_j){
    if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] > grid[old_i][old_j]){
        return true;
    }
    return false;
}

int solve(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<int>>&dp){

    if(i < 0 || i >= n || j < 0 || j >= m) return 0;
    if(dp[i][j]!= -1) return dp[i][j];

    // right
    int right = 0;
    if(isPoss(i ,j + 1,n,m,grid,i,j)){
        right = 1 + solve(i,j+1,n,m,grid,dp);
    }

    // top right    
    int top_Right = 0;
    if(isPoss(i - 1,j + 1,n,m,grid,i,j)){
        top_Right = 1 + solve(i - 1,j + 1,n,m,grid,dp);
    }
    
    // bottom_right
    int bottom_Right = 0;
    if(isPoss(i + 1,j + 1,n,m,grid,i,j)){
        bottom_Right = 1 + solve(i + 1,j + 1,n,m,grid,dp);
    }

    return dp[i][j] = max({right,top_Right,bottom_Right});

}

int maxMoves(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    int maxi = 0;
    for(int row = 0;row < n;row++){
        maxi = max(maxi,solve(row,0,n,m,grid,dp));
    }
    return maxi;
}

int main(){
    vector<vector<int>>arr={
        {2,4,3,5},
        {5,4,9,3},
        {3,4,2,11},
        {10,9,13,15}
    };

    int ans = maxMoves(arr);
    cout<<ans;
    return 0;
}