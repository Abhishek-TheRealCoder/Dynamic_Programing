// There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

// You have to form a team of 3 soldiers amongst them under the following rules:

// Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
// A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
// Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

 

// Example 1:

// Input: rating = [2,5,3,4,1]
// Output: 3
// Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 

// Example 2:

// Input: rating = [2,1,3]
// Output: 0
// Explanation: We can't form any team given the conditions.

// Example 3:

// Input: rating = [1,2,3,4]
// Output: 4
 

// Constraints:

// n == rating.length
// 3 <= n <= 1000
// 1 <= rating[i] <= 105
// All the integers in rating are unique.

#include<bits/stdc++.h>
using namespace std;

a) Recursion
int solve(int idx,int prev,int n,vector<int>& rat,int cnt)
{

    if(cnt == 0)
    {
        return 1;
    }

    if(idx >= n)
    {
        if(cnt == 0) return 1;
        return 0;
    }


    int include = 0;
    if(prev == -1 || rat[idx] > rat[prev])
    {
        include = solve(idx + 1 , idx , n , rat , cnt - 1);
    }
    int exclude = solve(idx + 1, prev , n , rat , cnt );
        

    return include + exclude;

}
int numTeams(vector<int>& rat) {
    int n = rat.size();
    int normal = solve(0,-1,n,rat,3); 
    reverse(rat.begin(),rat.end());
    int reverse = solve(0,-1,n,rat,3);
    return normal + reverse;
}

// b) Recursive + Memoization
int dp[1001][1001][4];

int solve(int idx,int prev,int n,vector<int>& rat,int cnt)
{

    if(cnt == 0)
    {
        return 1;
    }

    if(idx >= n)
    {
        if(cnt == 0) return 1;
        return 0;
    }

    if(prev != -1 && dp[idx][prev][cnt] != -1) return dp[idx][prev][cnt];


    int include = 0;
    if(prev == -1 || rat[idx] > rat[prev])
    {
        include = solve(idx + 1 , idx , n , rat , cnt - 1);
    }
    int exclude = solve(idx + 1, prev , n , rat , cnt );
        
    if(prev == -1) return include + exclude;
    return dp[idx][prev][cnt] = include + exclude;

}
int numTeams(vector<int>& rat) {
    int n = rat.size();
    memset(dp,-1,sizeof(dp));
    int normal = solve(0,-1,n,rat,3); 
    reverse(rat.begin(),rat.end());
    memset(dp,-1,sizeof(dp));
    int reverse = solve(0,-1,n,rat,3);
    return normal + reverse;
}
};
int main()
{
    vector<int> rat = {2,5,3,4,1};
    cout<<numTeams(rat)<<endl;
    return 0;
}