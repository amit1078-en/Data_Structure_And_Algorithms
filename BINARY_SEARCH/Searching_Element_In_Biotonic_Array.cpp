/******************************************************************************

Searching elment in biotonic array
biotonic array is  a array in which sequence is firstly increasing and then strictly decreasing with all distinct element's
example 1 4 5 6 8 1 2
time complexity -> O(log(n))
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ans = 0;
        if(nums.size()==1)
        {
            ans = 0;
        }
        else
        {
            int left,right;
            left = 0;
            right = nums.size()-1;
            while(left<=right)
            {
                int mid = (left+right)/2;
                if(mid==0 || mid==nums.size()-1)
                {
                    if(mid==0)
                    {
                        if(nums[mid]>=nums[mid+1])
                        {
                            ans = nums[0];
                            break;
                        }
                        else
                        {
                            left = mid+1;
                        }
                    }
                    else if(mid==nums.size()-1)
                    {
                        if(nums[mid]>nums[mid-1])
                        {
                            ans = nums[mid];
                            break;
                        }
                        else
                        {
                            right = mid-1;
                        }
                    }
                }
                else if(nums[mid]>nums[mid+1] && nums[mid]>=nums[mid-1])
                {
                     ans = nums[mid];
                    break;
                }
                else if(nums[mid-1]<nums[mid+1])
                {
                    left = mid+1;
                }
                else
                {
                    right = mid-1;
                }
            }
        }
        return ans;
    }
};
int main()
{
     Solution o;
    
         int size;
     vector<int> array;
    for(int i = 0 ; i <size;i++)
    {
        int t;
        cin>>t;
        array.push_back(t);
    }
    int x = o.findPeakElement(array);
    cout<<x<<endl;
     
    return 0;
}

