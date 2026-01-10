#include<bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int>dp(n,1);
    vector<int>path(n,-1);
    int maxiIdx = 0;
    int maxi = 0;

    for(int i = 1;i < n;i++){
        for(int j = i - 1;j >= 0;j--){
            if(nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i]){
                dp[i] = 1 + dp[j];
                path[i] = j;
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
        maxiIdx = path[maxiIdx];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    vector<int>arr={3,4,15,32,64};
    vector<int>ans = largestDivisibleSubset(arr);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}