// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array
// represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

 

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

// Example 2:

// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

// Constraints:

// 1 <= nums.length <= 104
// 0 <= nums[i] <= 105

#include<bits/stdc++.h>
using namespace std;

// a) Recursion + Memoization
int dp[10001];
bool solve(int idx,vector<int>&arr,int n)
{
    if(idx >= n-1) return true;
    if(dp[idx] != -1) return dp[idx];
    
    bool ans = false;
    for(int i = 1;i <= arr[idx];i++)
    {
        if(solve(idx + i,arr,n)) return true;
    }
    
    return dp[idx] = ans;
}

bool canJump(vector<int> &arr) {
    // code here
    int n = arr.size();
    memset(dp,-1,sizeof(dp));
    return solve(0,arr,n);
}


// b) Greedy Approach
bool canJump(vector<int> &arr) {
    // code here
    
}

int main(){
    vector<int> nums = {2,3,1,1,4};
    int n = nums.size();
    bool ans = canJump(nums);
    cout<<ans;
    return 0;
}