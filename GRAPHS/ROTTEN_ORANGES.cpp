/*
Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
 

Example 1:

Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
Output: 1
Explanation: The grid is-
0 1 2
0 1 2
2 1 1
Oranges at positions (0,2), (1,2), (2,0)
will rot oranges at (0,1), (1,1), (2,2) and 
(2,1) in unit time.
Example 2:

Input: grid = {{2,2,0,1}}
Output: -1
Explanation: The grid is-
2 2 0 1
Oranges at (0,0) and (0,1) can't rot orange at
(0,3).
 

Your Task:
You don't need to read or print anything, Your task is to complete the function orangesRotting() which takes grid as input parameter and returns the minimum time to rot all the fresh oranges. If not possible returns -1.
 

Expected Time Compelxity: O(n*m)
Expected Auxiliary Space: O(1)
 

Constraints:
1 = n, m = 500

Company Tags
Topic Tags
Related Courses
Related Interview Experiences

*/
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int num = 1;
        vector<int> answer[(grid.size()*grid[0].size() )+ 1];
        vector<int> track;
        int  check[(grid.size()*grid[0].size() )+ 1];
        for(int i = 0 ;  i<(grid.size()*grid[0].size() )+ 1;i++)
        {
            check[i] = -9;
        }
        for(int i = 0; i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    track.push_back(num);
                    check[num] = -2;
                }
                if(grid[i][j]==1)
                {
                    check[num] = 99999999;
                }
                if(grid[i][j]==1 || grid[i][j]==2)
                {
                    if(i!=0 )
                    {
                        if(grid[i-1][j]==1 || grid[i-1][j]==2)
                        {
                              answer[num].push_back(num-grid[0].size());
                        }
                          
                    }
                    if(i+1!=grid.size() )
                    {
                        if(grid[i+1][j]==1 || grid[i+1][j]==2)
                            answer[num].push_back(num+grid[0].size());
                    }
                    if(j!=0 )
                    {
                        if(grid[i][j-1]==1 || grid[i][j-1]==2)
                            answer[num].push_back(num-1);
                    }
                    if(j+1!=grid[0].size() )
                    {
                        if(grid[i][j+1]==1 || grid[i][j+1]==2)
                            answer[num].push_back(num+1);
                    }
                }
                num++;
            }
        }
        queue<pair<int,int>> Q;
        for(auto two:track)
        {
            int f = two;
            Q.push({f,0});
            while(Q.empty()!=true)
            {
                int c = Q.front().second;
                int r = Q.front().first;
                for(auto  x: answer[r])
                {
                    if(check[x]!=-9 && check[x]!=-2)
                    {
                        if(check[x]>c)
                        {
                            check[x] = c+1;
                            Q.push({x,c+1});
                        }
                    }
                }
                Q.pop();
            }
        }
         int p = grid.size()*grid[0].size();
        int ans = INT_MIN;
       
        for(int  i = 1 ; i<=p;i++)
        {
            if(check[i]==99999999)
           {
                return -1;
           }
            
            if(check[i]!=-9 && check[i]!=-2)
            {
                if(ans<check[i])
                {
                    ans = check[i];
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
} 
