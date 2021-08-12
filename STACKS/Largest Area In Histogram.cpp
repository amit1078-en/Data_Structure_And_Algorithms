/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104
Accepted
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& H) {
      int answer = 0;
      int l[H.size()];
      int r[H.size()];
      
      stack<int> S;
      r[H.size()-1] = H.size();
      S.push(H.size()-1);
      for(int i = H.size()-2 ; i>=0;i--)
      {
        while(!S.empty() && H[S.top()]>=H[i])
        {
          S.pop();
        }
        if(S.empty())
        {
            r[i] = H.size();
        }
        else
        {
            r[i] = S.top();
        }
        S.push(i);
      }
      
      while(!S.empty()){
        S.pop();
      }
      
      
      l[0] = -1;
      S.push(0);
      for(int i = 1 ; i<H.size();i++)
      {
        while(!S.empty() && H[S.top()]>=H[i])
        {
          S.pop();
        }
        if(S.empty())
        {
            l[i] = -1;
        }
        else
        {
            l[i] = S.top();
        }
        S.push(i);
      }

      for(int i = 0 ; i<H.size();i++)
      {
        answer = max(answer,(H[i]*(r[i]-l[i]-1)));
      }
      return answer;
    }
};
