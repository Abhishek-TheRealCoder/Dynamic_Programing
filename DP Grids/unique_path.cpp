// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
// The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any 
// point in time.

// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.


#include<bits/stdc++.h>
using namespace std;

int solve(int i,int j,int m,int n){
    if(i == m-1 && j == n-1) return 1;
    if(i < 0 || i > m - 1 || j < 0 || j > n - 1) return 0;

    int bottom =  solve( i + 1 , j , m , n );
    int right =  solve( i , j + 1 , m , n);

    return bottom + right;
}

int uniquePaths(int m, int n) {
    vector<vector<int>>dp(m,vector<int>(n,-1));
    return solve(0,0,m,n);
}

int main(){
    int m = 3;
    int n = 7;
    int paths = uniquePaths(m,n);
    cout<<paths;
    return 0;
}