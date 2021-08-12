/*
Smallest window in a string containing all the characters of another string 
Medium Accuracy: 42.59% Submissions: 31756 Points: 4
Given two strings S and P. Find the smallest window in the string S consisting of all the characters(including duplicates) of the string P.  Return "-1" in case there is no such window present. In case there are multiple such windows of same length, return the one with the least starting index. 

Example 1:

Input:
S = "timetopractice"
P = "toc"
Output: 
toprac
Explanation: "toprac" is the smallest
substring in which "toc" can be found.
Example 2:

Input:
S = "zoomlazapzo"
P = "oza"
Output: 
apzo
Explanation: "apzo" is the smallest 
substring in which "oza" can be found.
Your Task:
You don't need to read input or print anything. Your task is to complete the function smallestWindow() which takes two string S and P as input paramters and returns the smallest window in string S having all the characters of the string P. In case there are multiple such windows of same length, return the one with the least starting index. 

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(1)

Constraints: 
1 = |S|, |P| = 105

QUESTION TAG SLIDING WINDOWS,TWO POINTERS

https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1#
*/


#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
         int l = 0;
        int dp[26];
        int dp1[26];
        int extra = 0;
        l = 0;
        string ans;
        int l1 = s.length();
        int l2  = p.length();
        if(l1>=l2)
        {
           
            memset(dp,0,sizeof(dp));
            int count = 0;
            for(int i = 0 ; i<l2;i++)
            {
                count+=1;
                dp[p[i]-97]+=1;
            }
           
            memset(dp1,0,sizeof(dp1));
            int left = -1;
            int right = -1;
            int r = 0;
            string ans = "-1";
            int len = INT_MAX;
            int c = 0;
            while(r<l1)
            {
                dp1[s[r]-97]+=1;
                  if(dp[s[r]-97]!=0)
                  {
                    if(dp1[s[r]-97]<=dp[s[r]-97])
                    {
                        c+=1;
                    }
                    else
                    {
                        extra+=1;
                    }
                  }
              if(c>=count)
              {
                    int temp = r-l+1;
                    if(temp<len)
                    {
                        len = temp;
                        left = l;
                        right = r;
                    }  
                while(1)    
                {
                    if(dp[s[l]-97]!=0 && dp1[s[l]-97]<=dp[s[l]-97])
                    {
                        dp1[s[l]-97]-=1;
                        // int temp = r-l+1;
                        c-=1;
                    l+=1;
                   
                        break;
                    }
                        dp1[s[l]-97]-=1;
                    l+=1;
                    int temp = r-l+1;
                   
                    if(temp<len)
                    {
                        len = temp;
                        left = l;
                        right = r;
                    }
                }
               
              }
              r+=1;
            }
           
            if(left!=-1)
            {
                ans = s.substr(left,right-left+1);
            }
           
            return ans;
        }
        return "-1";
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
} 
