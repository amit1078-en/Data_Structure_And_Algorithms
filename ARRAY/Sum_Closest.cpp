/*
3Sum Closest

Solution
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 

Constraints:

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = -1000000009;
        sort(nums.begin(),nums.end());
        int size = nums.size();
        for(int i = 0 ; i<size-2;i++)
        {
          int l  = i+1;
          int r = nums.size()-1;
          while(l<r)
          {
            int sum = nums[i]+nums[l]+nums[r];
            if(abs(sum-target)<abs(ans-target))
            {
              ans = sum;
            }
            if(sum<=target)
            {
              l++;
            }
            else
            {
              r--;
            }
          }
        }
      return ans;
    }
};
