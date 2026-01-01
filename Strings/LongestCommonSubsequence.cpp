#include<bits/stdc++.h>
using namespace std;;

// a) Recursive 
// int solve(int i,int j,int m,int n,string s1,string s2){
//     if(i >= m || j >= n)return 0;
    
//     int ans = 0;
//     if(s1[i] == s2[j]){
//         ans = 1 + solve(i+1,j+1,m,n,s1,s2);
//     }else{
//         ans = max(solve(i+1,j,m,n,s1,s2),solve(i,j+1,m,n,s1,s2));
//     }
//     return ans;
// }
// TC-> O(2^m + 2^n) i.e O(2^m+n)

// b) Memoization
// int solve(int i,int j,int m,int n,string s1,string s2,vector<vector<int>>&dp){
//     if(i >= m || j >= n)return 0;
//     if(dp[i][j] != -1) return dp[i][j];

//     int ans = 0;
//     if(s1[i] == s2[j]){
//         ans = 1 + solve(i+1,j+1,m,n,s1,s2,dp);
//     }else{
//         ans = max(solve(i+1,j,m,n,s1,s2,dp),solve(i,j+1,m,n,s1,s2,dp));
//     }
//     return dp[i][j] = ans;
    
// }
// TC-> O(m+1 * n+1) i.e O(m*n)

// c) Bottom-up
// State Definition->
// dp[i][j] = Longest Common Subsequence for string s1 of length i and string s2 of length j
int solve(int m,int n,string s1, string s2){
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));

    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n ;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
            }
        }
    }
    return dp[m][n];
}

int longestCommonSubsequence(string& s1,string& s2){
    int m = s1.size();
    int n = s2.size();
    // return solve(0,0,m,n,s1,s2);
    // vector<vector<int>>dp(1001,vector<int>(1001,-1));
    // return solve(0,0,m,n,s1,s2,dp);
    return solve(m,n,s1,s2);
}

int main(){
    string s1 = "abcde";
    string s2 = "ace";
    int ans = longestCommonSubsequence(s1,s2);
    cout<<ans;
}