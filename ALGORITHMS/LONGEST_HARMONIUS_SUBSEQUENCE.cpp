/*
 Longest Harmonious Subsequence

Solution
We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

A subsequence of array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: nums = [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
Example 2:

Input: nums = [1,2,3,4]
Output: 2
Example 3:

Input: nums = [1,1,1,1]
Output: 0
*/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> amit;
        map<int,int> kumar;
        for(int i = 0; i<nums.size();i++)
        {
            amit[nums[i]]++;
            kumar[nums[i]]++;
        }
        int maximum = 0 ;
        int index = 0;
        for(auto i = kumar.begin();i!=kumar.end();i++)
        {
            nums[index] = i->first;
            index++;
        }
        for(int i = 0 ;i<index-1 ;i++)
        {
           if(nums[i+1]-nums[i]==1)
           {
               int temp  = (amit[nums[i]]+amit[nums[i+1]]);
               maximum = max(temp,maximum);
           }
        }
        return maximum;
    }
};
