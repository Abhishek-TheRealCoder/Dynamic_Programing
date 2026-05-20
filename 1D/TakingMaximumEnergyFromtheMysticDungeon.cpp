// In a mystic dungeon, n magicians are standing in a line. Each magician has an attribute that gives you energy. 
// Some magicians can give you negative energy, which means taking energy from you.

// You have been cursed in such a way that after absorbing energy from magician i, you will be instantly transported to 
// magician (i + k). This process will be repeated until you reach the magician where (i + k) does not exist.

// In other words, you will choose a starting point and then teleport with k jumps until you reach the end of the 
// magicians' sequence, absorbing all the energy during the journey.
// You are given an array energy and an integer k. Return the maximum possible energy you can gain.
// Note that when you reach a magician, you must take energy from them, whether it is negative or positive energy.

 

// Example 1:

// Input: energy = [5,2,-10,-5,1], k = 3

// Output: 3

// Explanation: We can gain a total energy of 3 by starting from magician 1 absorbing 2 + 1 = 3.

// Example 2:

// Input: energy = [-2,-3,-1], k = 2

// Output: -1

// Explanation: We can gain a total energy of -1 by starting from magician 2.
 

// Constraints:

// 1 <= energy.length <= 105
// -1000 <= energy[i] <= 1000
// 1 <= k <= energy.length - 1
 
#include <bits/stdc++.h>
using namespace std;

// a) recursion
// int solve(int idx,int n,vector<int>&energy,int k)
// {
//     if(idx >= n) return 0;

//     int ans = energy[idx] + solve(idx + k,n,energy,k);
//     return ans;
// }


// b) memoization + recursion
// int solve(int idx,int n,vector<int>&energy,int k,vector<int>&dp)
// {
//     if(idx >= n) return 0;
//     if(dp[idx] != INT_MIN) return dp[idx];

//     int ans = energy[idx] + solve(idx + k,n,energy,k,dp);
//     return dp[idx] = ans;
// }


// int maximumEnergy(vector<int>& energy, int k)
// {
//     int n = energy.size();
//     int maxi = INT_MIN;
//     vector<int>dp(n,INT_MIN);
//     for(int i = 0;i < n;i++){
//         maxi = max(maxi,solve(i,n,energy,k,dp));
//     }
//     return maxi;
// }

// c) bottom-up
int maximumEnergy(vector<int>& energy, int k)
{
    int n = energy.size();
    
    vector<int>dp(n,0);
    for(int i = n - 1;i >= 0; i--)
    {
        if(i + k < n)
        {
            dp[i] = energy[i] + dp[i + k];
        }
        else
        {
            dp[i] = energy[i];
        }
    }
    return *max_element(dp.begin(),dp.end());
}
int main()
{
    vector<int> energy = {5, 2, -10, -5, 1};
    int k = 3;
    cout << maximumEnergy(energy, k) << endl;
    return 0;
}