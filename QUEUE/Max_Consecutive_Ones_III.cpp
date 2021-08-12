/*
  Max Consecutive Ones III

Solution
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length
*/
class Solution {
public:
    int longestOnes(vector<int>& track, int k) {
        int ans = 0;
        queue<int> q;
        int zero = k;
        int temp = 0;
        if(k==0)
        {
            
            int k = 0;
            int ans = 0;
            for(int i  = 0;i<track.size();i++)
            {
                if(track[i]==1)
                {
                    int u = 0;
                    int j;
                    for( j = i ;j<track.size() && track[j]!=0;j++)
                    {
                        u++;
                    }
                    i = j;
                    ans = max(ans,u);
                }
            }
            return ans;
        }
        int i = 0;
        int dis = 0;
        int left = k;
        for(int j = 0; j<track.size();j++)
        {
            if(track[j]!=0)
            {
                dis+=track[j];
                temp+=track[j];
            }
            else
            {
                
                if(left>0)
                {
                    q.push(dis);
                    dis = 0;
                    temp++;
                    left--;
                }
                else
                {
                    int front = q.front();
                    q.pop();
                    q.push(dis);
                    dis = 0;
                    temp-=front;
                }
            }
            ans = max(ans,temp);
        }
        return ans;
    }
};
