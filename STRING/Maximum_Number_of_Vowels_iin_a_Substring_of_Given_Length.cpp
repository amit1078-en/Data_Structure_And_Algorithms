/*
link -> https://leetcode.com/submissions/detail/543542515/

1456. Maximum Number of Vowels in a Substring of Given Length



Given a string s and an integer k.

Return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are (a, e, i, o, u).

 

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
Example 4:

Input: s = "rhythms", k = 4
Output: 0
Explanation: We can see that s doesn't have any vowel letters.
Example 5:

Input: s = "tryhard", k = 4
Output: 1
 

Constraints:

1 <= s.length <= 10^5
s consists of lowercase English letters.
1 <= k <= s.length


*/


class Solution {
public:
    bool isvowel(char c)
    {
      if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
      {
        return true;
      }
      return false;
    }
    int maxVowels(string s, int k) {
      if(k==1)
      {
        for(char c: s)
        {
          if(isvowel(c))
          {
            return 1;
          }
        }
        return 0;
      }
      
      int ans = 0;
      int curr = 0;
      for(int i = 0 ; i<k;i++)
      {
        if(isvowel(s[i]))
          {
            curr+=1;
          }
      }
      ans = max(ans,curr);
      int l = 0;
      for(int i = k; i<s.length();i++)
      {
         if(isvowel(s[i]))
         {
           curr+=1;
         }
          if(isvowel(s[l]))
          {
            curr-=1;
          }
          l++;
        ans = max(ans,curr);
      }
      return ans;
    }
};
