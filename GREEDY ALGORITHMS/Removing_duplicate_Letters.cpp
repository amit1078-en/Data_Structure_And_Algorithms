/*
316. Remove Duplicate Letters

Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.
*/
class Solution {
public:
    string removeDuplicateLetters(string s) 
    {   
        string ans;
        vector<int> maap[26];
        for(int i = 0; i<s.length() ;i++)
        {
            maap[s[i]-97].push_back(i);
        }
        bool visited[26];
        memset(visited,false,sizeof(visited));
        string temp;
        for(int i = 0; i<26;i++)
        {
            if(!maap[i].empty())
            {
                temp.push_back('a'+i);
            }
        }

        int last = -1;
        while(ans.length()!=temp.length())
        {
            for(int k = 0 ;k<temp.length();k++)
            {
                int i = temp[k]-97;
                if(!visited[i])
                {
                    bool pushed = true;
                    //it will check if it is potential to become the member or not
                    
                    int index = upper_bound(maap[i].begin(),maap[i].end(),last)-maap[i].begin();
                    index=maap[i][index];
                    if(index<s.length() && index>last)
                    {
                         for(int j = 0 ;j<temp.length();j++)
                        {
                            if(temp[k]==temp[j] || visited[temp[j]-97])
                            {
                                continue;
                            }
                            int size = maap[temp[j]-97].size();
                            if(maap[temp[j]-97][size-1]<index)
                            {
                                pushed = false;
                                break;
                            }
                        }
                        if(pushed)
                        {
                            
                            last  = index;
                            ans.push_back(temp[k]);
                            visited[i] = true;
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
