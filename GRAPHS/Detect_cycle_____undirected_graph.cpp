#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isCycle(int V, vector<int>adj[]){
	   queue<int> arrs;
	   int arr[V];
	   memset(arr,-1,sizeof(V));
	   int qw = 0;
	   for(int i = 0 ; i<V;i++)
	   {
	       for(int x:adj[i])
	       {
	           qw = i;
	           i=V;
	           break;
	       
	       }
	   }
	   arrs.push(qw);
	   arr[qw] = 1;
	   while(arrs.empty()==false)
	   {
	       //USING DFS ALGO TO FIND CYCLE IN UNDIRECTED GRAPH
	       int tp  = arrs.front();
	       for( auto x:adj[tp])
	       {
	           int d1 = x;
	           if(arr[d1]==0 )
	           {
	               return true;
	           }
	          if(arr[d1]==-1)
	           {
	               arrs.push(d1);
	               arr[d1] =1;
	           }
	            
	       }
	           arrs.pop();
	           arr[tp] =0;
	   }
	   return false;
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
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
