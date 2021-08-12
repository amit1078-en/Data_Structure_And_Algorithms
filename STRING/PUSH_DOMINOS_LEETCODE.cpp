/*
Push Dominoes

Solution
There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes
 either to the left or to the right.

After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the
 right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen 
domino.

You are given a string dominoes representing the initial state where:

dominoes[i] = 'L', if the ith domino has been pushed to the left,
dominoes[i] = 'R', if the ith domino has been pushed to the right, and
dominoes[i] = '.', if the ith domino has not been pushed.
Return a string representing the final state.

 

Example 1:

Input: dominoes = "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.
Example 2:


Input: dominoes = ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."
 

Constraints:

n == dominoes.length
1 <= n <= 105
dominoes[i] is either 'L', 'R', or '.'.
*/
class Solution {
public:
    string pushDominoes(string ans){
          int len = ans.length();
          for(int i = 0;i<len;i++)
          {
            if(ans[i]=='.')
            {
                int l = i;
                while(l<len && ans[l]=='.')
                {
                    l++;
                }
    
                if(l==len)break;
                
                if(ans[l]=='L')
                {
                  int m = l-1;
                  while(m>=i)
                  {
                    ans[m] = 'L';
                    m--;
                  } 
                }
                if(l-1>=i)
                {
                  i = l-1;
                }
            }
            else if(ans[i]=='L')
            {
                int l = i;
                while(l<len && ans[l]=='L')
                {
                  l++;
                }
                if(l-1>=i)
                {
                  i = l-1;
                }
            }
            else if(ans[i]=='R')
            {
              int l = i;
              while(l<len && ans[l]=='R')
              {
                l++;
              }
              if(l==len)break;
              
              if(ans[l]=='.')
              {
                int m = l;
                while(l<len && ans[l]=='.')l++;
                
                if(l==len || ans[l]=='R'){
                  for(int k = m;k<l;k++)
                  {
                    ans[k] = 'R';
                  }
                }
                else if(ans[l]=='L')
                {
                    int rr = l-1;
                    int mm = m;
                    while(rr>mm && rr!=mm)
                    {
                      ans[rr] = 'L';
                      ans[mm] = 'R';
                      rr-=1;
                      mm+=1;
                    }
                }
              }
            
                if(l-1>=i)
                {
                  i = l-1;
                }
                
              
            }
          }
          return ans;
    }
};
