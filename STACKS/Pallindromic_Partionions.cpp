/*
131. Palindrome Partitioning
Medium

3851

123

Add to List

Share
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.
Accepted
330,467
Submissions
611,837
*/

class Solution {
public:
    bool find(string s)
    {
        int S = s.length();
        int i = 0;
        while(i<S/2)
        {
            if(s[i]!=s[S-i-1] )
            {
                return false;
            }
            i++;
        }
        return true;
    }
    void fun(vector<vector<string>> &help,int l,int r,string s,vector<string> &temp)
    {
        
        if(l==r)
        {
           help.push_back(temp);
            return ;
        }
        for(int i = l;i<r;i++)
        {
         
            bool check = find(s.substr(l,i-l+1));
            if(check==true)
            {
                temp.push_back(s.substr(l,i-l+1));
                fun(help,i+1,r,s,temp);
                temp.pop_back();
                
                
                
                
            }
            
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> help;
        fun(help,0,s.length(),s,temp);
        return help;
    }
};
