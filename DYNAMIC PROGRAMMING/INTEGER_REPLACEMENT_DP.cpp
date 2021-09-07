/*
INTERGER REPLACEMENT -> https://leetcode.com/submissions/detail/544521588/

link -> 
Given a positive integer n, you can apply one of the following operations:

If n is even, replace n with n / 2.
If n is odd, replace n with either n + 1 or n - 1.
Return the minimum number of operations needed for n to become 1.

 

Example 1:

Input: n = 8
Output: 3
Explanation: 8 -> 4 -> 2 -> 1
Example 2:

Input: n = 7
Output: 4
Explanation: 7 -> 8 -> 4 -> 2 -> 1
or 7 -> 6 -> 3 -> 2 -> 1
Example 3:

Input: n = 4
Output: 2
 

Constraints:

1 <= n <= 231 - 1
*/

class Solution {
public:
    unordered_map<long long,int> maap;
    int rec(long long n)
    {
      if(n==1)
      {
        return 1;
      }
      if(maap.find(n)!=maap.end())
      {
        return maap[n];
      }
      if(n&1)
      {
        maap[n] = min(rec(n-1),rec(n+1))+1;
      }
      else
      {
        maap[n] = rec(n/2)+1;
      }
      return maap[n];
    }
    int integerReplacement(int n) {
       long long m  = n;
      return rec(m)-1;
    }
};
