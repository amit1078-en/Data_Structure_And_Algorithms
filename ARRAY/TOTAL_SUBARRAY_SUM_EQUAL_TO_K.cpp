/*
560. Subarray Sum Equals K
Medium

6982

241

Add to List

Share
Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

 
*/
class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int ans = 0;
        int N = arr.size();
       unordered_map<int,int> array(N+1);
        array[arr[0]]++;
        for(int i = 1 ; i<N;i++)
       {
           arr[i] = arr[i]+arr[i-1];
            array[arr[i]]++;
       }
        for(int i = 0; i<N;i++)
        {
            if(i==0)
            {
                auto it = array.find(k);
                if(it!=array.end())
                {
                    ans  = ans+(it->second);
                }
                 it = array.find(arr[i]);
                if(it!=array.end())
                {
                    array[arr[i]]--;
                }
            }
            else
            {
                int search = arr[i]-arr[i-1];
                int element = k-search;
                auto it = array.find(element+arr[i]);
                if(it!=array.end())
                {
                    ans  = ans+(it->second);
                }
                 it = array.find(arr[i]);
                if(it!=array.end())
                {
                    array[arr[i]]--;
                }
            }
        }
        return ans;
    }
};
