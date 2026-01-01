#include<bits/stdc++.h>
using namespace std;

int solve(int i,int j,int n,vector<vector<int>>&mat,vector<vector<int>>&dp){
    if(i < 0 | i > n - 1 || j < 0 || j > n-1) return 1e9;

    if(i == n-1) return mat[i][j];
    if(dp[i][j] != -1) return dp[i][j];

    int bottom = mat[i][j] + solve(i+1,j,n,mat,dp);
    int bottomLeft = mat[i][j] + solve(i+1,j-1,n,mat,dp);
    int bottomRight = mat[i][j] + solve(i+1,j+1,n,mat,dp);

    return dp[i][j] =  min({bottom,bottomLeft,bottomRight});
}

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int mini = INT_MAX;
    for(int i = 0;i < n;i++){
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int res = solve(0,i,n,matrix,dp);
        mini = min(res,mini);
    }
    return mini;
}
int main(){
    vector<vector<int>>matrix = {{2,1,3},{6,5,4},{7,8,9}};
    int ans = minFallingPathSum(matrix);
    cout<<ans;
}
