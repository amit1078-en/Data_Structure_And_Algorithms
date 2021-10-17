/*
334. Increasing Triplet Subsequence

Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

 

Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
Example 2:

Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
Example 3:

Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
 

Constraints:

1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you implement a solution that runs in O(n) time complexity and O(1) space complexity?
*/

class Solution 
{
public:
    bool increasingTriplet(vector<int>& nums) 
    {
         if(nums.size()>=3)
         {
                int right[nums.size()];
                int  left[nums.size()];
            
                right[nums.size()-1] = nums.size();
                stack<int> rt;
                rt.push(nums.size()-1);
                for(int i = nums.size()-2;i>=0;i--)
                {
                    while(!rt.empty() && nums[rt.top()]<=nums[i])
                    {
                        rt.pop();
                    }
                    if(rt.empty())
                    {
                        right[i] = INT_MAX;
                    }
                    else
                    {
                        right[i] = i;
                    }
                    rt.push(i);
                }
             
                left[0] = 0;
                while(!rt.empty())
                {
                    rt.pop();
                }
                rt.push(0);
                for(int i = 1; i<nums.size();i++)
                {
                    while(!rt.empty() && nums[rt.top()]>=nums[i])
                    {
                        rt.pop();
                    }
                    if(rt.empty())
                    {
                        left[i] = 0;
                    }
                    else
                    {
                        left[i] = i;
                    }
                    rt.push(i);
                }
                 for(int i =1;i<nums.size()-1;i++)
                 {
                    if(left[i]!=0 && right[i]!=INT_MAX)
                    {
                        return true;
                    }
                 }
         }
         return false;   
    }
};
