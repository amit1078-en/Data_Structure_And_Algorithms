/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104

code 
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(intervals[0][0]);temp.push_back(intervals[0][1]);
        ans.push_back(temp);
        for(int i = 0 ; i<intervals.size();i++)
        {
            vector<int> prev;
            prev = ans[ans.size()-1];
            int x = prev[0];
            int y = prev[1];
            
            if(y>=intervals[i][0])
            {
               if(y>=intervals[i][1])
               {
                    ans[ans.size()-1][1] = y;
               }
                else
                {
                     ans[ans.size()-1][1] = intervals[i][1];
                }
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
