// Given two strings s and t, return the number of distinct subsequences of s which equals t.
// The test cases are generated so that the answer fits on a 32-bit signed integer.

// Example 1:

// Input: s = "rabbbit", t = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from s.
// rabbbit
// rabbbit
// rabbbit

// Example 2:

// Input: s = "babgbag", t = "bag"
// Output: 5
// Explanation:
// As shown below, there are 5 ways you can generate "bag" from s.
// babgbag
// babgbag
// babgbag
// babgbag
// babgbag
 

// Constraints:

// 1 <= s.length, t.length <= 1000
// s and t consist of English letters.

#include<bits/stdc++.h>
using namespace std;

// a) Recursion
// int solve(int i , int j , int n , int m , string s, string t)
// {
//     if(j == m) return 1;
//     if(i >= n) return 0;

//     int include = 0;
//     if(s[i] == t[j])
//     {  
//         include = solve(i + 1,j + 1, n , m , s , t);
//     }

//     int exclude = solve(i + 1, j , n , m , s , t);

//     return include + exclude ;
// }

// int numDistinct(string s, string t)
// {
//     int n = s.size();
//     int m = t.size();
//     if(n < m) return 0;

//     return solve(0,0,n,m,s,t);
// }
// TC-> 2^N


// b) Recursion + Memoization
// int dp[1001][1001];
// int solve(int i , int j , int n , int m , string s, string t)
// {
//     if(j == m) return 1;
//     if(i >= n) return 0;

//     if(dp[i][j] != -1) return dp[i][j];

//     int include = 0;
//     if(s[i] == t[j])
//     {  
//         include = solve(i + 1,j + 1, n , m , s , t);
//     }

//     int exclude = solve(i + 1, j , n , m , s , t);

//     return dp[i][j] = include + exclude ; 
// }

// int numDistinct(string s, string t) 
// {
//     int n = s.size();
//     int m = t.size();
//     if(n < m) return 0;
//     memset(dp , -1 , sizeof(dp));
//     return solve(0,0,n,m,s,t);
// }   
// TC-> O(n * m)


// But since tabulation method is simply copy of Memo + Recursion so now we will do Memo + Recursion from n - 1 .

// c) Same Recursion + Memoization from n - 1
// int dp[1001][1001];
// int solve(int n , int m , string s, string t)
// {
//     if(m == 0) return 1;
//     if(n == 0) return 0;

//     if(dp[n][m] != -1) return dp[n][m];

//     int include = 0;
//     if(s[n - 1] == t[m - 1])
//     {  
//         include = solve(n - 1, m - 1 , s , t);
//     }

//     int exclude = solve(n - 1, m , s , t);

//     return dp[n][m] = include + exclude ; 
// }

// int numDistinct(string s, string t) 
// {
//     int n = s.size();
//     int m = t.size();
//     if(n < m) return 0;
//     memset(dp , -1 , sizeof(dp));
//     return solve(n,m,s,t);
// } 
// TC-> O(n * m)

int numDistinct(string s, string t) 
{
    int n = s.size();
    int m = t.size();
    if(n < m) return 0;

    vector<vector<int>>dp(n + 1, vector<int>(m + 1,0));

    // base condition
    for(int i = 0;i <= n ;i++)
    {
        dp[i][0] = 1;
    }

    for(int i = 1;i <= n; i++)
    {
        for(int j = 1;j <= m; j++)
        {
            int include = 0;
            if(s[i - 1] == t[j - 1]) include = dp[i-1][j-1];
            
            int exclude = dp[i - 1][j];

            dp[i][j] = include + exclude;
        }
    }
    return dp[n][m];
}
// TC -> O(n * m)


int main()
{
    string s = "rabbbit";
    string t = "rabbit";
    cout << numDistinct(s,t);
    return 0;
}