// You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.
// A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.
// Return the length longest chain which can be formed.
// You do not need to use up all the given intervals. You can select pairs in any order.

// Example 1:
// Input: pairs = [[1,2],[2,3],[3,4]]
// Output: 2
// Explanation: The longest chain is [1,2] -> [3,4].

// Example 2:
// Input: pairs = [[1,2],[7,8],[4,5]]
// Output: 3
// Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
 
 
#include<bits/stdc++.h>
using namespace std;

// 1st method -> Recursion
// int solve(vector<vector<int>>& pairs,int n,int curr,int prev){
//     if(curr >= n) return 0;
//     int include = 0;
//     if(prev == -1 || pairs[curr][0] > pairs[prev][1]){
//         include = 1 + solve(pairs , n , curr + 1, curr);
//     }
//     int exclude = solve(pairs, n , curr + 1, prev);

//     return max(include , exclude);
// }
// tc-> O(n^2)

// 2nd method -> Recusion + memoization
// int solve(vector<vector<int>>& pairs,int n,int curr,int prev,vector<vector<int>>&dp){
//     if(curr >= n) return 0;
//     if(prev !=- 1 && dp[curr][prev] != -1) return dp[curr][prev];
//     int include = 0;
//     if(prev == -1 || pairs[curr][0] > pairs[prev][1]){
//         include = 1 + solve(pairs , n , curr + 1, curr,dp);
//     }
//     int exclude = solve(pairs, n , curr + 1, prev,dp);

//     return max(include , exclude);
// }

// 3rd) BottomUp or Tabulation
// int solve(vector<vector<int>>&pairs,int n){
//     vector<int>dp(n,1);
//     int maxi = 1;
//     for(int i = 0;i < n;i++){
//         for(int j = i-1;j >= 0;j--){
//             if(pairs[i][0] > pairs[j][1]){
//                 dp[i] = max(dp[i], 1+dp[j]);
//                 maxi = max(dp[i],maxi);
//             }
//         }
//     }

//     return maxi;
// }
// TC->O(n^2)
// SC->O(n)

// 4th -> Greedy Approach Same logic as Activity Selection Problem/ meeting room.
int solve(vector<vector<int>>&pairs,int n){
    sort(pairs.begin(), pairs.end(),
        [](auto &a, auto &b) { return a[1] < b[1];}); //sorted based on second that is finish time so that initally we have process that finish early
    int first = pairs[0][1];
    int cnt = 1;
    for(int i = 1 ; i < n;i++){
        if(pairs[i][0] > first){
            cnt++;
            first = pairs[i][1];
        }
    }
    return cnt;
}
// tc-> O(nlogn)
// SC-> O(1)
int findLongestChain(vector<vector<int>>& pairs) {
    int n = pairs.size();
    // sort(pairs.begin(),pairs.end());
    // return solve(pairs,n,0,-1);
    // vector<vector<int>>dp(n,vector<int>(n,-1));
    // return solve(pairs,n,0,-1,dp);
    // return solve(pairs,n);

    return solve(pairs,n);
}

int main(){
    vector<vector<int>>pairs = {
        {1,2},
        {7,8},
        {4,5}
    };
    int ans = findLongestChain(pairs);
    cout<<ans;
    return 0;
}