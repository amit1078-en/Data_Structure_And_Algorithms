/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

class Solution {
public:
   vector<string> ans;
    
    bool paranthesis_checker(string & temp)
    {
        stack<char> S;
        for(int i = 0 ; i<temp.length() ; i++)
        {
            if(temp[i]=='(')
            {
                S.push('(');
            }
            else
            {
                if(S.empty())
                {
                    return false;
                }
                S.pop();
            }
        }
        if(!S.empty())
        return false;
        
        
        return true;
    }
    void backtrack(int i,int target,string & temp,int in,int ou,int n){
        if(in>n || ou >n){
            return ;
        }
        
        if(i==target)
        {
            bool check = paranthesis_checker(temp);
            if(check){
                ans.push_back(temp);
            }
            
            return ;
        }
        
        temp.push_back('(');
        backtrack(i+1,target,temp,in+1,ou,n);
        temp.pop_back();
        
        temp.push_back(')');
        backtrack(i+1,target,temp,in,ou+1,n);
        temp.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        // we can solve this problem using backtracking and paranthesis checker
        ans.clear();
        string t;
        backtrack(0,2*n,t,0,0,n);
        return ans;
    }
};
