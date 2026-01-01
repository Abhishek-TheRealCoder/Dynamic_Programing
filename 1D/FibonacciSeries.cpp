// Fibonacci Series-> 0,1,1,2,3,5,8,13....................
// Solving using  methods->
// a) Recursion
// b) Memoization (Top Down)
// c) Bottom-up (Tabulation)
// d) Space optimization
// F(n) = F(n-1) + F(n-2)  
// F(5) = 5  // fibonacci of n=5 is equal to 5
            //              5
            //            /   \
            //           4      3
            //         / \     /  \
            //        3   2   2    1
            //       / \     / \
            //      2   1   1   0
            //     / \
            //    1   0
#include<bits/stdc++.h>
using namespace std;

// a) Recursive Approach ->
// int solve(int n){
//     if(n == 0) return 0;
//     if(n == 1) return 1;

//     return solve(n-1) + solve(n-2);
// }
// Problem here is we have overlapping subinterval as u can see we are calculation F(3) two times which causes unecessary
// computaion. Here n is small so it does not take time but when n is larger number it shows TLE(time limit exceed) 
// TC->
// Suppose time to calculate F(n) is T(n), F(n-1) is T(n-1), F(n-2) is T(n-2);
// SO time is =>
// T(n) = T(n-1) + T(n-2); 
// T(n) = 2T(n-1) + k        ->eq(1) // k is constant changed T(n-2) to T(n-1) so it becomes 2T(n-1)
// // now to remove T(N-1) we add 2T(n-1) to left side
// T(n-1) = 2T(n-2) + k      ->eq(2)
// 2T(n-1) = 2^2T(n-2) + k   ->eq(3)
// 4T(n-2) = 2^3T(n-3) + k   ->eq(4)


// T(n) = k + 2k + 4k + 8k + 16k ..............
// GP=> a(r^n - 1)/(r-1);
// so therefore -> k(2^n - 1)
// TC-> O(2^n) which is very high 


// Adding all equations ->
// T(n) + T(n-1) + 2T(n-1) + T(n-2) = 2T(n-1) + k + 2T(n-2) + k + 2^2T(n-3) + k +  2^3T(n-4) + k

// b) Recursion + Memoization Approach (Better than Recursion)
// int solve(int n , vector<int>&dp){
//     if(n == 0) return 0;
//     if(n == 1) return 1;

//     if(dp[n] != -1) return dp[n]; // here we are tackling the overlapping subproblem by storing the computational value and return it when again needed

//     return dp[n] = solve(n-1,dp) + solve(n-2,dp); 
// }
// TC-> O(2^n)


// c) Bottom Up -> (Better than other 2 Approaches)
// state definition -> dp[i] is the fibonacci computational value of ith number if i = 3 then dp[3] is nothing but f(3)
// int solve(int n){
//     vector<int>dp(n+1,-1);
//     dp[0] = 0;
//     dp[1] = 1;

//     for(int i = 2;i <= n; i++){
//         dp[i] = dp[i-1] + dp[i-2] ;
//     }

//     return dp[n];

// }
// TC-> O(n)
// SC-> O(n)

// d) Space Optimization (Best Approach)
int solve(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;

    int a = 0;
    int b = 1;

    for(int i = 2;i <= n; i++){
        int c = a + b;
        
    }
}
// TC-> O(n)
// SC-> O(1)

int main(){ 
    int n = 7;            //       0   1   2   3   4   5        
    // vector<int>dp(n+1,-1); // ------------------------
                      //         | 0 | 1 | 1 | 2 | 3 | 5 |  
                          //     ------------------------
    cout<<solve(n);
}