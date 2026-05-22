// Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the 
// array whose sum is equal to the given target.

// Examples:

// Input: arr[] = [5, 2, 3, 10, 6, 8], target = 10
// Output: 3
// Explanation: The subsets {5, 2, 3}, {2, 8}, and {10} sum up to the target 10.

// Input: arr[] = [2, 5, 1, 4, 3], target = 10
// Output: 3
// Explanation: The subsets {2, 1, 4, 3}, {5, 1, 4}, and {2, 5, 3} sum up to the target 10.

// Input: arr[] = [5, 7, 8], target = 3
// Output: 0
// Explanation: There are no subsets of the array that sum up to the target 3.
// Input: arr[] = [35, 2, 8, 22], target = 0
// Output: 1
// Explanation: The empty subset is the only subset with a sum of 0.

// Constraints:
// 1 ≤ arr.size() ≤ 103
// 0 ≤ arr[i] ≤ 103
// 0 ≤ target ≤ 103



#include<bits/stdc++.h>
using namespace std;

int solve(int i,int n,vector<int>& arr, int target)
{
    if(i >= n)
    {
        if(target == 0)
        {
            return 1;
        }
        return 0;
    }
    
    int include = 0;
    if(arr[i] <= target)
    {
        include = solve(i+1,n,arr,target - arr[i]);
    }
    
    int exclude = solve(i+1,n,arr,target);
    
    return include + exclude;
}
int perfectSum(vector<int>& arr, int target) {
    
    int n = arr.size();
    sort(arr.begin(),arr.end());
    return solve(0,n,arr,target);
}

int main()
{
    vector<int>arr = {5, 2, 3, 10, 6, 8};
    int target = 10;
    cout << perfectSum(arr,target);
    return 0;
}