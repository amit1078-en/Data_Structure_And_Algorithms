/*
Minimum Path Sum
Medium

5156

86

Add to List

Share
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, 
which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 ? 3 ? 1 ? 1 ? 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100
*/

bottom down memonised solution
class Solution {
public:
  int dp[201][201];
    int fun(int r,int c,vector<vector<int>>& grid,int row,int col)
    {
      if(r==row-1  && c==col-1)
      {
        return grid[r][c];
      }
      
      if(r==row || c==col)return 1e9;
      
      if(dp[r][c]!=-1)
      {
        return dp[r][c];
      }
      
      return dp[r][c] = min(fun(r+1,c,grid,row,col),fun(r,c+1,grid,row,col))+grid[r][c];
    }
    int minPathSum(vector<vector<int>>& grid) {
      memset(dp,-1,sizeof(dp));
      return fun(0,0,grid,grid.size(),grid[0].size());   
    }
};



top down 

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        for(int i = col-2;i>=0;i--)
        {
          grid[row-1][i]+=grid[row-1][i+1];
        }
        for(int i = row-2;i>=0;i--){
          grid[i][col-1]+=grid[i+1][col-1];
        }
        for(int i = row-2;i>=0;i--)
        {
          for(int j = col-2;j>=0;j--)
          {
            grid[i][j]+=min(grid[i+1][j],grid[i][j+1]);
          }
        }
      return grid[0][0];
    }
};
