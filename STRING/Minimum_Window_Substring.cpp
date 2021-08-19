/*

https://leetcode.com/submissions/detail/538810296/

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
 
 	
Follow up: Could you find an algorithm that runs in O(m + n) time?




TAG -> SLIDING WINDOW ,HASHING,TWO POINTERS

*/


class Solution {
public:
    string minWindow(string s, string t) {
        int len1  = s.length();
        int len2  = t.length();
        if(len1>=len2)
        {
              int dp[256];
              int dp2[256];
              memset(dp,0,sizeof(dp));
              memset(dp2,0,sizeof(dp2));
              for(char i:t){
                dp[i]+=1;
              }
            int start = -1;
          int end = -1;
          int i = 0;
          int req = 0;
          int dis = INT_MAX;
          int en = 0;
          while(i<len1)
          {
            
            if(dp[s[i]]!=0 && dp2[s[i]]<dp[s[i]]){
              req+=1;
            }
            dp2[s[i]]+=1;
            while(req==len2)
            {
              
              if(dp[s[en]]!=0)
              {
                if(dp2[s[en]]==dp[s[en]])
                {
                  req-=1;
                }
                if(dp2[s[en]]>=dp[s[en]])
                {
                  
                  dp2[s[en]]-=1;
                }
              }  
              if(dis>i-en+1)
              {
                dis = i-en+1;
                start = en;
                
              }
              en+=1;
            }
            i+=1;
          }
          
          if(start==-1)
          {
            return "";
          }
          return s.substr(start,dis);
        }
        return "";
    }
};
