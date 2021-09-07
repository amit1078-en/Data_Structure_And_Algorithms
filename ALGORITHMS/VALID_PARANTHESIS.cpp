/*
VALID PARANTHESIS
link -> https://leetcode.com/submissions/detail/544369134/
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> help;
        for(int i = 0 ;i<s.length();i++)
        {
             if(s[i]=='(' || s[i]=='{' || s[i]=='[')
             {
                help.push(s[i]);
             }
            else
            {
                if(help.empty())return false;
                
                char y = help.top();
                help.pop();
                if((y=='(' && s[i]!=')' ) || (y=='{' && s[i]!='}') || (y=='[' && s[i]!=']'  ))
                {
                    return false;
                }
            }
        } 
        return help.empty();
    }
};
