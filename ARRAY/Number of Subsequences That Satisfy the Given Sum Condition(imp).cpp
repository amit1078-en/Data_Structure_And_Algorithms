/*
Given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [3,5,6,7], target = 9
Output: 4
Explanation: There are 4 subsequences that satisfy the condition.
[3] -> Min value + max value <= target (3 + 3 <= 9)
[3,5] -> (3 + 5 <= 9)
[3,5,6] -> (3 + 6 <= 9)
[3,6] -> (3 + 6 <= 9)
Example 2:

Input: nums = [3,3,6,8], target = 10
Output: 6
Explanation: There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
[3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]
Example 3:

Input: nums = [2,3,3,4,6,7], target = 12
Output: 61
Explanation: There are 63 non-empty subsequences, two of them don't satisfy the condition ([6,7], [7]).
Number of valid subsequences (63 - 2 = 61).
Example 4:

Input: nums = [5,2,4,1,7,6,8], target = 16
Output: 127
Explanation: All non-empty subset satisfy the condition (2^7 - 1) = 127
*/'
int mod = 1000000007;
    vector<int> answer;
bool ty=false;
class Solution {
public:
    
    Solution()
    {
        if(!ty)
        {
            answer.push_back(1);
        long long int as  = 1;
        for(int i = 1;  i<1000001;i++)
        {
            as = (as*2)%mod;
            answer.push_back(as);
        }
            ty  = true;
        }
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int start = 0;
        int end = nums.size()-1;
        int ans = 0;
        for(int i = 0 ; i<nums.size();i++)
        {
           while(start<=end)
           {
                if(nums[start]+nums[end]<=target )
                {
                    int  x = end-start;
                    int p = answer[x];
                    ans = ((ans%mod)+p)%mod;
                    start++;
                    break;
                }
               else
               {
                   end--;
               }
           }
        }
        return ans;
    }
};
