/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

Example 1:

Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum underlined below:
[[2,1,3],      [[2,1,3],
 [6,5,4],       [6,5,4],
 [7,8,9]]       [7,8,9]]
Example 2:

Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is underlined below:
[[-19,57],
 [-40,-5]]
Example 3:

Input: matrix = [[-48]]
Output: -48
 

Constraints:

n == matrix.length
n == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100

*/


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col  = matrix[0].size();
        int ans = INT_MAX;
        for(int i = row-2;i>=0;i--)
        {
          for(int j = 0;j<col;j++)
          {
            int a = INT_MAX;
            int b  = matrix[i+1][j]; 
            int c = INT_MAX;
            if(j-1>=0)
            {
              a = matrix[i+1][j-1];
            }
            if(j+1<col)
            {
              c = matrix[i+1][j+1];
            }
            matrix[i][j]+=min(a,min(b,c));
          }
        }
        for(int i = 0;i<col;i++)
        {
          ans = min(ans,matrix[0][i]);
        }
        return ans;
    }
};

