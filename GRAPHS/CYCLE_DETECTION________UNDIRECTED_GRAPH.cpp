//			CYCLE DETECTION IN UNDIRECTED GRAPH
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool isCycle(int V, vector<int>adj[])
	{
	    bool track[V];
	    for(int i  = 0 ; i < V;i++)
	    {
	        track[i] = false;
	    }
	   for(int i = 0 ;  i<V;i++)
	   {
	       if(track[i]==false)
	       {
	           track[i] = true;
	           queue<int> arr;
	           int check[V];
	           arr.push(i);
	           for(int i = 0 ;  i <V;i++)
	           {
	               check[i] = -1;
	           }
	           while(arr.empty()==false)
	           {
	               int top =arr.front();
	               check[top] = 1;
	               for(auto x:adj[top])
	               {
	                   if(check[x]==0 && track[x]==true)
	                   {
	                       return true;
	                   }
	                   if(check[x]==-1)
	                   {
	                       arr.push(x);
	                       track[x]=true;
	                       check[x] = 0;
	                   }
	               }
	                check[top] = 1;
	               arr.pop();
	           }
	       }
	   }
		return false;
    }
};
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
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
} 
