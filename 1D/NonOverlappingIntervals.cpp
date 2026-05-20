
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