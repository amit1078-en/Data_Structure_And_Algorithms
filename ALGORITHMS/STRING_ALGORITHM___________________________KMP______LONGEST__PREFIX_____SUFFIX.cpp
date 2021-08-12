/*
Longest Prefix Suffix 
Medium Accuracy: 49.39% Submissions: 15672 Points: 4
Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.

Example 1:

Input: s = "abab"
Output: 2
Explanation: "ab" is the longest proper 
prefix and suffix. 
Example 2:

Input: s = "aaaa"
Output: 3
Explanation: "aaa" is the longest proper 
prefix and suffix. 
Your task:

You do not need to read any input or print anything. The task is to complete the function lps(), 
which takes a string as input and returns an integer.

Expected Time Complexity: O(|s|)
Expected Auxiliary Space: O(|s|)

Constraints:
1 = |s| = 105
s contains lower case English alphabets
*/

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:		

		
	int lps(string s)
	{
	    int ans = 0;
	    int arr[s.length()];
	    arr[0] = 0;
	    int len = 0;
	    for(int i = 1;i<s.length();i++)
	    {
	        if(s[i]==s[len])
	        {
                len++;
                arr[i]=len;
	        }
	        else if(len!=0)
	        {
	            len = arr[len-1];
	            i--;
	        }
	        else
	        {
	            arr[i] = 0;
	            len = 0;
	        }
	    }
	    return arr[s.length()-1];
	}
};

// { Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
} 
