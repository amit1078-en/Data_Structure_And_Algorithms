/*
416. Partition Equal Subset Sum
Medium

4722

94

Add to List

Share
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
Accepted
300,778
Submissions
664,875
Seen this question in a real interview before?

Yes

No

*/
class Solution{
public:
    int track[201][19995];
    bool help(int N,vector<int> &arr,int s)
    {
        if(s==0)
        {
            return true;
        }
        
        if(N==0 || s<0)
        {
            return false;
        }
        
        
        if(track[N-1][s]!=-1)
        {
            return track[N-1][s];
        }
        
        
        return track[N-1][s] = help(N-1,arr,s)|help(N-1,arr,s-arr[N-1]);
    }
    
    int canPartition(vector<int> &arr)
    {
        int N= arr.size();
        memset(track,-1,sizeof(track));
        
        int sum = 0;
        for(int i = 0 ;i<N;i++)
        {
            sum+=arr[i];
        }
        
        if(sum%2!=0)return 0;
        
        return help(N,arr,sum/2);
    }
};
