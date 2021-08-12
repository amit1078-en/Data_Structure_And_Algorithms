/*
You are given a 0-indexed integer array nums and an integer k.

You are initially standing at index 0. In one move, you can jump at most k steps forward without going outside the boundaries of the array.
 That is, you can jump from index i to any index in the range [i + 1, min(n - 1, i + k)] inclusive.

You want to reach the last index of the array (index n - 1). Your score is the sum of all nums[j] for each index j you visited in the array.

Return the maximum score you can get.
*/
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int ans = 0;
        int len = nums.size();
        priority_queue<pair<int,int>> track;
        for(int i = len-1;i>=0;i--)
        {
            
            if(track.empty()==true)
            {
                track.push({nums[i],i});
            }
            else if(i==0)
            {
                
                    while( i+k <track.top().second){
                        track.pop();
                    }
                    ans = nums[i]+track.top().first;
            }
            else
            {
                int s = track.top().second;
                if(i+k>=s)
                {
                    track.push({track.top().first+nums[i],i});
                }
                else
                {
                    while( i+k <track.top().second){
                        track.pop();
                    }
                    track.push({track.top().first+nums[i],i});
                }
            }
            
        }
        if(nums.size()==1)
        {
            ans = nums[0];
        }
        return ans;
    }
};
