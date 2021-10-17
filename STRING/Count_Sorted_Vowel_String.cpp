/*
Count Sorted Vowel String


Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.

 

Example 1:

Input: n = 1
Output: 5
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].
Example 2:

Input: n = 2
Output: 15
Explanation: The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.
Example 3:

Input: n = 33
Output: 66045
 

Constraints:

1 <= n <= 50 
Accepted
66,360
Submissions
88,496

*/

long long dp[52][5];
bool check = false;
class Solution {
public:
    Solution()
    {
        if(!check)
        {
            check = true;
            dp[0][0] = dp[0][1] =dp[0][2] = dp[0][3] = dp[0][4] = 1;
            long long sum = 5;
            for(int i = 1;i<51;i++)
            {
                long long temp = dp[i-1][0];
                dp[i][0] = sum;
                long long Sum = dp[i][0];
                for(int j = 1; j<5;j++)
                {
                    dp[i][j] = sum-temp;
                    temp+=dp[i-1][j];
                    Sum+=dp[i][j];
                }
                sum = Sum;
            }
        }
    }
    int countVowelStrings(int n) 
    {
        return dp[n][0];
    }
};

