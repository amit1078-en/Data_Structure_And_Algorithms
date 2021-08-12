/*
Given two integers m & n, find the number of possible sequences of length n such that each of the next element is greater than or equal to twice of the previous element but less than or equal to m.


Example 1:

Input: m = 10, n = 4
Output: 4
Explaination: There should be n elements and 
value of last element should be at-most m. 
The sequences are {1, 2, 4, 8}, {1, 2, 4, 9}, 
{1, 2, 4, 10}, {1, 2, 5, 10}.

Example 2:

Input: m = 5, n = 2
Output: 6
Explaination: The sequences are {1, 2}, 
{1, 3}, {1, 4}, {1, 5}, {2, 4}, {2, 5}.

Your Task:
You do not need to read input or print anything. Your task is to complete the function numberSequence() which takes the number m and n as input parameters and returns the number of sequences.


Expected Time Complexity: O(m*n)
Expected Auxiliary Space: O(1)


Constraints:
1 = m, n = 100
*/
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[101][101];
    int rec(int n,int m)
    {
        if(m==0 && n>=1)
        {
            return 0;
        }
        if(n==0)
        {
            return 1;
        }
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        dp[n][m] = rec(n-1,m/2)+rec(n,m-1);
        return dp[n][m];
    }
    int numberSequence(int m, int n)
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return rec(n,m);
    }
};






// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends
