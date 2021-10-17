/*
2033. Minimum Operations to Make a Uni-Value Grid

You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.

A uni-value grid is a grid where all the elements of it are equal.

Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.

 

Example 1:


Input: grid = [[2,4],[6,8]], x = 2
Output: 4
Explanation: We can make every element equal to 4 by doing the following: 
- Add x to 2 once.
- Subtract x from 6 once.
- Subtract x from 8 twice.
A total of 4 operations were used.
Example 2:


Input: grid = [[1,5],[2,3]], x = 1
Output: 5
Explanation: We can make every element equal to 3.
Example 3:


Input: grid = [[1,2],[3,4]], x = 2
Output: -1
Explanation: It is impossible to make every element equal.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 105
1 <= m * n <= 105
1 <= x, grid[i][j] <= 104


*/

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> maap;
        for(int i = 0 ; i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                maap.push_back(grid[i][j]);
            }
        }
        if(maap.size()==1)
        {
            return 0;
        }
        sort(maap.begin(),maap.end());
        int ans = INT_MAX;
        int left[maap.size()];
        int right[maap.size()];
        int low = maap[0];
        left[0] = 0;
        int step = 1;
        for(int i = 1;i<maap.size();i++)
        {
            int dif = maap[i]-maap[i-1];
            if(dif%x==0)
            {
                if(dif==0)
                {
                    step+=1;
                    left[i] = left[i-1];
                }
                else
                {
                    left[i] = left[i-1]  + (dif/x)*(i);
                    step=1;
                }
            }
            else
            {
                return -1;
            }
        }
        right[maap.size()-1] = 0;
        for(int i = maap.size()-2;i>=0;i--)
        {
            int dif = maap[i+1]-maap[i];
            if(dif%x==0)
            {
                if(dif==0)
                {
                    step+=1;
                    right[i] = right[i+1];
                }
                else
                {
                    right[i] = right[i+1]  + (dif/x)*(maap.size()-i-1);
                }
            }
            else
            {
                return -1;
            }
        }
        for(int i = 0 ; i<maap.size();i++)
        {
         
            ans = min(ans,right[i]+left[i]);
        }
        return ans;
    }
};
