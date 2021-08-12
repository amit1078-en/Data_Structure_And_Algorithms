/*
120. Triangle
Medium

3290

330

Add to List

Share
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
 

Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?
*/


class Solution {
public:
       int track[1000][1000];
int help( vector<vector<int>> &A,int row,int size,int ele) 
{
    if(row>=size )
    {
        return 0;
    }
    if(ele>=row+1 || ele==-1)
    {
        return INT_MAX;
    }
    if(track[row][ele]!=-1)
    {
        return track[row][ele];
    }
    track[row][ele] = A[row][ele]+min(help(A,row+1,size,ele+1),help(A,row+1,size,ele));
    return track[row][ele];
}
    int minimumTotal(vector<vector<int>>& triangle) {
         int ans = 0;
        for(int i = 0 ; i<triangle.size();i++)
        {
            for(int j = 0;j<=i;j++)
            {
                track[i][j] = -1;
            }
        }
        ans = help(triangle,0,triangle.size(),0);
        return ans;
    }
};

