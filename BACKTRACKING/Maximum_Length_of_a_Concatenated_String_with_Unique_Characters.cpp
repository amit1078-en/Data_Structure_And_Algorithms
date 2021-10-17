/*
  Maximum Length of a Concatenated String with Unique Characters



Given an array of strings arr. String s is a concatenation of a sub-sequence of arr which have unique characters.

Return the maximum possible length of s.

 

Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All possible concatenations are "","un","iq","ue","uniq" and "ique".
Maximum length is 4.
Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible solutions are "chaers" and "acters".
Example 3:

Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
 

Constraints:

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] contains only lower case English letters.
*/
class Solution {
public:
    int ans;
    bool check(int array[],string s)
    {
        for(int i = 0; i<s.length();i++)
        {
            if(array[s[i]-'a']>0)
            {
                return false;
            }
            
        }
        return true;
    }
    void rec(vector<string>& arr,int array[],int size,int i,int tot)
    {
        if(i==size)
        {
            ans = max(ans,tot);
            return ;
        }
        if(check(array,arr[i]))
        {
            for(char k:arr[i])
            {
                array[k-'a']+=1;
            }
            string t = arr[i];
            rec(arr,array,size,i+1,tot+t.length());
            for(char k:arr[i])
            {
                array[k-'a']-=1;
            }
        }
        rec(arr,array,size,i+1,tot);
    }
    int maxLength(vector<string>& arr) 
    {
        int array[26];
        ans = 0;
        memset(array,0,sizeof(array));
        vector<string> cc;
        for(string temp:arr)
        {
            bool breaak = false;
            int af[26];
            memset(af,0,sizeof(af));
            for(int i=0;i<temp.length();i++)
            {
                af[temp[i]-'a']+=1;
            }
            for(int i = 0;i<26;i++)
            {
                if(af[i]>1)
                {
                    breaak = true;
                    break;
                }
            }
            if(!breaak)
            {
                    cc.push_back(temp);
            }
        }
       rec(cc,array,cc.size(),0,0);
       return ans;
    }
};
