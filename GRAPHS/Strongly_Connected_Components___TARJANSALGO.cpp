/*
Given a Directed Graph with V vertices and E edges, Find the members of strongly connected components in the graph.


Example 1:

Input:

Output:
0 1 2,3,4,
Explanation:

We can clearly see that there are 3 Strongly
Connected Components in the Graph as mentioned
in the Output.
Example 2:

Input:

Output:
0 1 2,
Explanation:
All of the nodes are connected to each other.
So, there's only one SCC as shown.

Your Task:
You don't need to read input or print anything. Your task is to complete the function tarjans() which takes the number of vertices V and
 adjacency list of the graph as input parameters and returns a list of list of integers denoting the members of strongly connected components 
 in the given graph.
 
 
Note: A single strongly connected component must be represented in the form of a list if integers sorted in the ascending order.
 The resulting list should consist of a list of all SCCs which must be sorted in a way such that a lexicographically smaller list of integers 
 appears first.


Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).


Constraints:
1 = V  = 105
1 = E  = 105
0 = u, v = N-1

*/

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class node{
    public:
    int first;
    int second;
};
class Solution
{
	public:
	
	bool track[100001];
	int len = 0;
	 vector<vector<int>> help;
	 
	void dfs(int t,vector<int> adj[], node obj[],stack<int> &st)
	{
	    track[t] = true;
	    len+=1;
	    st.push(t);
	    obj[t].first = len;
	    obj[t].second = len;
	    for(int i :adj[t])
	    {
	        if(track[i] )
	        {
	            obj[t].first = min(obj[i].second,obj[t].first);
	        }
	        else if(obj[i].second==INT_MAX){
	           dfs(i,adj,obj,st);
	           obj[t].first = min(obj[i].first,obj[t].first);
	        }
	    }
	    if(obj[t].first==obj[t].second)
	   {
	       vector<int> tempp;
	       
	       while(st.top()!=t)
	       {
	           tempp.push_back(st.top());
	           track[st.top()] = false;
	           st.pop();
	       }
	       if(track[st.top()])
	       {
	           track[t]=false;
	           tempp.push_back(st.top());
	       }
	       st.pop();
	       sort(tempp.begin(),tempp.end());
	       help.push_back(tempp);
	   }
	}
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
       help.clear();
        node obj[V+1];
        for(int i = 0 ; i<V;i++)
        {
            obj[i].first=INT_MAX;
            obj[i].second = INT_MAX;
            track[i] = false;
        }
        len = -1;
        stack<int> st;
        for(int i = 0 ; i<V;i++)
        {
            if(obj[i].first==INT_MAX)
            {
                dfs(i,adj,obj,st);
            }
        }
        sort(help.begin(),help.end());
        return help;
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
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}

