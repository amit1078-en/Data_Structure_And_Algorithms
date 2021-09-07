/*
link -> https://leetcode.com/problems/daily-temperatures/

Share
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
 

Constraints:

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100

*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        int size = temperatures.size();
        stack<int> stack;
        stack.push(size-1);
        int nge[size];
        nge[size-1] = size;
        for(int i = size-2;i>=0;i--)
        {
          while(!stack.empty() && temperatures[stack.top()]<=temperatures[i])
          {
            stack.pop();
          }
          if(stack.empty())
          {
            nge[i] = size;
          }
          else
          {
            nge[i] = stack.top();
          }
          stack.push(i);
        }
      for(int i = 0 ; i<size;i++)
      {
        temperatures[i] = nge[i]-i;
        if(nge[i]==size)
        {
          temperatures[i] = 0;
        }
      }
      return temperatures;
    }
};

