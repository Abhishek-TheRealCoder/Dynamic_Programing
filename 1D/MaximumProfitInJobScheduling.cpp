// // DP + BinarySearch

// We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].
// You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no 
// two jobs in the subset with overlapping time range.

// If you choose a job that ends at time X you will be able to start another job that starts at time X.

// Example 1:
// Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
// Output: 120
// Explanation: The subset chosen is the first and fourth job. 
// Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.


// Example 2:
// Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
// Output: 150
// Explanation: The subset chosen is the first, fourth and fifth job. 
// Profit obtained 150 = 20 + 70 + 60.

// Example 3:
// Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
// Output: 6
 

// Constraints:

// 1 <= startTime.length == endTime.length == profit.length <= 5 * 104
// 1 <= startTime[i] < endTime[i] <= 109
// 1 <= profit[i] <= 104

#include <bits/stdc++.h>
using namespace std;

int dp[50001];
int solve(int idx,int n,vector<pair<pair<int,int>,int>>&time)
{
    if(idx >= n) return 0;
    if(dp[idx] != -1) return dp[idx];

    int exclude = solve(idx + 1, n , time);

    int currElmt = time[idx].first.second;
    int s = idx + 1;
    int e = n - 1;
    int startIdx = n;

    while(s <= e)
    {
        int mid =  s + ( e - s ) / 2;
        if(time[mid].first.first >= currElmt)
        {
            startIdx = mid;
            e = mid - 1;
        }else
        {
            s = mid + 1;
        }
    }

    int include = time[idx].second   + solve(startIdx,n,time);

    return dp[idx] = max(include,exclude);
}

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    vector<pair<pair<int,int>,int>> time;
    int n = profit.size();
    for(int i = 0;i < n; i++)
    {
        time.emplace_back(make_pair(make_pair(startTime[i],endTime[i]),profit[i]));
    }

    sort(time.begin(),time.end());// we will sort based on firstElement becoz in Binary Search we are searching element based on first element
    memset(dp,-1,sizeof(dp));
    return solve(0,n,time);
}

int main()
{
    vector<int>startTime = {1,2,3,3};
    vector<int>endTime = {3,4,5,6};
    vector<int>profit = {50,10,40,70};
    cout << jobScheduling(startTime,endTime,profit);
    return 0;
}