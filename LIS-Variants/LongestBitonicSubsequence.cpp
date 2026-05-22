// Given an array of positive integers. Find the maximum length of Bitonic subsequence. 
// A subsequence of array is called Bitonic if it is first strictly increasing, then strictly decreasing. 
// Return the maximum length of bitonic subsequence.
 
// Note : A strictly increasing or a strictly decreasing sequence should not be considered as a bitonic sequence

// Examples :

// Input: n = 5, nums[] = [1, 2, 5, 3, 2]
// Output: 5
// Explanation: The sequence [1, 2, 5] is increasing and the sequence [3, 2] is decreasing so merging both we will get length 5.

// Input: n = 8, nums[] = [1, 11, 2, 10, 4, 5, 2, 1]
// Output: 6
// Explanation: The bitonic sequence [1, 2, 10, 4, 2, 1] has length 6.

// Input: n = 3, nums[] = [10, 20, 30]
// Output: 0
// Explanation: The decreasing or increasing part cannot be empty.

// Input: n = 3, nums[] = [10, 10, 10]
// Output: 0
// Explanation: No strictly increasing or decreasing sequence exists.

// Constraints:
// 1 ≤ length of array ≤ 103
// 1 ≤ arr[i] ≤ 104


#include<bits/stdc++.h>
using namespace std;

int longestBitonicSequence(int n, vector<int> &arr) {

    vector<int>dp1(n,1);
    vector<int>dp2(n,1);
    
    for(int i = 1;i < n; i++)
    {
        for(int j = 0;j < i; j++)
        {
            if(arr[i] > arr[j] && 1 + dp1[j] > dp1[i])
            {
                dp1[i] = 1 + dp1[j];
            }
        }
    }
    
    for(int i = n - 2; i >= 0 ; i--)
    {
        for(int j = n - 1; j > i; j--)
        {
            if(arr[i] > arr[j] && 1 + dp2[j] > dp2[i])
            {
                dp2[i] = 1 + dp2[j];
            }   
        }
    }
    
    int maxi = 0;
    for(int i = 0;i<n;i++){
        if(dp1[i] > 1 && dp2[i] > 1){
            maxi = max(dp1[i] + dp2[i] - 1 ,maxi) ;
        }
    }
    
    return maxi;
}

int main()
{
    vector<int>arr = {1, 11, 2, 10, 4, 5, 2, 1};
    int n = arr.size();
    cout << longestBitonicSequence(n,arr);
    return 0;
}   