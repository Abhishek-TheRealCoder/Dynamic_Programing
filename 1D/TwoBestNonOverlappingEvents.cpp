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
// int solve(int idx,int n,int prev ,vector<pair<pair<int,int>,int>>&time,int count)
// {
//     if(idx >= n || count == 0) return 0;

//     int include = 0;
//     if(prev == -1 || time[idx].first.first > time[prev].first.second)
//     {
//         include = time[idx].second + solve(idx+1,n,idx,time,count - 1);
//     }
//     int exclude = solve(idx+1,n,prev,time,count);

//     return max(include,exclude);
// }
// int maxTwoEvents(vector<vector<int>>& events) {
        
//     int n = events.size();
//     vector<pair<pair<int,int>,int>>time;
//     for(int i = 0;i < n;i++)
//     {
//         time.emplace_back(make_pair(make_pair(events[i][0],events[i][1]),events[i][2]));
//     }

//     auto lambda = [](const pair<pair<int,int>,int>&a , pair<pair<int,int>,int>&b){
//         return a.first.second < b.first.second;
//     };

//     sort(time.begin(),time.end(),lambda);
//     return solve(0,n,-1,time,2);
// } 

// NOTE: The above recursive approach gives TLE because of the overlapping subproblems. We are calculating the same subproblems multiple times which causes unecessary computation. To tackle this we can use memoization to store the computational value and return it when again needed. This will reduce the time complexity from O(2^n) to O(n*count) where count is the number of events we can attend which is 2 in this case.
// This Approach is right but since there are 3 parameters which are changing in the recursive function, we need to use a 3D vector for memoization which will consume a lot of space.


// b) Recursion + Memoization Based on upper Recursion 
// int dp[100001][100001][3];
// int solve(int idx,int n,int prev ,vector<pair<pair<int,int>,int>>&time,int count)
// {
//     if(idx >= n || count == 0) return 0;

//     if(prev != -1 && dp[idx][prev][count] != -1) return dp[idx][prev][count];

//     int include = 0;
//     if(prev == -1 || time[idx].first.first > time[prev].first.second)
//     {
//         include = time[idx].second + solve(idx+1,n,idx,time,count - 1);
//     }
//     int exclude = solve(idx+1,n,prev,time,count);

//     return dp[idx][prev][count] = max(include,exclude);
// }

// int maxTwoEvents(vector<vector<int>>& events) {
        
//     int n = events.size();
//     vector<pair<pair<int,int>,int>>time;
//     memset(dp,-1,sizeof(dp));
//     for(int i = 0;i < n;i++)
//     {
//         time.emplace_back(make_pair(make_pair(events[i][0],events[i][1]),events[i][2]));
//     }
//     sort(time.begin(),time.end());
//     return solve(0,n,-1,time,2);
// }

int dp[100001][3];
int solve(int idx,int n,vector<pair<pair<int,int>,int>>&time,int count)
{
    if(idx >= n || count == 0) return 0;
    
    if(dp[idx][count] != -1) return dp[idx][count];

    int LastElement = time[idx].first.second; // we are comparing the last element of the current event with the first element of the next event to check for non overlapping condition
    int s = idx + 1;
    int e = n - 1;

    int nextIdx = n; // if we dont find any non overlapping event then we will return n which is out of bound index and in the next recursive call we will check for this condition and return 0 if we get this index
    
    while(s <= e)
    {
        int mid = s + (e - s) / 2;
        if(time[mid].first.first > LastElement) // we are comparing the first element of the next event with the last element of the current event to check for non overlapping condition
        {
            nextIdx = mid; // we found a non overlapping event so we will update the startIdx to this index and continue searching in the left half to find the first non overlapping event
                            // this helps preventing use of prev pointer in the recursive call and we can directly pass the current index to the next recursive call which will be used in binary search to find the next non overlapping event
            e = mid - 1;
        }
        else
        {
            s = mid + 1; // we need to search in the right half to find a non overlapping event
        }
    }

    int include = time[idx].second + solve(nextIdx , n , time , count - 1); // now we dont need prev pointer becoz binary Search will take care of the non overlapping condition and we are just passing the current index to the next recursive call which will be used in binary search to find the next non overlapping event
    int exclude = solve(idx + 1 , n , time ,count);

    return dp[idx][count] = max(include,exclude);
}
// c) Better Approach (Sorting + Binary Search and DP Memoization)
int maxTwoEvents(vector<vector<int>>& events) {
        
    int n = events.size();
    vector<pair<pair<int,int>,int>>time;
    memset(dp,-1,sizeof(dp));
    for(int i = 0;i < n;i++)
    {
        time.emplace_back(make_pair(make_pair(events[i][0],events[i][1]),events[i][2]));
    }

    sort(time.begin(),time.end()); // normal sorting based on firt element in asending becoz later in BS we are comparing 
                                  // first element so we need sorting based on first element

    return solve(0,n,time,2);
}


int main()
{
    vector<vector<int>> events = {{1,3,2},{4,5,2},{2,4,3}};
    sort(events.begin(), events.end());
    int ans = maxTwoEvents(events);
    cout<< ans;
    return 0;
}