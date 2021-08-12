/*
LeetCode 
525. Contiguous Array 

Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
*/

class Solution {
public:
//	approach
// we have to calculate the answer such That we maximum suubarray with equal number of 0 and 1 
//algorithm
//step 1 -> declare the unordered_map and do maap[0] = -1 initailly
//step 2 -> traverse vector and if we encounter 0 we will do count-- and for 1 we will do count++
//step 3 -> check if count exist in map if it exist then do and = max(ans,i-maaap[count])
//step 4 -> if it doesn't exist then simply insert in maap




    int findMaxLength(vector<int>& nums) {
//    taking answer varaible for storing the answer
     int ans = 0 ;
      unordered_map<int,int> maaap;
      
      int t = 0;
      maaap[0] = -1;
      for(int i = 0 ; i<nums.size();i++)
      {
        if(nums[i]==0)
        {
          t-=1;
        }
        else
        {
          t+=1;
        }
        
        if(maaap.find(t)==maaap.end())
        {
          maaap[t] = i;
        }
        else
        {
          ans = max(ans,i-maaap[t]);
        }
      }
      return ans;
    }
};

