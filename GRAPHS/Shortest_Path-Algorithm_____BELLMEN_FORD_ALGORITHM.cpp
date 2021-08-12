/*

You don't need to read or print anyhting. Your task is to complete the function isNegativeWeightCycle() which takes n and edges as
 input paramater and returns 1 if graph contains negative weight cycle otherwise returns 0.
 

Expected Time Complexity: O(n*m)
Expected Space Compelxity: O(n)
 

Constraints:
1 <= n <= 100
1 <= m <= n*(n-1), where m is the total number of Edges in the
*/
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    int arr[n+1];
	    for(int i = 0 ; i<n;i++)
	    {
	        arr[i] = 10000007;
	    }
	   
	    int temp = n-1;
	     arr[0] = 0;
	    while(temp--)
	    {
	        for(auto i:edges)
	        {
	            int u = i[0];
	            int v = i[1];
	            int val = i[2];
	            int weight = val + arr[u];
	            if(arr[v]>weight)
	            {
	                arr[v] = weight;
	            }
	        }
	    }
	    for(auto i:edges)
	        {
	            int u = i[0];
	            int v = i[1];
	            int val = i[2];
	            int weight = val + arr[u];
	            
	            
	            if(arr[v]>weight)
	            {
	                return true;
	                arr[v] = weight;
	            }
	        }
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
