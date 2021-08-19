/*
https://leetcode.com/submissions/detail/540301952/


1930. Unique Length-3 Palindromic Subsequences
User Accepted:3517
User Tried:4935
Total Accepted:3653
Total Submissions:9712
Difficulty:Medium
Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

A palindrome is a string that reads the same forwards and backwards.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
 

Example 1:

Input: s = "aabca"
Output: 3
Explanation: The 3 palindromic subsequences of length 3 are:
- "aba" (subsequence of "aabca")
- "aaa" (subsequence of "aabca")
- "aca" (subsequence of "aabca")
Example 2:

Input: s = "adc"
Output: 0
Explanation: There are no palindromic subsequences of length 3 in "adc".
Example 3:

Input: s = "bbcbaba"
Output: 4
Explanation: The 4 palindromic subsequences of length 3 are:
- "bbb" (subsequence of "bbcbaba")
- "bcb" (subsequence of "bbcbaba")
- "bab" (subsequence of "bbcbaba")
- "aba" (subsequence of "bbcbaba")
 

Constraints:

3 <= s.length <= 105
s consists of only lowercase English letters.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> track[26];
        for(int i = 0;i<s.length();i++)
        {
          track[s[i]-97].push_back(i);
        }
        int answer = 0;
        for(int i = 0;  i<26;i++)
        {
          
          
          if(track[i].size()>=2)
          {
            int s = track[i][0];
            int e = track[i][track[i].size()-1];
            for(int j = 0;j<26;j++)
            {
              if(i==j)
              {
                if(track[i].size()>=3)
                {
                  answer+=1;
                }
                continue;
              }
              if(track[j].size()>=1 && track[j][track[j].size()-1]>s)
              {
                int index = upper_bound(track[j].begin(),track[j].end(),s)-track[j].begin();
                if(track[j][index]<e)
                {
                  answer+=1;
                }
              }
            }
          }
          
        }
        return answer;
    }
};


int main()
{
    Solution obj;
    cout<<obj.countPalindromicSubsequence("846846546546546")<<endl;
}
