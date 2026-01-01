#include<bits/stdc++.h>
using namespace std;

// int solve(int i,int j,int m,int n,string& s1,string& s2,vector<vector<int>>&dp){
//     if(i >= m || j >= n) return 0;

//     if(dp[i][j] != -1) return dp[i][j];
//     int ans = 0;
//     if(s1[i] == s2[j]) return 1 + solve(i+1,j+1,m,n,s1,s2,dp);
//     else ans = max(solve(i+1,j,m,n,s1,s2,dp),solve(i,j+1,m,n,s1,s2,dp));

//     return dp[i][j] = ans;
// }

int solve(int i,int j,int m,int n,string s1,string s2, vector<vector<int>>&dp){
    if(i >= m) return n - j;
    if(j >= n) return m - i;

    if(dp[i][j] != -1) return dp[i][j];
    int ans = 0;
    if(s1[i] == s2[j]){
        return 1 + solve(i+1,j+1,m,n,s1,s2,dp);
    }else{
        ans = 1 + min(solve(i+1,j,m,n,s1,s2,dp),solve(i,j+1,m,n,s1,s2,dp));
    }
    return dp[i][j] = ans;
}
int shortestCommonSupersequence(string &s1, string &s2) {
    // 1st method -> find lcs then subtract it with sum of length s1 + s2
    int m = s1.size();
    int n = s2.size();
    // vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    // int lcs = solve(0,0,m,n,s1,s2,dp);
    // return n + m - lcs;

    //  2nd method  ->if(s1[i] == s2[j]) then 1 + solve(i+1,j+1); else take min(1 + solve(i+1,j),1 + solve(i,j+1))
    return solve(0,0,m,n,s1,s2);

}

int main(){
    string s1 = "efgh";
    string s2 = "jghi";
    int shortest = shortestCommonSupersequence(s1,s2);
    cout<<shortest;
    return 0;
}