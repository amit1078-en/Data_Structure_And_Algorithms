/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.
*/


class trie
{
  public:
  trie* arr[26];
  bool last;
  trie(){
    for(int i =0;i<26;i++)
    {
      arr[i]=NULL;
    }
    last = false;
  }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
      string ans = "";
      trie* parent = new trie();
      for(int i = 0 ; i<strs.size();i++)
      {
          trie* child  = parent;
          string temp = strs[i];
          for(int j = 0 ; j<temp.length();j++)
          {
              if(child->arr[temp[j]-97]==NULL)
              {
                trie* newn = new trie();
                child->arr[temp[j]-97] = newn;
                child = newn;
              }
              else
              {
                
                child = child->arr[temp[j]-97];
              }
              
          }
        child->last = true;
      }
      
      while(!parent->last)
      {
        int y = 0;
        int tot = 0;
        for(int i =  0 ; i<26;i++)
        {
          if(parent->arr[i]!=NULL)
          {
            y = i;
            tot+=1;
          }
        }
        if(tot>1 || parent->last==true)
        {
          break;
        }
        ans.push_back('a'+y);
        parent = parent->arr[y];
      }
      return ans;
    } 
};
