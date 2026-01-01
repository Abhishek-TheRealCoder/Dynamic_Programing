#include<bits/stdc++.h>
using namespace std;;

// c) Bottom-up
// State Definition->
// dp[i][j] = Longest Common Subsequence for string s1 of length i and string s2 of length j
string solve(int m,int n,string s1, string s2){
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
    string lcs = "";

    int i = m;
    int j = n;
    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            lcs += s1[i-1];
            i--;
            j--;
        }else{
            if(dp[i][j-1] > dp[i-1][j]){
                j--;
            }else{
                i--;
            }
        }
    }
    reverse(lcs.begin(),lcs.end());
    return lcs;
}

string longestCommonSubsequence(string& s1,string& s2){
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
    string ans = longestCommonSubsequence(s1,s2);
    cout<<ans;
}