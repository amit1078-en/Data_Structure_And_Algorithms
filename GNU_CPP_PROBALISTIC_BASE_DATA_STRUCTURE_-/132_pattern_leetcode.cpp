/*
132 pattern 


https://leetcode.com/submissions/detail/547298138/

Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

 

Example 1:

Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.
Example 2:

Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:

Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
 

Constraints:

n == nums.length
1 <= n <= 2 * 105
-109 <= nums[i] <= 109

*/

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> 


class Solution {
public:
    bool find132pattern(vector<int>& nums) 
    {
        int size = nums.size();
        if(size>=3)
        {
          int left[size+1];
          left[0] = INT_MAX;
          int minn = nums[0];
          for(int i = 1 ; i<size  ; i++)
          {
            if(minn>=nums[i])
            {
              left[i] = INT_MAX;  
            }
            else
            {
              left[i] = minn;
            }
            minn = min(minn,nums[i]);
          }
          ordered_set object;
          object.insert(nums[size-1]);
          for(int i = size-2;i>0;i--)
          {
            if(left[i]==INT_MAX)
            {
              object.insert(nums[i]);
              continue;
            }
            int m = object.order_of_key(nums[i]);
            if(m==0)
            {
              object.insert(nums[i]);
              continue;
            }
            int  x = *object.find_by_order(m-1);  
            if(x>left[i])
            {
              return true;
            }
            object.insert(nums[i]);
          }
        }
        return false;
    }
};
