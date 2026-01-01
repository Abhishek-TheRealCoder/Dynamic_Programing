#include<bits/stdc++.h>
using namespace std;

// bool isPallin(int i,int j,string s,int n){
//     while(i <= j){
//         if(s[i] != s[j]) return false;
//         i++;
//         j--;
//     }
//     return true;
// }
// // 1) Normal Brute Force 
// int countSubstrings(string s) {
//     int n = s.size();
//     int cnt = 0;
//     for(int i = 0;i < n;i++){
//         for(int j = i;j < n;j++){
//             if(isPallin(i,j,s,n)){
//                 cnt++;
//             }
//         }
//     }
//     return cnt;
// }
// TC-> O(n^3)

// 2) Recursion + Memo
// bool isPallin(int i,int j,string s,vector<vector<int>>&dp){
//     if(i >= j) return dp[i][j] = 1;
//     if(dp[i][j] != -1) return dp[i][j];
//     if(s[i] != s[j]) return dp[i][j] = 0;

//     bool ans = isPallin(i+1,j-1,s,dp);
//     return dp[i][j] = ans;
// }
// int countSubstrings(string s) {
//     int n = s.size();
//     int cnt = 0;
//     vector<vector<int>>dp(n,vector<int>(n,-1));
//     for(int i = 0;i < n;i++){
//         for(int j = i;j < n;j++){
//             if(isPallin(i,j,s,dp)){
//                 cnt++;
//             }
//         }
//     }
//     return cnt;
// }
// TC-> O(n^2)

// 3) Bottom-up
int countSubstrings(string s) {
    int n = s.size();
    int cnt = 0;
    vector<vector<int>>dp(n,vector<int>(n,0));
    // on basis of length
    for(int len = 1; len <= n;len++){
        for(int i = 0;len + i - 1 < n;i++){
            int j = len + i - 1;
            // one len string
            if(i == j){
                dp[i][j] = 1;
            }
            // two len string
            else if(len == 2){
                if(s[i] == s[j]) dp[i][j] = 1;
            }
            // len more than 2
            else{
                if(s[i] == s[j] && dp[i+1][j-1]) dp[i][j] = 1;
            }

            if(dp[i][j] == 1) cnt++;
        }
    }

    return cnt;
}

int main(){
    string s = "aaa";
    cout<<countSubstrings(s);
    return 0;
}