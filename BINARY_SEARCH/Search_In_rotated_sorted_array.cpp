/*
Share

link -> https://leetcode.com/submissions/detail/543442267/

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array 
is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 
3 and become [4,5,6,7,0,1,2].

Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is guaranteed to be rotated at some pivot.
-104 <= target <= 104
*/
class Solution {
public:
    
    int search(vector<int>& nums, int target) 
    {
        int size = nums.size();
        if(size<=3)
        {
            for(int i = 0;i<nums.size();i++)
            {
              if(nums[i]==target)
              {
                return i;
              }
            }
          return -1;
        }
      int first = nums[0];
      int last = nums[nums.size()-1];
       int l = 0;
      int r = size-1;
      if(first<last)
      {
        int index =  lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(nums[index]!=target)
        {
          return -1;
        }
        return index;
      }
      if(nums[0]>nums[1])
      {
        if(nums[0]==target)
        {
          return 0;
        }
        l = 1;
        while(l<=r)
        {
             int mid = (l+r)/2;
             if(nums[mid]==target)
             {
               return mid;
             }
            if(nums[mid]>target)
            {
              r = mid-1;        
            }
            else{
               l = mid+1;
       
            }
        }
        
        return -1;
      }
     
      int MID;
      while(l<=r)
      {
        int mid = (l+r)/2;
        
        if(mid==0)
        {
          l = mid+1;
          continue;
        }
        if(mid==size-1)
        {
          r = mid-1;
          continue;
        }
          if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1])
          {
            MID  = mid;
            break;
          }
          
        else if(nums[mid]>nums[0])
        {
              l = mid+1;
        }
        else
        {
              r = mid-1;
        }
      }
      
      l = 0;
      int MIDD = MID;
      while(l<=MIDD)
      {
        int mid =  (l+MIDD)/2;
        if(nums[mid]==target)
        {
          return mid;
        }
        else if(nums[mid]>target)
        {
          MIDD=mid-1;
        }
        else
        {
          l = mid+1;
        }
      }
      MID+=1;
      r = size-1;
      while(MID<=r)
      {
        int mid =  (r+MID)/2;
        if(nums[mid]==target)
        {
          return mid;
        }
        else if(nums[mid]>target)
        {
          r=mid-1;
        }
        else
        {
          MID = mid+1;
        }
      }
      return -1;
    }
};
