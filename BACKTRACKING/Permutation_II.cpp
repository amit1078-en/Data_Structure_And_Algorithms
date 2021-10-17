/*
47. Permutations II

Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10
*/

class Solution {
public:
     map<vector<int>, int>  check;
     vector<vector<int>> answer;
    void rec(vector<int> nums,int size,int l)
    {
        for(int i = l;i>=0;i--)
        {
            
            swap(nums[i],nums[l]);
            if(check.find(nums)==check.end())
            {
                 answer.push_back(nums);
                check[nums]+=1;
                rec(nums,size,l);
                
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        answer.clear();
        check.clear();
        sort(nums.begin(),nums.end());
        int size = nums.size();
        rec(nums,size,size-1);
   
        return answer;
    }
};
