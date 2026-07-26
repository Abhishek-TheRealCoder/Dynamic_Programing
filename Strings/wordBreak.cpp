// Part 2 of WordBreak is in my BackTrack playlist

// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

// Example 1:

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".

// Example 2:

// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
// Note that you are allowed to reuse a dictionary word.

// Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false
 

// Constraints:

// 1 <= s.length <= 300
// 1 <= wordDict.length <= 1000
// 1 <= wordDict[i].length <= 20
// s and wordDict[i] consist of only lowercase English letters.
// All the strings of wordDict are unique.

#include<bits/stdc++.h>
using namespace std;

// a) Recursion
bool solve(int idx, int n,string &s, unordered_map<string,int>&mp)
{
    if(idx >= n) return true;
    
    bool ans = false;
    for(int i = idx; i <= n;i++)
    {
        string substring = s.substr(idx,i - idx + 1); // gives each substring from len 1 to ...
        if(mp.find(substring) != mp.end() && solve(i + 1, n , s , mp ))
        {
            return true;
        }
    }
    return ans;
}
// TC-> O(2^n × n²)

// b) Recursion + Memo
int dp[301];
bool solve(int idx, int n,string &s, unordered_map<string,int>&mp)
{
    if(idx >= n) return true;
    if(dp[idx] != -1) return dp[idx];

    bool ans = false;
    for(int i = idx; i <= n;i++)
    {
        string substring = s.substr(idx,i - idx + 1); // gives each substring from len 1 to ...
        if(mp.find(substring) != mp.end() && solve(i + 1, n , s , mp ))
        {
            return true;
        }
    }
    return dp[idx] = ans;
}
// TC->O(n³)


bool wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string,int>mp;
    memset(dp,-1,sizeof(dp));
    for(auto word : wordDict)
    {
        mp[word]++;
    }
    return solve(0,s.size(),s,mp);
}

int main()
{
    string s = "applepenapple";
    vector<int>wordDict = {"apple","pen"}; 
    cout << wordBreak(s,wordDict);
    return 0;
}