// Problem statement
// You are given an integer ‘N’ denoting the length of the rod. You need to determine the maximum number of segments you 
// can make of this rod provided that each segment should be of the length 'X', 'Y', or 'Z'.

// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 2
// 7 5 2 2
// 8 3 3 3
// Sample Output 1:
// 2
// 0
// Explanation For Sample Input 1:

// In the first test case, cut it into 2 parts of 5 and 2.

// In the second case, there is no way to cut into segments of 3 length only as the length of the rod is less than the given length. 

// Sample Input 2:
// 2
// 7 3 2 2
// 8 1 4 4
// Sample Output 2:
// 3
// 8
// Explanation For Sample Input 2:
// In the first test case, cut it into 3 parts of 3, 2 and 2.

// In the second case, cut it into 8 parts of length 1.


#include<bits/stdc++.h>
using namespace std;

int solve(int n, int x, int y, int z )
{
	if(n == 0) return 0;
	if(n < 0) return INT_MIN;
	

	int a = 1 + solve(n - x, x , y , z );
	int b = 1 + solve(n - y, x , y , z );
	int c = 1 + solve(n - z, x , y, z );

	return max({a,b,c});
}
int cutSegments(int n, int x, int y, int z) {
	int res = solve(n,x,y, z);
	if(res < 0) return 0;
	return res;
}

int main(){
    int n = 7;
    int x = 5;
    int y = 2;
    int z = 2;
    cout<< cutSegments(n,x,y,z);
    return 0;
}