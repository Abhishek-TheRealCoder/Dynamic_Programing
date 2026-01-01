#include<bits/stdc++.h>
using namespace std;

string shortestCommonSupersequence(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1));

    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= m;j++){
            if(i == 0 || j == 0){
                dp[i][j] = i + j;
            }
            else if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1 + min(dp[i][j-1],dp[i-1][j]);
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
                ans += s1[i-1];
                i--;
            }else{
                ans += s2[j-1];
                j--;
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