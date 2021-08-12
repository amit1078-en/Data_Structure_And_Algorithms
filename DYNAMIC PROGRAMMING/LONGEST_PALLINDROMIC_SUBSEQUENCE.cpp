/*
. Longest Palindromic Substring
Medium

11131

710

Add to List

Share
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int st = 0;
        int ans = 0;
        int len = s.length();
        bool track[1001][1001];
        for(int i= 0;i<len;i++)
        {
          track[i][i] = true;
        }
        for(int i= 1;i<len;i++)
        {
          if(s[i]==s[i-1])
          {
            track[i-1][i] = true;
            ans = 1;
            continue;
          }
          
          
         track[i-1][i] = false;
          
        }
      for(int i = 2;i<len;i++)
      {
        int I = 0;
        while(I+i<len)
        {
          if(s[I]==s[I+i]  && track[I+1][I+i-1])
          {
            track[I][I+i] = true;
            ans = i;
  
          }
          else
          {
            track[I][I+i] = false;
          }
          I++;
        }
      }
      int I = 0;
        while(I+ans<len)
        {
          if(track[I][I+ans])
          {
            return s.substr(I,ans+1);
          }
          I++;
        }
     return s;
    }
};
