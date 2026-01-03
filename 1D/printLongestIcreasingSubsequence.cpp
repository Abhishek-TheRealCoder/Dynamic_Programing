#include<bits/stdc++.h>
using namespace std;

vector<int>printLIS(vector<int>&arr){
    int n = arr.size();
    int maxi = 1;
    vector<int>dp(n+1,1);
    vector<int>path(n+1,-1);
    int index = 0;
    for(int i = 1 ;i < n; i++){
        for(int j = i;j >= 0; j--){
            if(arr[i] > arr[j]){
                if(1 + dp[j] > dp[i]){
                    path[i] = j;
                    dp[i] = 1 + dp[j];
                }

                if(maxi < dp[i]){
                    maxi = dp[i];
                    index = i;
                }
            }
        }
    }
    vector<int>ans;
    while(index != -1){
        ans.push_back(arr[index]);
        index = path[index];
    }

    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    vector<int>arr = {10,9,2,5,3,7,101,18};
    vector<int>ans = printLIS(arr);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}
