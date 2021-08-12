// CYCLE DETETCTION IN DIRECTED GRAPH
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool isCyclic(int V, vector<int> adj[]) {
	   bool track[V];
	   for(int i = 0 ; i<V;i++)
	   {
	   	track[i] = false;
	   }
	   for(int i = 0 ;i<V;i++)
	   {
	   			if(track[i]==false)
	   			{
	   				track[i] = true;
	   				stack<int> arr;
	   				arr.push(i);
	   				int temp[V];
	   				memset(temp,-1,sizeof(temp));
	   				temp[i] = 0;
					while(arr.empty()==false)
	   				{
	   					int t = arr.top();
	   					track[t] = true;
	   					bool visited = false;
	   					for(auto x:adj[t])
	   					{
	   						if(temp[x]==0)
	   						{
	   							return true;
							}
							if(temp[x]==-1 && track[x]==false)
							{
							    track[x] = true;
							    visited = true;
								arr.push(x);
								temp[x] = 0;
								break;
							}
						}
	   					if(visited==false)
	   					{
	   						temp[t] = 1;
	   						arr.pop();
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
