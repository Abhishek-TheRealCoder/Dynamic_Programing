// Given an array of non-negative integers arr, you are initially positioned at start index of the array. 
// When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach any index with value 0.


// Notice that you can not jump outside of the array at any time.

 

// Example 1:

// Input: arr = [4,2,3,0,3,1,2], start = 5
// Output: true
// Explanation: 
// All possible ways to reach at index 3 with value 0 are: 
// index 5 -> index 4 -> index 1 -> index 3 
// index 5 -> index 6 -> index 4 -> index 1 -> index 3 

// Example 2:

// Input: arr = [4,2,3,0,3,1,2], start = 0
// Output: true 
// Explanation: 
// One possible way to reach at index 3 with value 0 is: 
// index 0 -> index 4 -> index 1 -> index 3

// Example 3:

// Input: arr = [3,0,2,1,2], start = 2
// Output: false
// Explanation: There is no way to reach at index 1 with value 0.
 

// Constraints:

// 1 <= arr.length <= 5 * 104
// 0 <= arr[i] < arr.length

#include<bits/stdc++.h>
using namespace std;

// a) Recursion 
bool solve(vector<int>& arr, int idx,int n,vector<int>&visited)
{
    if(idx < 0 || idx >= n || visited[idx])
        return false;

    if(arr[idx] == 0) return true;        
    
    visited[idx] = 1;

    bool incr = solve(arr,idx + arr[idx],n,visited);
    
    bool decr = solve(arr,idx - arr[idx],n,visited);

    return incr || decr;
}

// b) Recursion + Memoization
int dp[50001];
bool solve(vector<int>& arr, int idx,int n,vector<int>&visited)
{
    if(idx < 0 || idx >= n || visited[idx])
        return false;

    if(arr[idx] == 0) return true; 
    if(dp[idx] != -1) return dp[idx];     
    
    visited[idx] = 1;

    bool incr = solve(arr,idx + arr[idx],n,visited);
    
    bool decr = solve(arr,idx - arr[idx],n,visited);

    return dp[idx] = incr || decr;
}

bool canReach(vector<int>& arr, int start) {
    int n = arr.size();
    vector<int>visited(n,0);
    memset(dp,-1,sizeof(dp));
    return solve(arr,start,n,visited);   
}

int main(){
    vector<int> arr = {4,2,3,0,3,1,2};
    int start = 5;
    bool ans = canJump(arr);
    cout << ans << endl;
    return 0;
}