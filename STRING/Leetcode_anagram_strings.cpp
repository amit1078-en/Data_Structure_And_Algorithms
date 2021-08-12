/*
Leetcode -> Anagram strings
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 

Constraints:

1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters.
*/

//approach_used -> sliding window with 2 pointers
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int lens = s.length();
        int lenp = p.length();
        if(lenp<=lens)
        {
              int arr[26];
              int temp[26];
              for(int i = 0 ; i<26;i++)
              {
                arr[i] = temp[i] = 0;
              }
              for(int i = 0 ; i<lenp;i++)
              {
                arr[p[i]-97]++;
              }
              int tot = lenp;
              int t = 0;
              for(int i = 0 ; i<lenp;i++)
              {
                if(arr[s[i]-97]!=0)
                {
                  if(temp[s[i]-97]<arr[s[i]-97]){
                      t++;
                  }
                  temp[s[i]-97]++;
                }
              }
          int i = 0;
          for( i = 0;i+lenp<lens;i++)
          {
              if(t==lenp)
              {
                ans.push_back(i);
              }
               if(arr[s[i]-97]!=0)
               {
                 
                 if(temp[s[i]-97]<=arr[s[i]-97]){
                      t--;
                   
                  }
                 temp[s[i]-97]--;
               }
               if(arr[s[i+lenp]-97]!=0)
                {
                  if(temp[s[i+lenp]-97]<arr[s[i+lenp]-97]){
                      t++;
                  }
                  temp[s[i+lenp]-97]++;
                }
           }
          if(t==lenp)
          {
            ans.push_back(i);
          }
        }
        return ans;
    }
};
