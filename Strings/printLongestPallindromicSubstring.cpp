// Constraints:
// 1 <= s.length <= 1000
// s consist of only digits and English letters.

#include<bits/stdc++.h>
using namespace std;

// 1) Brute force
// O(n^3)
// bool isPallin(int i,int j,int n,string &s){
//     while(i <= j){
//         if(s[i] != s[j]) return false;
//         i++;
//         j--;
//     }
//     return true;
// }
// string longestPalindrome(string s) {
//     int n = s.size();
//     int maxi = 1;
//     int si = 0;
//     for(int i = 0;i < n;i++){
//         for(int j = i;j < n;j++){
//             if(isPallin(i,j,n,s)){
//                 if(maxi < j - i + 1){
//                     si = i;
//                     maxi = j - i + 1;      
//                 }
//             }
//         }
//     }
//     return s.substr(si,maxi);
// }

// // 2) Recursion 
// bool isPallin(int i,int j,int n,string &s){
//     if(i >= j) return true;
//     if(s[i] != s[j]) return false;
//     bool ans = isPallin(i+1,j-1,n,s);
//     return ans;
// }
// string longestPalindrome(string s) {
//     int n = s.size();
//     int maxi = 1;
//     int si = 0;
//     for(int i = 0;i < n;i++){
//         for(int j = i;j < n;j++){
//             if(isPallin(i,j,n,s)){
//                 if(maxi < j - i + 1){
//                     si = i;
//                     maxi = j - i + 1;      
//                 }
//             }
//         }
//     }
//     return s.substr(si,maxi);
// }

// 3) Recursion + Memo
// TC-> O(n^3)
// bool isPallin(int i,int j,int n,string &s,vector<vector<int>>&dp){
//     if(i >= j) dp[i][j] = 1;
//     if(s[i] != s[j]) dp[i][j] = 0;
//     if(dp[i][j] != -1) return dp[i][j];

//     bool ans = isPallin(i+1,j-1,n,s,dp);
//     return dp[i][j] = ans;
// }
// string longestPalindrome(string s) {
//     int n = s.size();
//     int maxi = 1;
//     int si = 0;
//     vector<vector<int>>dp(n,vector<int>(n,-1));
//     for(int i = 0;i < n;i++){
//         for(int j = i;j < n;j++){
//             if(isPallin(i,j,n,s,dp)){
//                 if(maxi < j - i + 1){
//                     si = i;
//                     maxi = j - i + 1;      
//                 }
//             }
//         }
//     }
//     return s.substr(si,maxi);
// }

// // 4) Bottom-up
// Tc-> O(n^2)
// string longestPalindrome(string s) {
//     int n = s.size();
//     int maxi = 1;
//     int si = 0;
//     vector<vector<int>>dp(n,vector<int>(n,0));
//     // on basis of length
//     for(int len = 1; len <= n;len++){
//         for(int i = 0;len + i - 1 < n;i++){
//             int j = len + i - 1;
//             // one len string
//             if(i == j){
//                 dp[i][j] = 1;
//             }
//             // two len string
//             else if(i + 1 == j){
//                 if(s[i] == s[j]) dp[i][j] = 1;
//             }
//             // len more than 2
//             else{
//                 if(s[i] == s[j] && dp[i+1][j-1]) dp[i][j] = 1;
//             }

//             if(dp[i][j] == 1){
//                 if(maxi < j - i + 1){
//                     si = i;
//                     maxi = j - i + 1;      
//                 }
//             }
//         }
//     }
//     return s.substr(si,maxi);
// }


// 5) optimal approach
// TC->O(n^2)
// SC->O(1)

string longestPalindrome(string s) {
    int n = s.size();
    int maxi = 1;
    int si = 0;
    for(int i = 1;i < n; i++){
        //odd
        int left = i-1;
        int right = i+1;
        while(left >= 0 && right < n && s[left] == s[right]){
            if(maxi < right - left + 1){
                maxi = right - left + 1;
                si = left;
            }
            left--;
            right++;
        }
    }

    for(int i = 1;i < n; i++){
        //even
        int left = i-1;
        int right = i;
        while(left >= 0 && right < n && s[left] == s[right]){
            if(maxi < right - left + 1){
                maxi = right - left + 1;
                si = left;
            }
            left--;
            right++;
        }
    }
    return s.substr(si,maxi);
}

int main(){
    string s = "babad";
    cout<<longestPalindrome(s);
    return 0;
}