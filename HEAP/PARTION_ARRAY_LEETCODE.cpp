/*
  Partition Array into Disjoint Intervals

Solution
Given an array nums, partition it into two (contiguous) subarrays left and right so that:

Every element in left is less than or equal to every element in right.
left and right are non-empty.
left has the smallest possible size.
Return the length of left after such a partitioning.  It is guaranteed that such a partitioning exists.

 

Example 1:

Input: nums = [5,0,3,8,6]
Output: 3
Explanation: left = [5,0,3], right = [8,6]
Example 2:

Input: nums = [1,1,1,0,6,12]
Output: 4
Explanation: left = [1,1,1,0], right = [6,12]
 

Note:

2 <= nums.length <= 30000
0 <= nums[i] <= 106
It is guaranteed there is at least one 
*/

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
        for(int i = 0;i<nums.size();i++){
          Q.push({nums[i],i});
        }
      int ans = nums[0];
      for(int i = 0 ; i<nums.size();i++)
      {
       
        if(Q.top().first>=ans && i!=0)
        {
          return i;
        }
        if(Q.top().second<=i)
        {
          while(!Q.empty() && Q.top().second<=i)
          {
            Q.pop();
          }
        }
          ans  =max(ans,nums[i]);
      }
      return 0;
    }
};
