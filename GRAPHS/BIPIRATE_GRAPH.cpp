/*

BIPIRATE GRAPH

Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
 

Example 1:

Input: 

Output: 1
Explanation: The given graph can be colored 
in two colors so, it is a bipartite graph.
Example 2:

Input:

Output: 0
Explanation: The given graph cannot be colored 
in two colors such that color of adjacent 
vertices differs. 
 

Your Task:
You don't need to read or print anything. Your task is to complete the function isBipartite() which takes V denoting no. of vertices and adj denoting adjacency list of graph and returns a boolean value true if graph is bipartite otherwise returns false.
 

Expected Time Complexity: O(V)
Expected Space Complexity: O(V)

Constraints:
1 = V, E = 105

Company Tags
Topic Tags
Related Courses
Related Interview Experiences

*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[])
	{
	    bool visited[V];
	    int color[V];
	    memset(color,0,sizeof(color));
	    memset(visited,false,sizeof(visited));
	    for(int i  = 0;i<V;i++)
	    {
	        if(!visited[i])
	        {
	            visited[i] = true;
	            color[i] = 1;
	            queue<int> Q;
	            Q.push(i);
	            while(!Q.empty())
	            {
	                int front = Q.front();
	                visited[front] = true;
	                Q.pop();
	                for(int k:adj[front])
	                {
	                    if(!visited[k])
	                    {
	                        Q.push(k);
	                        if(color[k]==0)
	                        {
	                            if(color[front]==1)
	                            {
	                                color[k] = 2; 
	                            }
	                            else
	                            {
	                                 color[k] = 1; 
	                            }
	                        }
	                        else
	                        {
	                            if(color[front]==color[k])
	                            {
	                                return false;
	                            }
	                        }
	                    }
	                    else
	                    {
	                         if(color[front]==color[k])
	                            {
	                                return false;
	                            }
	                    }
	                    visited[k] = true;
	                }
	            }
	        }
	    }
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  /
