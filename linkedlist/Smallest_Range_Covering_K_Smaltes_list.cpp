/*
Hard

1660

28

Add to List

Share
You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 

Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]
Example 3:

Input: nums = [[10,10],[11,11]]
Output: [10,11]
Example 4:

Input: nums = [[10],[11]]
Output: [10,11]
Example 5:

Input: nums = [[1],[2],[3],[4],[5],[6],[7]]
Output: [1,7]
 

Constraints:

nums.length == k
1 <= k <= 3500
1 <= nums[i].length <= 50
-105 <= nums[i][j] <= 105
nums[i] is sorted in non-decreasing order.
*/

class ok
{
  public:
    int v;
    int i;
    int r;
    ok(int vv,int ii,int rr)
    {
        v=vv;
        i = ii;
        r  = rr;
    }
};
struct compare
{
    bool operator()(ok a,ok b){
        return a.v>b.v;
    }
};
class Solution {
public:
    
    vector<int> smallestRange(vector<vector<int>>& nums) 
    {
     vector<int> answer;
     int high = INT_MAX;
     int low  = 0;
    priority_queue<ok,vector<ok>,compare> q;
    int maxx = INT_MIN;
    for(int i = 0 ; i<nums.size();i++)
    {
        maxx = max(maxx,nums[i][0]);
        q.push(ok(nums[i][0],0,i));
    }
     while(!q.empty())
     {
         ok top = q.top();
         q.pop();
         if(high-low>maxx-top.v)
         {
             high = maxx;
             low = top.v;
         }
         if(top.i+1==nums[top.r].size())
         {
             break;
         }
        q.push(ok(nums[top.r][top.i+1],top.i+1,top.r));
         maxx = max(nums[top.r][top.i +1],maxx);
     }
        answer.push_back(low);
        answer.push_back(high);
     return answer;
    }
};
