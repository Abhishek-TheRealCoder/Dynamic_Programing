// You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the ith job, you have to finish all the jobs j where 0 <= j < i).
// You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the d days. 
// The difficulty of a day is the maximum difficulty of a job done on that day.
// You are given an integer array jobDifficulty and an integer d. The difficulty of the ith job is jobDifficulty[i].

// Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.

#include<bits/stdc++.h>
using namespace std;

int solve(int idx,int day,vector<int>&jd,int n){
    if(day == 1){
        int maxD = jd[idx];
        for(int i = idx;i < n;i++){
            maxD = max(maxD,jd[i]);
        }
        return maxD;
    }
    int maxD = jd[idx];
    int final = INT_MAX;
    for(int i = idx; i <= n-day; i++){
        maxD = max(maxD,jd[i]);
        int res = maxD + solve(i+1,day-1,jd,n);
        final = min(res,final);
    }
    return final;
}   

int minDifficulty(vector<int>& jd, int d) {
    int n = jd.size();
    return solve(0,d,jd,n);
}
int main(){
    vector<int>jd = {6,5,4,3,2,1};
    int day = 2;

    int mini = minDifficulty(jd,day);
    cout<<mini;
    return 0;
}