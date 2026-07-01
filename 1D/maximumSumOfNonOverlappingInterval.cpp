// Problem:
// Given intervals of the form [start, end, weight], choose up to 4 non-overlapping intervals so that the total weight is maximum.
// Example:
// Input:
// vector<vector<int>> intervals = {
//     {1, 3, 2},
//     {4, 5, 2},
//     {1, 5, 5},
//     {6, 9, 3},
//     {6, 7, 1},
//     {8, 9, 1}
// };

// Output:
// 8

#include <bits/stdc++.h>
using namespace std;

long long solve(int idx, int n,
                vector<vector<int>>& intervals,
                int cnt)
{
    if(idx >= n)
        return 0;

    if(cnt == 4)
        return 0;

    long long exclude = solve(idx + 1, n, intervals, cnt);

    int currEnd = intervals[idx][1];

    int s = idx + 1;
    int e = n - 1;
    int nextIdx = n;

    while(s <= e)
    {
        int mid = s + (e - s)/2;

        if(intervals[mid][0] > currEnd)
        {
            nextIdx = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }

    long long include =
        1LL * intervals[idx][2] +
        solve(nextIdx, n, intervals, cnt + 1);

    return max(include, exclude);
}

long long maximumWeight(vector<vector<int>>& intervals) {

    sort(intervals.begin(), intervals.end());

    return solve(0, intervals.size(), intervals, 0);
}


int main()
{
    // vector<vector<int>> intervals = {{1, 2, 4}, {3, 4, 3}, {2, 3, 1}, {5, 6, 2}};
    // vector<vector<int>> intervals = {{5,8,1},{6,7,7},{4,7,3},{9,10,6},{7,8,2},{11,14,3},{3,5,5}};
    vector<vector<int>>intervals = {
        {1,3,2},
        {4,5,2},
        {1,5,5},
        {6,9,3},
        {6,7,1},
        {8,9,1}
    };
    cout << maximumWeight(intervals) << endl;
    return 0;
}