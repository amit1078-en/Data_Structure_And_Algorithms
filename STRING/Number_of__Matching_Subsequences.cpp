/*
Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
 

Example 1:

Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
Example 2:

Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2
 

Constraints:

1 <= s.length <= 5 * 104
1 <= words.length <= 5000
1 <= words[i].length <= 50
s and words[i] consist of only lowercase English letters.
*/

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> track[26];
        int ans = 0;
        for(int i = 0 ; i<s.length();i++)
        {
            track[s[i]-97].push_back(i);
        }
        for(string temp:words)
        {
            int i = 0;
            bool push = true;
            int last = -1;
            for(int i = 0;i<temp.length();i++){
                int it = temp[i]-97;
                 if(track[it].empty()){
                    push = false;
                    break;
                }
                auto itr = upper_bound(track[it].begin(),track[it].end(),last);
                if(itr==track[it].end()){
                    push = false;
                    break;
                }
                last = track[it][itr-track[it].begin()];
    
            }
            if(push){
                ans++;
            }
        }
        return ans;
    }
};
