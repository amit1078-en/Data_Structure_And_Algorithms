/*
      Largest Plus Sign


You are given an integer n. You have an n x n binary grid grid with all values initially 1's except for some indices given in the array mines. The ith element of the array mines is defined as mines[i] = [xi, yi] where grid[xi][yi] == 0.

Return the order of the largest axis-aligned plus sign of 1's contained in grid. If there is none, return 0.

An axis-aligned plus sign of 1's of order k has some center grid[r][c] == 1 along with four arms of length k - 1 going up, down, left, and right, and made of 1's. Note that there could be 0's or 1's beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1's.

 

Example 1:


Input: n = 5, mines = [[4,2]]
Output: 2
Explanation: In the above grid, the largest plus sign can only be of order 2. One of them is shown.
Example 2:


Input: n = 1, mines = [[0,0]]
Output: 0
Explanation: There is no plus sign, so return 0.
 

Constraints:

1 <= n <= 500
1 <= mines.length <= 5000
0 <= xi, yi < n
All the pairs (xi, yi) are unique.

*/
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int left[n][n];
        int right[n][n];
        int up[n][n];
        int down[n][n];
        int ans = 0;
        int dp[n][n];
        for(int i = 0 ;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j] = 1;
                up[i][j] = 1;
                down[i][j] = 1;
                left[i][j] = 1;
                right[i][j] = 1;
            }
        }
        for(int i=0;i<mines.size();i++)
        {
            dp[mines[i][0]][mines[i][1]] = 0;
            up[mines[i][0]][mines[i][1]] = 0;
            down[mines[i][0]][mines[i][1]] = 0;
            left[mines[i][0]][mines[i][1]] = 0;
            right[mines[i][0]][mines[i][1]] = 0;
        }
        int i = 0;
        for(int i = 1;i<n;i++)
        {
            for(int j =1;j<n;j++)
            {
                if(up[i][j]!=0)
                {
                    up[i][j]+=up[i-1][j];
                }
                if(left[i][j]!=0)
                {
                    left[i][j]+=left[i][j-1];
                }
            }
        }
       for(int i = n-2;i>=0;i--)
        {
            for(int j =n-2;j>=0;j--)
            {
                if(down[i][j]!=0)
                {
                    down[i][j]+=down[i+1][j];
                }
                if(right[i][j]!=0)
                {
                     right[i][j]+=right[i][j+1];
                }
            }
        }
        
        for(int i = 1; i<n-1;i++)
        {
            for(int j = 1;j<n-1;j++)
            {
                ans = max(ans,min(min(left[i][j],right[i][j]),min(up[i][j],down[i][j])));
            }
        }
        if(ans==0)
        {
            if(n*n!=mines.size())
            {
                return 1;
            }
        }
        return ans;
    }
};
