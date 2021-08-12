/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
Example 3:

Input: intervals = [], newInterval = [5,7]
Output: [[5,7]]
Example 4:

Input: intervals = [[1,5]], newInterval = [2,3]
Output: [[1,5]]
Example 5:

Input: intervals = [[1,5]], newInterval = [2,7]
Output: [[1,7]]
 

Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= intervals[i][0] <= intervals[i][1] <= 105
intervals is sorted by intervals[i][0] in ascending order.
newInterval.length == 2
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      if(intervals.empty())
      {
        intervals.push_back(newInterval);
        return intervals;
      }
      int start = newInterval[0];
      int end =   newInterval[1];
      int size = intervals.size();
      
      int start_index =  0;
      int end_index =     0; 
      for(int i = 0 ; i<size;i++)
      {
        if(intervals[i][0]<=start)
        {
          start_index = i;
        }
        if(intervals[i][0]<=end)
        {
          end_index = i;
        }
      }
      vector<vector<int>> help;
      for(int i = 0 ;i<intervals.size();i++)
      {
        if(i==start_index)
        {
          if(end<intervals[i][0])
          {
            help.push_back(newInterval);
            help.push_back(intervals[i]);
          }
          else if(start<=intervals[i][1])
          {
            vector<int> hg;
            hg.push_back(min(intervals[i][0],start));
            i = end_index;
            hg.push_back(max(intervals[end_index][1],end));
             help.push_back(hg);
          }
          else
          {
            help.push_back(intervals[i]);
            newInterval.clear();
            newInterval.push_back(start);
            newInterval.push_back(max(end,intervals[end_index][1]));
            i = end_index;
             help.push_back(newInterval);
          }
        }
        else
        {
   
           help.push_back(intervals[i]);
        }
      }
      return help;
    }
};
