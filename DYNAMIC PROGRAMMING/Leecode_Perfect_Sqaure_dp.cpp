/*
279. Perfect Squares
Medium

4776

248

Add to List

Share
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

 

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
 

Constraints:

1 <= n <= 104
*/


class Solution {
public:
    int numSquares(int n) {
        // ok we can solve this question using 
        if(n==1 || n==2 || n==3)
        {
          return n;
        }
      
       if(floor(sqrt(n))==ceil(sqrt(n)))return 1;
        
      vector<int> arr;
        for(int i = 1; (i*i)<n;i++)
        {
          arr.push_back(i*i);
        }
      // cout<<endl;
        int dp[arr.size()+1][n+1];
      
        for(int i = 0; i<=n;i++)
        {
          dp[0][i] = INT_MAX;
        }
        
        for(int i =1; i<=arr.size();i++)
        {
          dp[i][0]= 0 ;
        }
        for(int i = 1;  i<=n;i++)
        {
          dp[1][i] = i;
        }
      for(int i = 2;i<=arr.size();i++)
      {
        for(int j = 1;j<=n;j++)
        {
          if(arr[i-1]>j)
          {
            dp[i][j] = dp[i-1][j];
            continue; 
          }
          dp[i][j] = min(dp[i][j-arr[i-1]]+1,dp[i-1][j]);
        }
      }
      return dp[arr.size()][n];
      }
};
