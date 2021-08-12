// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int coloumn = grid[0].size();
        vector<int> track;
        vector<int> arr[row*coloumn];
        int num = 0;
        bool check[row*coloumn];
        bool lk[row][coloumn];
        for(int i = 0 ; i<row ;i++)
        {
            for(int j  = 0 ; j<coloumn ;j++)
            {
                 check[i] = false;
                if(grid[i][j]=='1')
                {
                    track.push_back(num);
                    if(j-1>=0)
                    {
                        //left case
                        if(grid[i][j-1]=='1')
                        arr[num].push_back(num-1);
                        lk[i][j-1]==true;
                    }
                    if(j+1<coloumn)
                    {
                        if(grid[i][j+1]=='1')
                        arr[num].push_back(num+1);
                        lk[i][j+1]==true;
                    }
                    if(i+1<row)
                    {
                        //bottom case
                        if(grid[i+1][j]=='1')
                        arr[num].push_back(num+coloumn);
                        lk[i+1][j]==true;
                    }
                    if(i-1>=0)
                    {
                        //top
                        if(grid[i-1][j]=='1')
                        arr[num].push_back(num-coloumn);
                        lk[i-1][j]==true;
                    }
                    if(j-1>=0 && i-1>=0)
                    {
                        //top left case
                        if(grid[i-1][j-1]=='1')
                        arr[num].push_back(num-coloumn-1);
                        lk[i-1][j-1]==true;
                    }
                    if(j+1<coloumn && i-1>=0)
                    {
                        //top right case
                        if(grid[i-1][j+1]=='1')
                        arr[num].push_back(num-coloumn+1);
                        lk[i-1][j+1]==true;
                    }
                    if(j-1>=0 && i+1<row)
                    {
                        
                        //bottom left case
                        if(grid[i+1][j-1]=='1')
                        arr[num].push_back(num+coloumn-1);
                        lk[i+1][j-1]==true;
                    }
                    if(j+1<coloumn && i+1<row)
                    {
                        //bottom left case
                        if(grid[i+1][j+1]=='1')
                        arr[num].push_back(num+coloumn+1);
                        lk[i-1][j+1]==true;
                    }
                }
                num++;
            }
        }
        
        int ans = 0;
       
        for(int i = 0;i<track.size();i++)
        {
            if(check[track[i]]==false)
            {
                ans++;
                //cout<<track<<" ";
                queue<int> bfs;
                bfs.push(track[i]);
                while(bfs.empty()==false)
                {
                    
                    int f = bfs.front();
                   
                    for(auto x : arr[f])
                    {
                        if(check[x]==false)
                        {
                            check[x] = true;
                            bfs.push(x);
                        }
                    }
                     check[f] = true;
                    bfs.pop();
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
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends
