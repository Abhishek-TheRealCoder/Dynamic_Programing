// Given an integer array nums, return the number of subarrays filled with 0.

// A subarray is a contiguous non-empty sequence of elements within an array.

 

// Example 1:

// Input: nums = [1,3,0,0,2,0,0,4]
// Output: 6
// Explanation: 
// There are 4 occurrences of [0] as a subarray.
// There are 2 occurrences of [0,0] as a subarray.
// There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.

// Example 2:

// Input: nums = [0,0,0,2,0,0]
// Output: 9
// Explanation:
// There are 5 occurrences of [0] as a subarray.
// There are 3 occurrences of [0,0] as a subarray.
// There is 1 occurrence of [0,0,0] as a subarray.
// There is no occurrence of a subarray with a size more than 3 filled with 0. Therefore, we return 9.

// Example 3:

// Input: nums = [2,10,2019]
// Output: 0
// Explanation: There is no subarray filled with 0. Therefore, we return 0.
 

// Constraints:

// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109

#include<bits/stdc++.h>
using namespace std;

// a) method 1: using two pointers
// long long zeroFilledSubarray(vector<int>& nums) {
//     int n = nums.size();
//     long long cnt = 0;
//     int i = 0;
//     int j = 0;
//     while(j < n)
//     {
//         if(nums[j] == 0)
//         {
//             i = j;
//             while(j < n && nums[j] == nums[i])
//             {
//                 cnt += j - i + 1;
//                 j++;
//             }
//             i = j;
//         }
//         else{
//             j++;
//         }

//     }
//     return cnt;
// }

// b) method 2: DP
// dp[i] = number of subarrays fillled with zero ending at index i
long long zeroFilledSubarray(vector<int>& nums) {
    int n = nums.size();
    
    vector<int>dp(n,0);

    for(int i = 0;i < n;i++)
    {
        if(nums[i] == 0)
        {
            if(i > 0 && nums[i-1] == 0)
            {
                dp[i] = 1 + dp[i] + dp[i-1];
            }
            else
            {
                dp[i] = 1 + dp[i];
            }
        }
    }

    long long sum = 0;
    for(int i = 0;i < n;i++)
    {
        sum += dp[i];
    }
    return sum;
}
int main()
{
    vector<int> nums = {1,3,0,0,2,0,0,4};
    cout<<zeroFilledSubarray(nums)<<endl;
    return 0;
}