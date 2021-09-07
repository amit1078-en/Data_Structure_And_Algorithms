/*
DIJAKSTRA ALGORITHM



Given a weighted, undirected and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
Note: The Graph doesn't contain any negative weight cycle.

Example 1:

Input:

S = 0
Output:
0 9
Explanation:
The source vertex is 0. Hence, the shortest distance
of node 0 is 0 and the shortest distance from node 9
is 9 - 0 = 9.
Example 2:

Input:

S = 2
Output:
4 3 0
Explanation:
For nodes 2 to 0, we can follow the path-
2-1-0. This has a distance of 1+3 = 4,
whereas the path 2-0 has a distance of 6. So,
the Shortest path from 2 to 0 is 4.
The other distances are pretty straight-forward.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function dijkstra()  which takes number of vertices V and an adjacency list adj as input parameters and returns a list of integers, where ith integer denotes the shortest distance of the ith node from Source node. Here adj[i] contains a list of lists containing two integers where the first integer j denotes that there is an edge between i and j and second integer w denotes that the weight between edge i and j is w.

 

Expected Time Complexity: O(V2).
Expected Auxiliary Space: O(V2).

 

Constraints:
1 = V = 1000
0 = adj[i][j] = 1000
0 = S < V

*/

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> ans;
        for(int i = 0 ; i<V;i++)
        {
            ans.push_back(INT_MAX);
        }
        bool visited[V];
        memset(visited,false,sizeof(visited));
        ans[S] = 0;
        int n = V;
        while(n--)
        {
              int minn=INT_MAX;
              int x ;
              for(int i = 0 ; i<V;i++)
              {
                  if(!visited[i])
                  {
                      if(minn>ans[i])
                      {
                          minn = ans[i];
                          x = i;
                      }
                  }
              }
              visited[x] = true;
              int s = adj[x].size();
              int k = 0;
              while(k<s)
              {
                  int f =adj[x][k][0];
                  if(!visited[f])
                  {
                      ans[f] = min(ans[f],minn+adj[x][k][1]);
                  }
                  k++;
              }
        }
        return ans;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}
