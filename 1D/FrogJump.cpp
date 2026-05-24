
// There is a frog on the '1st' step of an 'N' stairs long staircase. The frog wants to reach the 'Nth' stair. 
// 'HEIGHT[i]' is the height of the '(i+1)th' stair.If Frog jumps from 'ith' to 'jth' stair, the energy lost in 
// the jump is given by absolute value of ( HEIGHT[i-1] - HEIGHT[j-1] ). If the Frog is on 'ith' staircase, he can 
// jump either to '(i+1)th' stair or to '(i+2)th' stair. Your task is to find the minimum total energy used by 
// the frog to reach from '1st' stair to 'Nth' stair.

// For Example
// If the given ‘HEIGHT’ array is [10,20,30,10], the answer 20 as the frog can jump from 1st stair 
// to 2nd stair (|20-10| = 10 energy lost) and then a jump from 2nd stair to last stair (|10-20| = 10 energy lost). 
// So, the total energy lost is 20.


// 1 <= T <= 10
// 1 <= N <= 100000.
// 1 <= HEIGHTS[i] <= 1000 .

// Sample Input 1:
// 2
// 4
// 10 20 30 10
// 3
// 10 50 10
// Sample Output 1:
// 20
// 0
// Explanation of sample input 1:
// For the first test case,
// The frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost).
// Then a jump from the 2nd stair to the last stair (|10-20| = 10 energy lost).
// So, the total energy lost is 20 which is the minimum. 
// Hence, the answer is 20.

// For the second test case:
// The frog can jump from 1st stair to 3rd stair (|10-10| = 0 energy lost).
// So, the total energy lost is 0 which is the minimum. 
// Hence, the answer is 0.
// Sample Input 2:
// 2
// 8
// 7 4 4 2 6 6 3 4 
// 6
// 4 8 3 10 4 4 
// Sample Output 2:
// 7
// 2
#include<bits/stdc++.h>
using namespace std;

// a) Recursion + Memo
int solve(int curr,int n,vector<int>&arr,vector<int>&dp)
{
    if(curr == n - 1) return 0;
    if(dp[curr] != -1) return dp[curr];
    int first = abs(arr[curr] - arr[curr + 1]) + solve(curr + 1 , n , arr,dp);
    int second = INT_MAX;
    if(curr + 2 < n) second = abs(arr[curr + 2] - arr[curr]) + solve(curr + 2, n, arr,dp);
    
    return dp[curr] = min(first,second);   
    
}
int frogJump(int n, vector<int> &heights)
{   
    vector<int>dp(n+1,-1);
    return solve(0,n,heights,dp);
}

int main()
{
    vector<int>arr = {7, 4, 4, 2, 6, 6, 3, 4};
    int n = arr.size();
    cout<<frogJump(n,arr);
    return 0;
}