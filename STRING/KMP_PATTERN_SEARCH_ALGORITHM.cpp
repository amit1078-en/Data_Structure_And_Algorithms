/*
Search Pattern (KMP-Algorithm) 
Medium Accuracy: 64.23% Submissions: 2419 Points: 4
Given two strings, one is a text string, txt and other is a pattern string, pat. The task is to print the indexes of all the occurences of pattern string in the text string. For printing, Starting Index of a string should be taken as 1.


Example 1:

Input:
txt = "batmanandrobinarebat", pat = "bat"
Output: 1 18
Explanation: The string "bat" occurs twice
in txt, one starts are index 1 and the other
at index 18. 
Example 2:

Input: 
txt = "abesdu", pat = "edu"
Output: -1
Explanation: There's not substring "edu"
present in txt.

Your Task:
You don't need to read input or print anything. Your task is to complete the function search() which takes the string txt and the string pat as inputs and returns an array denoting the start indices (1-based) of substring pat in the string txt. 
Note: Return an empty list incase of no occurences of pattern. Driver will print -1 in this case.


Expected Time Complexity: O(|txt|).
Expected Auxiliary Space: O(|txt|).


Constraints:
1 = |txt| = 105
1 = |pat| < |S|
*/
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            int size = pat.size();
            int arr[size+2];
            arr[0] = 0;
            arr[1] = 0;
            int p = 0;
            for(int i = 2;i<=pat.length();i++)
            {
                if(pat[p]==pat[i-1])
                {
                    p++;
                    arr[i] = p;
                }
                else
                {
                    arr[i] = 0;
                    p = 0;
                }
            }
            vector<int> answer;
            
            if(txt.length()>=pat.length())
            {
                 p = 0;
                 for(int i =0;i<txt.length();i++)
                 {
                    if(txt[i]==pat[p])
                    {
                        p+=1;
                        if(p==size)
                        {
                            answer.push_back(i-size+2);
                            p = arr[p];
                        }
                    }
                    else {
                        p = arr[p];
                        if(txt[i]==pat[p])
                        {
                            p+=1;
                        }
                        else{
                            p = 0;
                        }
                    }
                 }
            }
            if(answer.empty())
            {
                answer.push_back(-1);
            }
            return answer;
        }
     
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

