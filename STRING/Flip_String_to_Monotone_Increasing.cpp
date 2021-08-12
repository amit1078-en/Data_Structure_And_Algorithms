/*
Leetcode -> 926  Flip String to Monotone Increasing



submition link -> https://leetcode.com/submissions/detail/536361733/

A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's
 (also possibly none).

You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.

Return the minimum number of flips to make s monotone increasing.

 

Example 1:

Input: s = "00110"
Output: 1
Explanation: We flip the last digit to get 00111.
Example 2:

Input: s = "010110"
Output: 2
Explanation: We flip to get 011111, or alternatively 000111.
Example 3:

Input: s = "00011000"
Output: 2
Explanation: We flip to get 00000000.
*/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int start = -1;
        int one = 0;
        int zero = 0;
        for(int i = 0 ; i<s.length();i++)
        {
      
          if(s[i]=='1')
          {
            one+=1;
            if(start==-1)
            {
              start=i;
            }
          }
          else if(start!=-1)
          {
            zero+=1;
          }
        }
      if(zero==0 || one==0)
      {
        return 0;
      }
      int ans = INT_MAX;
      int o = one;
      int z = zero;
      int k = 0;
      for(int i = start;i<s.length();i++)
      {
        if(s[i]=='0')
        {
          zero-=1;
          continue;
        }
        
        ans = min(ans,zero+k);
        k+=1;
      }
      zero = z;
      return min(ans,min(one,zero));
    }
};

