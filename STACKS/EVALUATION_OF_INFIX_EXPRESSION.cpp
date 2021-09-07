/*

EVALUATION OF INFIX EXPRESSION

227. Basic Calculator II
Medium

2748

409

Add to List

Share
Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5
 

Constraints:

1 <= s.length <= 3 * 105
s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
s represents a valid expression.
All the integers in the expression are non-negative integers in the range [0, 231 - 1].
The answer is guaranteed to fit in a 32-bit integer.
Accepted
297,215
Submissions
753,143
*/


class Solution {
public:
    int precedance(char r)
    {
      if(r=='+')
      {
        return 1;
      }
      if(r=='-')
      {
        return 1;
      }
      if(r=='*')
      {
        return 2;
      }
      if(r=='/')
      {
        return 2;
      }
      return -1;
    }
    int calculate(string s) 
    {
      long long ans = 0;
      stack<long long> s1;
      stack<char> s2;
        for(int i = 0 ; i<s.length();i++)
        {
          if(s[i]==' ')
          {
            continue;
          }
          if(s[i]=='*' || s[i]=='/' || s[i]=='+' || s[i]=='-')
          {
            int p = precedance(s[i]);
            if(s2.empty())
            {
              s2.push(s[i]);
            }
            else
            {
              while(!s2.empty() && precedance(s2.top())>=p)
              {
                char top = s2.top();
                long long b = s1.top();
                s1.pop();
                  long long a = s1.top();
                s1.pop();
                if(top=='+')
                {
                  s1.push(a+b);
                }
                else if(top=='-')
                {
                  s1.push(a-b);
                }
                else if(top=='*')
                {
                  s1.push(a*b);
                }
                else if(top=='/')
                {
                   s1.push(a/b);
                }
                s2.pop();
              }
              s2.push(s[i]);
            }
            continue;
          }
          long long temp = 0;
          int l = i;
          while(s[l]-'0'>=0 && s[l]-'0'<=9)
          {
            temp*=10;
            temp+=(s[l]-'0');
            l+=1;
          }
          i = l-1;
          s1.push(temp);
        }
        while(!s2.empty())
        {
          char top = s2.top();
                long long b = s1.top();
                s1.pop();
                  long long a = s1.top();
                s1.pop();
                if(top=='+')
                {
                  s1.push(a+b);
                }
                 if(top=='-')
                {
                  s1.push(a-b);
                }
                 if(top=='*')
                {
                  s1.push(a*b);
                }
                 if(top=='/')
                {
                   s1.push(a/b);
                }
                s2.pop();
        }
        return s1.top();
    }
};
