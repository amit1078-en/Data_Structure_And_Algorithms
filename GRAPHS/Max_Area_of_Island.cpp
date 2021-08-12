/*
NAME ->   AMIT KUMAR

TOPIC -> Max Area of Island

ALGORITHM USED -> GRAPHS,BFS,2D ARRAY

You are given an m x n binary matrix grid. 
An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.
The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid. If there is no island, return 0.

 
Example 1:
Input: 
grid = [	[0,0,1,0,0,0,0,1,0,0,0,0,0],
			[0,0,0,0,0,0,0,1,1,1,0,0,0],
			[0,1,1,0,1,0,0,0,0,0,0,0,0],
			[0,1,0,0,1,1,0,0,1,0,1,0,0],
			[0,1,0,0,1,1,0,0,1,1,1,0,0],
			[0,0,0,0,0,0,0,0,0,0,1,0,0],
			[0,0,0,0,0,0,0,1,1,1,0,0,0],
			[0,0,0,0,0,0,0,1,1,0,0,0,0]]
			
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
Example 2:
Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.
*/

class Solution {
public:
    int bfs(int r,int c,vector<vector<int>>& grid,int i,int j)
    {
        queue<pair<int,int>> Q;
        Q.push({i,j});
        int t = 0;
        while(!Q.empty()){
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            grid[x][y] = 0;
            
            //up
            if(x!=0)
            {
                if(grid[x-1][y]==1)
                {Q.push({x-1,y});grid[x-1][y] = 0;}
            }
            
            //down
            if(x+1!=r)
            {
                if(grid[x+1][y]==1)
                {Q.push({x+1,y});grid[x+1][y] = 0;}
            }
            
            //left
            if(y!=0){
                if(grid[x][y-1]==1)
                {Q.push({x,y-1});grid[x][y-1] = 0;}
            }
            
            //right
            if(y+1!=c)
            {
                if(grid[x][y+1]==1){
                    grid[x][y+1] = 0;
                 Q.push({x,y+1});   
                }
                
            }
            t++;
        }
        return t;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
     int ans = 0;
     int r = grid.size();
     int c = grid[0].size();
    for(int i =  0      ;i<r    ;i++)
    {
        for(int j =  0 ;    j<c     ;j++)
        {
            if(grid[i][j]==1)
            {
                ans = max(ans,bfs(r,c,grid,i,j));
            }
        }
    }
     return ans;
    }
};


