// Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to 
// remove to make the rest of the intervals non-overlapping.

// Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

 

// Example 1:

// Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

// Example 2:

// Input: intervals = [[1,2],[1,2],[1,2]]
// Output: 2
// Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

// Example 3:

// Input: intervals = [[1,2],[2,3]]
// Output: 0
// Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 

// Constraints:

// 1 <= intervals.length <= 105
// intervals[i].length == 2
// -5 * 104 <= starti < endi <= 5 * 104


#include<bits/stdc++.h>
using namespace std;

int dp[100001];
int maxNumberOfNONOverlapping(int idx,int n,vector<vector<int>>& intervals)
{
    if(idx >= n) return 0;
    if(dp[idx] != -1) return dp[idx];
    int LastElement = intervals[idx][1];

    int s = idx + 1;
    int e = n - 1;
    int nextIdx = n;
    while(s <= e)
    {
        int mid = s + (e - s)/2;
    
        if(intervals[mid][0] >= LastElement)
        {
            nextIdx = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    int include = 1 + maxNumberOfNONOverlapping(nextIdx,n,intervals);
    int exclude = maxNumberOfNONOverlapping(idx + 1,n,intervals);

    return  dp[idx] = max(include,exclude);
}
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    // calc maximum no of non overlapping intervals
    int n = intervals.size();
    memset(dp,-1,sizeof(dp));
    sort(intervals.begin(),intervals.end()); // normal sorting based on firt element in asending becoz later in BS we are comparing first element so we need sorting based on first element
    int ans = maxNumberOfNONOverlapping(0,n,intervals);
    return n - ans;
}


int main()
{
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    cout<<eraseOverlapIntervals(intervals);
    return 0;
}