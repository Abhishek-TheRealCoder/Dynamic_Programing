#include<bits/stdc++.h>
using namespace std;


// b) Recursion + Memo
int solve(int i,int j, int n,vector<vector<int>>& tri,vector<vector<int>>&dp)
{
    if(i == n - 1) return tri[i][j];
    if(dp[i][j] != -1) return dp[i][j];

    int bottom = tri[i][j] + solve(i+1,j,n,tri,dp);
    int bot_right = tri[i][j] + solve(i+1,j+1,n,tri,dp);

    return dp[i][j] = min(bottom,bot_right);
}

int minimumTotal(vector<vector<int>>& tri) {
    int n = tri.size();
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    return solve(0,0,n,tri,dp);
}
int main(){
    vector<vector<int>>triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    int mini = minimumTotal(triangle);
    cout<<mini;
    return 0;
}
