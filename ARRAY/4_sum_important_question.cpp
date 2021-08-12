/*
Leetcode 
4 sum

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109

*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int size = nums.size();
      
        if(size<4)return ans;
        int i = 0;
        while(i<size-3)
        {
          int j = i+1;
          while(j<size-2)
          {
            int temp = nums[i]+nums[j];
            int k = j+1;
            int l = size-1;
            while(k<l)
            {
              int  req = nums[k]+nums[l];
              if(temp+req==target)
              {
                vector<int> help;
                help.push_back(nums[i]);
                help.push_back(nums[j]);
                help.push_back(nums[k]);
                help.push_back(nums[l]);
                
                ans.push_back(help);
                
                int t1 = k;
                while(k<l && nums[t1]==nums[k])k++;
                
                t1 = l;
                while(k<l && nums[t1]==nums[l])l--;
                
              }
              else if(temp+req<target)
              {
                k++;
              }
              else
              {
                l--;
              }
            }
            int p = j;
            
            while(j<size-2 && nums[j]==nums[p])j++;
          }
          int p = i;
          while(i<size-3 && nums[p]==nums[i])i++;
        }
        return ans;
    }
};

//approach 
//step 1 sort the array
//step 2 then use two loops
//step 3 then use two pointer technique for finding other two index

