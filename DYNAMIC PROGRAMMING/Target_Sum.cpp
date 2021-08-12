/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1
 

Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000
Accepted
254.3K
Submissions
558.7K
Seen this question in a real interview before?

Yes

No


*/

//memonised code
class Solution {
public:
    int ans =  0;
    int dp[2001][21];
    int getsum(vector<int>& nums,int l,int r,long long sum,int target)
    {
        if(r==l)
        {
            if(target==sum)
            {
                return 1;
            }
            return 0;
        }

    if(dp[sum+1000][l]!=-1){
        return dp[sum+1000][l];
        }  
      
        return dp[sum+1000][l] = getsum(nums,l+1,r,sum+nums[l],target)   +   getsum(nums,l+1,r,sum+(nums[l]*-1),target);
      
    }
    int findTargetSumWays(vector<int>& nums, int target) {
      memset(dp,-1,sizeof(dp));
        long long temp = 0;
        return getsum(nums,0,nums.size(),0,target);
    }
};

//recursive code
class Solution {
public:
    int ans =  0;
    void getsum(vector<int>& nums,int l,int r,long long sum,int target)
    {
        if(r==l)
        {
            if(sum==target)
            {
                ans++;
            }
            return ;
        }
        getsum(nums,l+1,r,sum+(nums[l]*1),target);
        getsum(nums,l+1,r,sum+(nums[l]*(-1)),target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        ans = 0;
        long long temp = 0;
        getsum(nums,0,nums.size(),temp,target);
        return ans;
    }
};
