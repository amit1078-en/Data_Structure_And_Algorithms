/*
Restrictive Candy Crush 
Medium Accuracy: 57.83% Submissions: 8765 Points: 4
Given a string s and an integer k, the task is to reduce the string by applying the following operation:
Choose a group of k consecutive identical characters and remove them.

The operation can be performed any number of times until it is no longer possible.

Example 1:

Input:
k = 2
s = "geeksforgeeks"
Output:
gksforgks
Explanation:
Modified String after each step: 
"geeksforgeeks" -> "gksforgks"
Example 2:

Input:
k = 2
s = "geegsforgeeeks" 
Output:
sforgeks
Explanation:
Modified String after each step:
"geegsforgeeeks" -> "ggsforgeks" -> "sforgeks"
Your Task:  
You don't need to read input or print anything. Complete the function Reduced_String() 
which takes integer k and string s as input parameters and returns the reduced string.

Expected Time Complexity: O(|s|)
Expected Auxiliary Space: O(|s|)

Constraints:
1 = |s| = 105
1 = k = |s|
link -> https://practice.geeksforgeeks.org/problems/8c8f95810b05b4cab665f2997d36991bd58308a2/1#
*/

//code
// { Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    string Reduced_String(
        int k,string s){
       if(k==1)
       {
           string ans;
        return ans;   
       }
       else
       {
            string ans;
        int len;
        stack<pair<char,int>> STACK;
        for(int i = 0;i<s.length();i++){
           
           if(!STACK.empty()){
               if(STACK.top().first==s[i]){
                   int c  = STACK.top().second;
                   STACK.push({s[i],c+1});
                   if(c+1==k)
                   {
                        for(int i  = 0;  i<k;i++)
                        {
                            STACK.pop();
                        }
                   }
               }
               else
               {
                   STACK.push({s[i],1});
               }
           }
           else
           {
               STACK.push({s[i],1});
           }
            
        }
        while(!STACK.empty())
        {
            ans.push_back(STACK.top().first);
            STACK.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
       }
    }


};

// { Driver Code Starts.

int main() {
    
    
    int t;cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.Reduced_String(k,s)<<"\n";
        
    }
    
	return 0;
}  // } Driver Code Ends
