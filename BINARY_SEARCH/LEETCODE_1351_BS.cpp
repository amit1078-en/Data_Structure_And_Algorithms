/*
Share
Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

 

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0
Example 3:

Input: grid = [[1,-1],[-1,-1]]
Output: 3
Example 4:

Input: grid = [[-1]]
Output: 1
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100
 

Follow up: Could you find an O(n + m) solution?
Accepted
124,300
Submissions
164,739
Seen this question in a real interview before?

Yes

No

*/
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0 ;
        for(int i= 0 ; i<grid.size();i++)
        {
          if(grid[i][grid[0].size()-1]>=0)
          {
            continue;
          }
            if(grid[i][0]<0)
            {
              ans+=grid[0].size();
              continue;
            }
            int ind =  lower_bound(grid[i].begin(),grid[i].end(),0,greater<int>()) -  grid[i].begin();
            if(ind==grid[i].size())
            {
              continue; 
            }
            if(grid[i][ind]==0)
            {
              ind = upper_bound(grid[i].begin(),grid[i].end(),0,greater<int>()) -  grid[i].begin();
             ans+=grid[0].size()-ind;
            }
            else
            {
              ans+=grid[0].size()-ind;
            }
        }
      cout<<endl;
        return  ans;
    }
};
