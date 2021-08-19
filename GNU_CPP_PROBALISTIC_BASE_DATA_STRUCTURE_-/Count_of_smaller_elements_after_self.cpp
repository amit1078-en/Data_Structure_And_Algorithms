/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the 
number of smaller elements to the right of nums[i].

 

Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Example 2:

Input: nums = [-1]
Output: [0]
Example 3:

Input: nums = [-1,-1]
Output: [0,0]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104


*/

//code


#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>
class Solution {
public:
    ordered_set ok;
    vector<int> countSmaller(vector<int>& nums) {
      int size = nums.size();
      ok.insert(nums[size-1]);
      nums[size-1] = 0;
      for(int i  = size-2;i>=0;i--)
      {
        ok.insert(nums[i]);
         nums[i] = ok.order_of_key(nums[i]);
          
      }
      return nums;
    }
};
