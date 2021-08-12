/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.


Example 1:

Input:



Output: 1
Explanation: 3 -> 3 is a cycle

Example 2:

Input:


Output: 0
Explanation: no cycle in the graph

Your task:
You don’t need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.


Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)


Constraints:
1 = V, E = 105
*/
#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
	bool isCyclic(int V, vector<int> adj[]) 
	{
	    bool track[V];
	    memset(track,false,sizeof(track));
	     bool temp[V];
	   	        memset(temp,false,sizeof(temp));
	   	for(int i = 0 ;  i<V;i++)
	   	{
	   	    if(track[i]==false)
	   	    {
	   	        stack<int> S;
	   	        S.push(i);
	   	        while(!S.empty()){
                     int top = S.top();
                     track[top] = true;
                     temp[top] = true;
                     bool help = true;
                     for(int j:adj[top]){
                        if(track[j]==false && temp[j]==false)
                        {
                            track[j] = true;
                            temp[j] = true;
                            S.push(j);
                            help = false;
                            break;
                        }
                        else if(temp[j])return true;
                     }
                    if(help){
                        temp[top] = false;
                        S.pop();
                    }
	   	        }
	   	    }
	   	}
	   	return false;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

