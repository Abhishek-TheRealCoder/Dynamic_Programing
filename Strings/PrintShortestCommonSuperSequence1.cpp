#include<bits/stdc++.h>
using namespace std;

string shortestCommonSupersequence(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    // Longest Common Subsequence
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

    int i = n;
    int j = m;
    string ans;
    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            ans += s1[i-1];
            i--;
            j--;
        }else{
            if(dp[i][j-1] > dp[i-1][j]){
                ans += s2[j-1];
                j--;
            }else{
                ans += s1[i-1];
                i--;
            }
        }
    }

    while(i > 0){
        ans += s1[i-1];
        i--;
    }

    while(j > 0){
        ans += s2[j-1];
        j--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string s1 = "abac";
    string s2 = "cab";
    cout<<shortestCommonSupersequence(s1,s2);
    return 0;
}