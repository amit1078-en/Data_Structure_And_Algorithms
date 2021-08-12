
/*
1937. Maximum Number of Points with Cost
User Accepted:846
User Tried:3555
Total Accepted:887
Total Submissions:8814


Difficulty:Medium
You are given an m x n integer matrix points (0-indexed). Starting with 0 points, you want to maximize the number of points you can get from the matrix.

To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.

However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.

Return the maximum number of points you can achieve.

abs(x) is defined as:

x for x >= 0.
-x for x < 0.
 

Example 1:


Input: points = [[1,2,3],[1,5,1],[3,1,1]]
Output: 9
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 2), (1, 1), and (2, 0).
You add 3 + 5 + 3 = 11 to your score.
However, you must subtract abs(2 - 1) + abs(1 - 0) = 2 from your score.
Your final score is 11 - 2 = 9.
Example 2:


Input: points = [[1,5],[2,3],[4,2]]
Output: 11
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 1), (1, 1), and (2, 0).
You add 5 + 3 + 4 = 12 to your score.
However, you must subtract abs(1 - 1) + abs(1 - 0) = 1 from your score.
Your final score is 12 - 1 = 11.
 

Constraints:

m == points.length
n == points[r].length
1 <= m, n <= 105
1 <= m * n <= 105
0 <= points[r][c] <= 105


*/

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        
      int row = points.size();
        int col = points[0].size();
        vector<vector<long long>> temp;
        for(int i = 0 ; i<row;i++)
        {
          vector<long long> t;
          long long v;
          for(int j= 0; j<col;j++)
          {
            v = points[i][j];
            t.push_back(v);
          }
          temp.push_back(t);
        }
        
        for(int i = row-2;i>=0;i--)
        {
          
          vector<long long> help;
          int ele = 0;
          help.push_back(temp[i+1][0]);
          for(int j = 1 ; j<col;  j++)
          {
            long long  c = temp[i+1][j];
            help.push_back(max(c,help[j-1]-1));
          }
          for(int j = col-2;j>=0;j--)
          {
            long long c = temp[i+1][j];
            help[j] = max(help[j+1]-1,max(help[j],c));
          }
          for(int j = 0;j<col;j++)
          {
              long long p;
              if(j==0){
                    p = help[j+1];
              }
              else if(j==help.size()-1){
                p = help[j-1];
              }
              else if(j!=0 && j!=help.size()-1){
                p = max(help[j-1],help[j+1]);
              }
              temp[i][j] = temp[i][j]+help[j];
          }
          
        }
      
      long long ans = INT_MIN;
        for(int i = 0 ;i<col;i++)
        {
          ans = max(ans,temp[0][i]);
        }
      return ans;
    }
  
};
