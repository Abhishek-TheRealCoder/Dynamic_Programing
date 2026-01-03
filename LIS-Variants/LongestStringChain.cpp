// Longest String Chain
// You are given an array of words where each word consists of lowercase English letters.
// wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without 
// changing the order of the other characters to make it equal to wordB.
// For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
// A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.
// Return the length of the longest possible word chain with words chosen from the given list of words.

// Example 1:

// Input: words = ["a","b","ba","bca","bda","bdca"]
// Output: 4
// Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
// Example 2:

// Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
// Output: 5
// Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
// Example 3:

// Input: words = ["abcd","dbqca"]
// Output: 1
// Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
// ["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.

#include<bits/stdc++.h>
using namespace std;

bool isSubseq(string s1,string s2){
    int n = s1.size();
    int m = s2.size();

    int i = 0;
    int j = 0;
    while(i < n && j < m){
        if(s1[i] == s2[j]){
            j++;
        }
        i++;
    }
    return j == m;
    
}

bool isPred(string s1, string s2){
    int n = s1.size();
    int m = s2.size();
    if(n - m == 1 && isSubseq(s1,s2)){
        return true;
    }
    return false;

}
int longestStrChain(vector<string>& words) {
    int n = words.size();
    sort(words.begin(),words.end(),[](const string&a,const string &b){
        return a.size() < b.size();
    });

    vector<int>dp(n,1);
    int maxi = 1;
    for(int i = 0;i < n; i++){
        for(int j = 0 ; j < i ; j++){
            if(isPred(words[i],words[j])){
                dp[i] = max(dp[i] , 1 + dp[j]);
                maxi = max(maxi, dp[i]);
            }
        }
    }
    return maxi;
    
}
int main(){
    vector<string>words = {"xbc","pcxbcf","xb","cxbc","pcxbc"};
    int ans = longestStrChain(words);
    cout<<ans;
    return 0;
}