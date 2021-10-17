/*

Given a list of contacts contact[] of length n where each contact is a string which exist in a phone directory and a query string s. The task is to implement a search query for the phone directory. Run a search query for each prefix p of the query string s (i.e. from  index 1 to |s|) that prints all the distinct contacts which have the same prefix as p in lexicographical increasing order. Please refer the explanation part for better understanding.
Note: If there is no match between query and contacts, print "0".

Example 1:

Input: 
n = 3
contact[] = {"geeikistest", "geeksforgeeks", 
"geeksfortest"}
s = "geeips"
Output:
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest
0
0
Explaination: By running the search query on 
contact list for "g" we get: "geeikistest", 
"geeksforgeeks" and "geeksfortest".
By running the search query on contact list 
for "ge" we get: "geeikistest" "geeksforgeeks"
and "geeksfortest".
By running the search query on contact list 
for "gee" we get: "geeikistest" "geeksforgeeks"
and "geeksfortest".
By running the search query on contact list 
for "geei" we get: "geeikistest".
No results found for "geeip", so print "0". 
No results found for "geeips", so print "0".
Your Task:
Youd do not need to read input or print anything. Your task is to complete the function displayContacts() which takes n, contact[ ] and s as input parameters and returns a list of list of strings for required prefixes. If some prefix has no matching contact return "0" on that list.

Expected Time Complexity: O(|s| * n * max|contact[i]|)
Expected Auxiliary Space: O(n * max|contact[i]|)

Constraints:
1 = n = 50
1 = |contact[i]| = 50
1 = |s| = 6 

Company Tags
Topic Tags
Related Interview Experiences

*/


// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++


class trie
{
  public:
    trie* next[26];
    bool last;
    trie()
    {
     last = false;
     for(int i = 0; i <26;i++)
     {
         next[i] = NULL;
     }
    }
};

class Solution{
public:
    trie* Head;
    unordered_set<string> j;
    Solution()
    {
         trie* temp = new trie();
        Head = temp;
    }
    void insert(string s)
    {
        trie* temp = Head;
        for(int i = 0 ; i<s.length();i++)
        {
            int x   = s[i]-'a';
            if(temp->next[x]==NULL)
            {
                trie* hh = new trie();
                temp->next[x] = hh;
                temp = hh;
            }
            else
            {
                temp = temp->next[x];
            }
        }
        temp->last = true;
    }
    void rec(string s,string eq,vector<string> &add,trie* root)
    {
        bool check = true;
        for(int i = 0 ; i<26;i++)
        {
            if(root->next[i]!=NULL)
            {
                check = false;
                s.push_back('a'+i);
                if(j.find(s)==j.end() && root->next[i]->last)
                {
                    add.push_back(s);
                    j.insert(s);
                }
                rec(s,eq,add,root->next[i]);
                s.pop_back();
            }
        }
        if(check)
        {
            
            return ;
        }
    }
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        j.clear();
        string ok;
        bool sss = false;
        unordered_set<string> check;
        vector<vector<string>> answer;
        for(int i  = 0 ; i<n;i++)
        {
        	check.insert(contact[i]);
            if(contact[i]==s)
            {
                sss = true;
            }
            insert(contact[i]);
        }
        
    
        for(int i=0;i<s.length();i++)
        {
            j.clear();
            ok.push_back(s[i]);
              vector<string> temp;
                
            j.insert(ok);
          
            string add;
          
             if(Head!=NULL)
            {
            	   Head = Head->next[s[i]-'a'];
            }
            if(Head==NULL)
            {
            	if(check.find(ok)!=check.end())
	           	{
	           		  temp.push_back(ok);
		                answer.push_back(temp);
		                continue;
				}
                  string ss;
                  ss = "0"; 
                  temp.push_back(ss);
                answer.push_back(temp);
                continue;
            }
            if(check.find(ok)!=check.end())
		           	{
		           		  temp.push_back(ok); 
					}
            rec(ok,ok,temp,Head);
            if(temp.empty())
            {
	            	
					temp.push_back("0");
			}
            answer.push_back(temp);
        }
        
        return answer;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends
