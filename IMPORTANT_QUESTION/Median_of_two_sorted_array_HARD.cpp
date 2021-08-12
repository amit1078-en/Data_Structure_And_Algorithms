/*
4. Median of Two Sorted Arrays
https://leetcode.com/problems/median-of-two-sorted-arrays/
Hard

11196

1601

Add to List

Share
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
Accepted
1,003,980
Submissions
3,123,016
*/
class Solution {
public:
  double getans(int s1,int s2,vector<int> &nums1,vector<int> &nums2,int req)
  {
      double temp = 1;
        int l = min(nums1[0],nums2[0]);
        int r = max(nums1[s1-1],nums2[s2-1]);
        while(l<=r)
        {
          bool f = false,s=false;
          int mid = (l+r)/2;
          int index =  upper_bound(nums1.begin(),nums1.end(),mid)-nums1.begin();
          int index2 = upper_bound(nums2.begin(),nums2.end(),mid)-nums2.begin();           
        
          int c = index+index2;
          
          if(c>=req)
          {
                  index =  lower_bound(nums1.begin(),nums1.end(),mid)-nums1.begin();
                 index2 = lower_bound(nums2.begin(),nums2.end(),mid)-nums2.begin();          
                if((index!=s1 && nums1[index]==mid)  )
                {
                  temp = mid;
              
                }
            if((index2!=s2 && nums2[index2]==mid))
            {
              temp = mid;
            }
             r = mid-1;
            
          }
          else
          {
    
            l = mid+1;
          }
        }
    return temp;
  }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size();
        int s2 = nums2.size();
        if(s2==0)
        {
          if(nums1[0]==nums1[nums1.size()-1]){
            return nums1[0];
          }
          if(nums1.size()%2==0){
            double f = nums1[(nums1.size()/2)-1];
            double s = nums1[nums1.size()/2];
            return (f+s)/2;
          }
          return nums1[nums1.size()/2];
        }
        else if(s1==0)
        {
            if(nums2[0]==nums2[nums2.size()-1]){
              return nums2[0];
            }
           if(nums2.size()%2==0)
           {
            double f = nums2[(nums2.size()/2)-1];
            double s = nums2[nums2.size()/2];
            return (f+s)/2;
          }
          return nums2[nums2.size()/2];
        }
      
      double ans = getans(s1,s2,nums1,nums2,(s1+s2)/2 +1);
     if((s1+s2)%2==0)
     {
       ans+=getans(s1,s2,nums1,nums2,(s1+s2)/2);
       ans/=2;
     }
      return ans;
    }
};



