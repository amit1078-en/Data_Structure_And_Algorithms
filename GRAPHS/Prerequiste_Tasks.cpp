/*

There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.


Example 1:

Input: 
N = 4, P = 3
prerequisites = {{1,0},{2,1},{3,2}}
Output:
Yes
Explanation:
To do task 1 you should have completed
task 0, and to do task 2 you should 
have finished task 1, and to do task 3 you 
should have finished task 2. So it is possible.
Example 2:

Input:
N = 2, P = 2
prerequisites = {{1,0},{0,1}}
Output:
No
Explanation:
To do task 1 you should have completed
task 0, and to do task 0 you should
have finished task 1. So it is impossible.

Your task:
You don’t need to read input or print anything. Your task is to complete the function isPossible() which takes the integer N denoting the number of tasks, P denoting the number of prerequisite pairs and prerequisite as input parameters and returns true if it is possible to finish all tasks otherwise returns false. 


Expected Time Complexity: O(N + P)
Expected Auxiliary Space: O(N + P)


Constraints:
1 = N = 104
1 = P = 105

*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<int> graph[N];
	   // graph formation using adjancje list
	    for(int i = 0 ; i<prerequisites.size();i++)
	    {
	        graph[ prerequisites[i].second].push_back( prerequisites[i].first);
	    }
	    
	   // now we have to detect if there exist any cycle in the graph or not
	    bool traverse[N];
	    bool cycle[N];
	    
	    for(int i = 0 ; i<N;i++)
	    {
	        traverse[i] =  false;
	        cycle[i] = false;
	    }
	    
	    for(int i  = 0 ; i<N;i++)
	    {
	            if(traverse[i]==false)
	            {
	                stack<int> ans;
	                ans.push(i);
	                while(!ans.empty())
	               {
	                   int l = ans.top();
	                    bool help = true;
	                     traverse[l] = true;
	                     cycle[l] =  true;
	                   for(int j:graph[l])
	                    {
	                        if(traverse[j]==false && cycle[j]==false)
	                        {
	                            help = false;
	                                 traverse[j] =  true;
                                        cycle[j] = true;
	                            ans.push(j);
	                            break;
	                        }
	                        else if(cycle[j])
	                        {
	                            return false;
	                        }
	                    }
	                    if(help)
	                    {
	                        cycle[l] =false;
	                        ans.pop();
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
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends
