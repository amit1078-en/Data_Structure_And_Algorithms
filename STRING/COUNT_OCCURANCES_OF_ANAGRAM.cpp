/*
Count Occurences of Anagrams 
Given a word pat and a text txt. Return the count of the occurences of anagrams of the word in the text.

Example 1:

Input:
txt = forxxorfxdofr
pat = for
Output: 3
Explanation: for, orf and ofr appears
in the txt, hence answer is 3.
Example 2:

Input:
txt = aabaabaa
pat = aaba
Output: 4
Explanation: aaba is present 4 times
in txt.
Your Task:
Complete the function search() which takes two strings pat, txt, as input parameters and returns an integer denoting the answer. You don't to print answer or take inputs.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(26) or O(256)

Constraints:
1 <= |pat| <= |txt| <= 105
Both string contains lowercase english letters.

 
*/
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string B, string A) 
	{
	    int small[26];
	    memset(small,0,sizeof(small));
	    int ans = 0;
	    for(int i= 0;i<B.length();i++)
	    {
	        small[B[i]-97]+=1;
	    }
	    
	    int sliding_window[26];
	    memset(sliding_window,0,sizeof(sliding_window));
	    
	    if(A.length()<B.length()) return 0;
	    
	    for(int i = 0; i<B.length();i++)
	    {
	        sliding_window[A[i]-97]+=1;
	    }
	    
	    
	    bool cycle = true;
	    for(int i = 0;i<26;i++)
	    {
	        if(small[i]!=0)
	        {
	            
	           if(small[i]!=sliding_window[i])
              {
                   cycle = false;
	           break; 
              }
	        }
	    }
	    if(cycle)
	    {
	        ans+=1;
	    }
	    
	    int m = 0;
	    for(int k = B.length();k<A.length();k++)
	    {
	        sliding_window[A[m]-97]-=1;
	        sliding_window[A[k]-97]+=1;
	        cycle = true;
	        for(int i = 0;i<26;i++)
    	    {
    	        if(small[i]!=sliding_window[i])
    	        {
                   cycle = false;
    	           break; 
    	        }
    	    }
    	    if(cycle)
    	    {
    	        ans+=1;
    	    }
	        m+=1;
	    }
	    
	    return ans;
	}

};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
