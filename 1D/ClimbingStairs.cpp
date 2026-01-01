// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top

// Constraints:
// 1 <= n <= 45


#include<bits/stdc++.h>
using namespace std;

// a) Recursive Approach
// int climbStairs(int n){
//     if(n == 0)return 1;
//     if(n == 1)return 1;

//     return climbStairs(n-1) + climbStairs(n-2);
// }
// TC-> O(2^n)

// b) Memoization + Recursion
// int climbStairs(int n,vector<int>&dp){
//     if(n == 0) return 1;
//     if(n == 1) return 1;

//     return dp[n] = climbStairs(n-1,dp) + climbStairs(n-2,dp);
// }
// TC-> O(2^n)

// c) Bottom - up
int climbStairs(int n){
    if(n == 0) return 1;
    if(n == 1) return 1;

    vector<int>dp(n+1,-1);
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2;i <= n ;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
// TC -> O(n)
// SC -> O(n)

int main(){
    int n = 4;
    vector<int>dp(n+1,-1);   //  0   1    2    3    4 
                        //     -----------------------
                    //        | 1  | 1  | 2  | 3  | 5 |
                     //        -----------------------
    cout<< climbStairs(n);
}