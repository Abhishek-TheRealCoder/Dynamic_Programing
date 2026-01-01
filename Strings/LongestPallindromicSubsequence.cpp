#include<bits/stdc++.h>
using namespace std;

// 1) Recursive
// int solve(int i,int j,string s,int n){
//     if(i == j) return 1;
//     if(i > j) return 0;
    
//     int ans = 0;
//     if(s[i] == s[j]){
//         return 2 + solve(i+1,j-1,s,n);
//     }else{
//         ans = max(solve(i+1,j,s,n),solve(i,j-1,s,n));
//     }
//     return ans;

// }

// int longestPalindromeSubseq(string s) {
//     int n = s.size();
//     return solve(0,n-1,s,n);
// }
// TC->O(2^n)


// 2) Recursion + memo
// int solve(int i,int j,string s,int n,vector<vector<int>>&dp){
//     if(i == j) return 1;
//     if(dp[i][j] != -1)return dp[i][j];
//     if(i > j) return 0;
//     int ans = 0;

//     if(s[i] == s[j]){
//         return 2 + solve(i+1,j-1,s,n,dp);
//     }else{
//         ans =  max(solve(i+1,j,s,n,dp),solve(i,j-1,s,n,dp));
//     }
//     return dp[i][j] = ans;
// }
// int longestPalindromeSubseq(string s) {
//     int n = s.size();
//     if(n==1)return 1;
//     vector<vector<int>>dp(n,vector<int>(n,-1));
//     return solve(0,n-1,s,n,dp);
// }


// 3) Bottom - up
// dp[i][j] = True if(s[i] == s[j]) 
int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>>dp(n,vector<int>(n));
    for(int len = 1;len <= n;len++){
        for(int i = 0;i + len - 1 < n;i++){
            int j = len + i - 1;
            if(i == j) dp[i][j] = 1;
            else if(s[i] == s[j]){
                dp[i][j] = 2 + dp[i+1][j-1];
            }else{
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }
    return dp[0][n-1];
}

// 4) LCS Approach idea -> reverse the string then calc Longest Common Sequence

int main(){
    string s = "bbbab";
    cout<<longestPalindromeSubseq(s);
    return 0;
}