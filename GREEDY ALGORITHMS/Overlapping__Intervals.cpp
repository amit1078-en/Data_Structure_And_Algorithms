/*
Overlapping Intervals

Given a collection of Intervals, the task is to merge all of the overlapping Intervals.

Example 1:

Input:
Intervals = {{1,3},{2,4},{6,8},{9,10}}
Output: {{1, 4}, {6, 8}, {9, 10}}
Explanation: Given intervals: [1,3],[2,4]
[6,8],[9,10], we have only two overlapping
intervals here,[1,3] and [2,4]. Therefore
we will merge these two and return [1,4],
[6,8], [9,10].
Example 2:

Input:
Intervals = {{6,8},{1,9},{2,4},{4,7}}
Output: {{1, 9}}
Your Task:
Complete the function overlappedInterval() that takes the list N intervals as input parameters and returns sorted list of intervals after merging.

Expected Time Complexity: O(N*Log(N)).
Expected Auxiliary Space: O(Log(N)) or O(N).

Constraints:
1 = N = 100
0 = x = y = 1000

*/
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         vector<vector<int>> maap;
         sort(intervals.begin(),intervals.end());
         int start =    intervals[0][0];
         int end   =    intervals[0][1];
         maap.push_back(vector<int>{start,end});
         for(int i = 1;i<intervals.size();i++)
         {
             if(intervals[i][0]>end)
             {
                 maap.push_back(intervals[i]);
                 end = intervals[i][1];
             }
             else
             {
                 vector<int> vc = maap[maap.size()-1];
                 if(intervals[i][1]>vc[1])
                 {
                     vc[1] = intervals[i][1];
                     end = intervals[i][1];
                     maap[maap.size()-1] = vc;
                 }
             }
         }
         return maap;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends
