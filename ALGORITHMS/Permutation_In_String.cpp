/*
Permutation in the String
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
Accepted
228,943
Submissions
514,030
*/

class Solution {
public:
    bool check(int dp[],int ds[])
    {
        for(int i= 0;i<26;i++)
        {
            if(dp[i]!=0)
            {
                if(dp[i]>ds[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int dp[26];
        int dp1[26];
        memset(dp,0,sizeof(dp));
        memset(dp1,0,sizeof(dp1));
        if(s1.length()<=s2.length())
        {
            for(int i = 0; i<s1.length();i++)
            {
                dp[s1[i]-97]+=1;
            }
            for(int i = 0 ; i<s1.length();i++)
            {
                dp1[s2[i]-97]+=1;
            }
            if(check(dp,dp1))
            {
                return true;
            }
            else
            {
                int k = 0;
                for(int i = s1.length();i<s2.length();i++)
                {
                       dp1[s2[i]-97]+=1;
                       dp1[s2[k]-97]-=1;
                         if(check(dp,dp1))
                        {
                            return true;
                        }
                        k+=1;
                }
            }
            
        }
        return false;
    }
};


