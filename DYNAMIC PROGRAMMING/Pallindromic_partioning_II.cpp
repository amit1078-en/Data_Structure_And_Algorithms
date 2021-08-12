/*
Palindrome Partitioning II

Solution
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:

Input: s = "a"
Output: 0
Example 3:

Input: s = "ab"
Output: 1
 

Constraints:

1 <= s.length <= 2000
s consists of lower-case English letters only.
*/

class Solution {
public:
    
    bool track[2001][2001];
    int step[2001];
    int rec(int row,int col,int size)
    {
      if( row==size)
      {
        return 0;
      }
   
      int m = INT_MAX;
      for(int k = row;k<size;k++)
      {
        if(track[row][k])
        {
          if(step[k+1]!=-1)
          {
            m = min(m,step[k+1]+1);
          }
          else
          {
            m = min(m,rec(k+1,k+1,size)+1);
          }
        }
      }
      step[row] = m;
      return m;
    }
    int minCut(string s) {

          int st = 0;
        int len = s.length();

        for(int i= 0;i<len;i++)
        {
          step[i] = -1;
          track[i][i] = true;
        }
        for(int i= 1;i<len;i++)
        {
          if(s[i]==s[i-1])
          {
            track[i-1][i] = true;
          }
          else
          {
            track[i-1][i] = false;
          
          } 
        }
       for(int i = 2;i<len;i++)
      {
        int I = 0;
        int ds = len-i;
        while(ds--)
        {
          if(s[I]==s[I+i]  && track[I+1][I+i-1]==true)
          {
            track[I][I+i] = true;
          }
          else
          {
            track[I][I+i] = false;
          }
          I++;
        }
      }
      int ans =  rec(0,0,len);
      return ans-1;
    }
};
