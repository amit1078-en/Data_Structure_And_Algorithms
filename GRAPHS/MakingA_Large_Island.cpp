/*
https://leetcode.com/problems/making-a-large-island/
827. Making A Large Island
Hard

1029

29

Add to List

Share
You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
*/
/*
algorithm
step1 -> make all islands in grid 2d array
step2 -> make one universal unordered_map of type string and int
step 3-> now traverse the 2 d array & whenever we encounter any 1 we call dfs function and count all elements in that element and also push it 
into the map and replace all elements of vector with the frequency
step 4-> now traverse the 2 d array & whenever we encounter 0 we add 1 to temp value and check in all 4 directions with required conditions.
*/
class Solution {
public:
  unordered_map<string,int> maap;
  int dfs(int i,int j,int r,int c,int k,vector<vector<int>>& grid)
  {
    queue<pair<int,int>> Q;
    Q.push({i,j});
    maap[to_string(i)+"+"+to_string(j)] = k;
    int area = 0;
    vector<pair<int,int>> help;
    while(!Q.empty())
    {
      area+=1;
      int x = Q.front().first;  
      int y = Q.front().second;
      help.push_back({x,y});
      Q.pop();
      if(x-1>=0 && grid[x-1][y]==1)
      {
        string tempvar = to_string(x-1)+"+"+to_string(y);
        if(maap.find(tempvar)==maap.end())
        {
          Q.push({x-1,y});
          maap[tempvar] = k;          
        }
      }
      if(x+1<r && grid[x+1][y]==1)
      {
        string tempvar = to_string(x+1)+"+"+to_string(y);
        if(maap.find(tempvar)==maap.end())
        {
          Q.push({x+1,y});
          maap[tempvar] = k;          
        }
      }
      if(y+1<c && grid[x][y+1]==1)
      {
        string tempvar = to_string(x)+"+"+to_string(y+1);
        if(maap.find(tempvar)==maap.end())
        {
          Q.push({x,y+1});
          maap[tempvar] = k;          
        }
      }
      if(y-1>=0 && grid[x][y-1]==1)
      {
        string tempvar = to_string(x)+"+"+to_string(y-1);
        if(maap.find(tempvar)==maap.end())
        {
          Q.push({x,y-1});
          maap[tempvar] = k;          
        }
      }
    }
    for(int i = 0 ;i<help.size();i++)
    {
      
      grid[help[i].first][help[i].second] = area;
    }
   return area;
  }
  int largestIsland(vector<vector<int>>& grid) {
        maap.clear();
        int area  = 0;
        int row =      grid.size();
        int column =   grid[0].size();
        int k = 1;
        for(int i = 0;  i<row;i++)
        {
            for(int j = 0 ;j<column;j++)
            {
                  
                  if(grid[i][j]==1)
                  {
                   
                      int temp = dfs(i,j,row,column,k,grid);
                      area = max(temp,area);
                      k++;
                   
                  }
            }
        }
    
      for(int i = 0 ; i<row;i++)
      {
        for(int j = 0 ; j<column;j++)
        {
          if(grid[i][j]==0)
          {
            unordered_set<int> track;
            int tot =  1;
            if(j-1>=0 && grid[i][j-1]>0)
            {
              string tt = to_string(i)+"+"+to_string(j-1);
              int r  =maap[tt];
              if(track.find(r)==track.end())
              {
                track.insert(r);
                 tot+=grid[i][j-1];  
              }
            }
            if(j+1<column && grid[i][j+1]>0)
            {
              string tt = to_string(i)+"+"+to_string(j+1);
              int r  =maap[tt];
              if(track.find(r)==track.end())
              {
                track.insert(r);
                 tot+=grid[i][j+1];  
              }
            }
             if(i+1<row && grid[i+1][j]>0)
            {
              string tt = to_string(i+1)+"+"+to_string(j);
              int r  =maap[tt];
              if(track.find(r)==track.end())
              {
                track.insert(r);
                 tot+=grid[i+1][j];  
              }
            }
             if(i-1>=0 && grid[i-1][j]>0)
            {
              string tt = to_string(i-1)+"+"+to_string(j);
              int r  =maap[tt];
              if(track.find(r)==track.end())
              {
                track.insert(r);
                 tot+=grid[i-1][j];  
              }
            }
            area = max(area,tot);
          }
        }
      }
      return area;
    }
};
