/*
31. Next Permutation
Medium

6402

2121

Add to List

Share
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
Example 4:

Input: nums = [1]
Output: [1]
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100
*/


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if(size!=1)
        {
          bool b = false;
          for(int i = size-1;i>0;i--)
          {
            if(nums[i]<=nums[i-1])
            {
              continue;
            }
            b= true;
            int pos = i-1;
            for(int k = size-1;k>=i;k--)
            {
              if(nums[k]>nums[pos])
              {
                swap(nums[k],nums[pos]);
                break;
              }
            }
            reverse(nums.begin()+i,nums.end());
            break;
          }
          if(!b)
          {
             reverse(nums.begin(),nums.end());
          }
        }
    }
};
