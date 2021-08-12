/*
329. Longest Increasing Path in a Matrix
Hard

3784

64

Add to List

Share
Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

 

Example 1:


Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:


Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
Example 3:

Input: matrix = [[1]]
Output: 1
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 231 - 1
*/


class Solution {
public:
    int dp[201][201];
    int rec(vector<vector<int>>& matrix,int i,int j,int r,int c)
    {
        if(dp[i][j]!=0)
        {
            return dp[i][j];
        }
        int a = 0;
        int b = 0;
        int f = 0;
        int d = 0;
        if(i-1>=0 && matrix[i-1][j]>matrix[i][j])
        {
                a = rec(matrix,i-1,j,r,c);
        }
        if(i+1<r && matrix[i+1][j]>matrix[i][j])
        {
                b = rec(matrix,i+1,j,r,c);        
        }
        if(j-1>=0 && matrix[i][j-1]>matrix[i][j])
        {
                f = rec(matrix,i,j-1,r,c);
        }
        if(j+1<c && matrix[i][j+1]>matrix[i][j])
        {
            d = rec(matrix,i,j+1,r,c);
        }
        return dp[i][j] = max(a,max(b,max(f,d)))+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int r = matrix.size(); 
        int c = matrix[0].size();
        memset(dp,0,sizeof(dp));
        for(int i  = 0 ; i<r;i++)
        {
            for(int j = 0;j<c;j++)
            {
                if(dp[i][j]==0)
                {
                    rec(matrix,i,j,r,c);
                }
            }
        }
        int ans = 1;
        for(int i = 0;i<r;i++)
        {
            for(int j = 0 ; j<c;j++)
            {
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
