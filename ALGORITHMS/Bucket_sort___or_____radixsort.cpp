class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int ans = 0;
        int size = nums.size();
        if(size>1)
        {
            int digit = INT_MIN;
            vector<int> temp;
            for(int i = 0 ;  i<size;i++)
            {
                digit = max(digit,nums[i]);
                temp.push_back(nums[i]);
            }
            int d = 0;
            while(digit>0)
            {
                d++;
                digit/=10;
            }
            for(int i = 0 ;  i<d;i++)
            {
                vector<int> space[10];
                for(int j = 0; j<size;j++)
                {
                    int rr = nums[j]; 
                    for(int y = 0  ; y<i;y++)
                    {
                        rr/=10;
                    }
                    int q = rr%10;
                    space[q].push_back(nums[j]);
                }
                int y = 0;
                for(int k = 0 ;  k<=9;k++)
                {
                    for(int h:space[k])
                    {
                        nums[y]  = h;
                        y++;
                    }
                }
            }
            for(int i = 1 ; i<size;i++)
            {
                ans = max(ans,nums[i]-nums[i-1]);
            }
        }
        return ans;
    }
};
