/*
Maximum Erasure Value
Solution
You are given an array of positive integers nums and want to erase a subarray containing unique elements. 
The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, 
if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].

*/
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int   check[100001];
        for(int i = 0 ; i<10001;i++){
            check[i] = -1;
        }
        int ans = nums[0];
        check[nums[0]] = 0;
        int l = 0 ; 
        int r = 0;
        int temp = ans;
        ans = nums[0];
        check[nums[0]] = 0;
        l = 0;
        for(int i =1;i<nums.size();i++){
            nums[i]+=nums[i-1];
            int ele = nums[i]-nums[i-1];
            if(check[ele]==-1)
            { 
                temp+=ele;
                check[ele] = i;
            }
            else if(check[ele]>=l)
            {
                int past = check[ele];
                ans = max(ans,temp);
                temp = nums[i]-(nums[past]);
                check[ele] = i;
                l = past;
            }
            else if(check[ele]<l)
            {
                temp+=ele;
                check[ele] = i;
            }
        }
        ans  =  max(ans,temp);
        return ans;
    }
};
