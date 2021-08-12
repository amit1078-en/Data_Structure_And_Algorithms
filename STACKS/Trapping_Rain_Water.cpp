/*
42. Trapping Rain Water
Hard

12548

179

Add to List

Share
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
0 <= n <= 3 * 104
0 <= height[i] <= 105
Accepted
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if(size<3)return 0;
        
      int ans = 0;
        for(int i = 0;i<size;i++)
        {
          
              int j = i+1;
              int count = 0;
              while(j<size && height[i]>height[j])
              {
                count+=height[j];
                j++;
                
              }
            
            if(i+1!=j && j!=size)
            {
              ans+=((height[i]*(j-i-1))-count);
              i = j-1;
            }
            else if(j==size && i!=size-1)
            {
             
              count = 0;
              j = size-1;
              int val = INT_MIN;
              int k = size-1;
              while(i<j)
              {
                
                if(val<=height[j]){
                  k  = j;
                  val = height[j];
                }
                j--;
              }
                for(int j = i+1;j<k;j++)
                {
                  count+=height[j];
                }
                 ans+=((height[k]*(k-i-1))-count);
                  i = k-1;
            }
          }
        
        return ans;
      }
};
