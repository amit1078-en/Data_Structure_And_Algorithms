/*
3. Longest Substring Without Repeating Characters
Medium

15720

778

Add to List

Share
Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     if(s.empty()){
       return 0;
     }
        int map[256];
        memset(map,0,sizeof(map));
        int start =0;
        map[s[0]]+=1;
        int ans = 1;
      
      for(int i = 1;i<s.length();i++)
      {
        map[s[i]]++;
        if(map[s[i]]==2)
        {
          int k = start;
          while(k<i)
          {
            map[s[k]]--;
            if(map[s[k]]==1)
            {
              start = k+1;
              break;
            }  
            k++;
          }
        }
        ans = max(ans,i-start+1);
      }
      
      return ans;
    }
};
