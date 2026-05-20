// You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. The ith event starts at 
// startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. You can choose at most two 
// non-overlapping events to attend such that the sum of their values is maximized.

// Return this maximum sum.

// Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts 
// and the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at or after t + 1.

// Example 1:
// Input: events = [[1,3,2],[4,5,2],[2,4,3]]
// Output: 4
// Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.

// Example 2:
// Input: events = [[1,3,2],[4,5,2],[1,5,5]]
// Output: 5
// Explanation: Choose event 2 for a sum of 5.

// Example 3:
// Input: events = [[1,5,3],[1,5,1],[6,6,5]]
// Output: 8
// Explanation: Choose events 0 and 2 for a sum of 3 + 5 = 8.
 
// Constraints:

// 2 <= events.length <= 105
// events[i].length == 3
// 1 <= startTimei <= endTimei <= 109
// 1 <= valuei <= 106


#include<bits/stdc++.h>
using namespace std;

// a) Recursive approach (TLE)


int solve(int idx,int n,int prev ,vector<pair<pair<int,int>,int>>&time,int count)
{
    if(idx >= n || count == 0) return 0;

    int include = 0;
    if(prev == -1 || time[idx].first.first > time[prev].first.second)
    {
        include = time[idx].second + solve(idx+1,n,idx,time,count - 1);
    }
    int exclude = solve(idx+1,n,prev,time,count);

    return max(include,exclude);
}
int maxTwoEvents(vector<vector<int>>& events) {
        
    int n = events.size();
    vector<pair<pair<int,int>,int>>time;
    for(int i = 0;i < n;i++)
    {
        time.emplace_back(make_pair(make_pair(events[i][0],events[i][1]),events[i][2]));
    }

    auto lambda = [](const pair<pair<int,int>,int>&a , pair<pair<int,int>,int>&b){
        return a.first.second < b.first.second;
    };

    sort(time.begin(),time.end(),lambda);
    return solve(0,n,-1,time,2);
}



int main()
{
    vector<vector<int>> events = {{1,3,2},{4,5,2},{2,4,3}};
    sort(events.begin(), events.end());
    int ans = maxTwoEvents(events);
    cout<< ans;
    return 0;
}