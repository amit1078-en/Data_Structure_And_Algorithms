/*

https://leetcode.com/contest/biweekly-contest-48/problems/second-largest-digit-in-a-string/

1796. Second Largest Digit in a String
User Accepted:3608
User Tried:4128
Total Accepted:3711
Total Submissions:8563
Difficulty:Easy
Given an alphanumeric string s, return the second largest numerical digit that appears in s, or -1 if it does not exist.

An alphanumeric string is a string consisting of lowercase English letters and digits.

 

Example 1:

Input: s = "dfa12321afd"
Output: 2
Explanation: The digits that appear in s are [1, 2, 3]. The second largest digit is 2.
Example 2:

Input: s = "abc1111"
Output: -1
Explanation: The digits that appear in s are [1]. There is no second largest digit. 
 

Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters and/or digits.
*/
class Solution {
public:
    int secondHighest(string s) 
    {
        set<int> p;
        for(int i = 0 ; i<s.length();i++)
        {
          char r = s[i];
          if(r>='0' && r<='9')
          {
            p.insert(r-'0');
          }
        }
      if(p.size()==1 || p.size()==0)
      {
        return -1;
        
      }
      int prev;
      int m;
      for(int i :p)
      {
        prev=m;
        m = i;
      }
        return prev;
      
    }
};
