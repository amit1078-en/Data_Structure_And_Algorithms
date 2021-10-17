/*
115. Distinct Subsequences

Given two strings s and t, return the number of distinct subsequences of s which equals t.

A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

It is guaranteed the answer fits on a 32-bit signed integer.

 

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from S.
babgbag
babgbag
babgbag
babgbag
babgbag
 

Constraints:

1 <= s.length, t.length <= 1000
s and t consist of English letters.

*/
class Solution 
{
public:
    int numDistinct(string s, string t) 
    {
        int ans = 0;
        if(s.length()<=t.length())
        {
            if(s==t)
                return 1;
            
            return 0;
        }
        int rsize = s.length();
        int csize = t.length();
        long long dp[s.length()+1][t.length()+1];
        for(int i = 0 ; i<=t.length();i++)
        {
            dp[0][i] = 0;
        }
        for(int i = 0;  i<=s.length();i++)
        {
            dp[i][0] = 1;
        }
        for(int i = 1;  i<=s.length();i++)
        {
            for(int j = 1;j<=t.length();j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[s.length()][t.length()];
    }
};
