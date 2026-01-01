#include<bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int>dp(n,1);
    vector<int>prevIdx(n,-1);
    int maxiIdx = 0;
    int maxi = 0;

    for(int i = 1;i < n;i++){
        for(int j = 0;j < i;j++){
            if(nums[i] % nums[j] == 0){
                if(dp[i] > 1 + dp[j])continue;
                dp[i] = max(dp[i],1+dp[j]);
                prevIdx[i] = j;
            }

            if(dp[i] > maxi){
                maxi = dp[i];
                maxiIdx = i;
            }
        }
    }
    vector<int>ans;
    while(maxiIdx != -1){
        ans.push_back(nums[maxiIdx]);
        maxiIdx = prevIdx[maxiIdx];
    }
    return ans;
}

int main(){
    vector<int>arr={1,4,2,8};
    vector<int>ans = largestDivisibleSubset(arr);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}