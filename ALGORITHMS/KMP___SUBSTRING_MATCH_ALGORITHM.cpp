/*
28. Implement strStr()
Easy

2445

2453

Add to List

Share
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

 

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Example 3:

Input: haystack = "", needle = ""
Output: 0
 

Constraints:

0 <= haystack.length, needle.length <= 5 * 104
haystack and needle consist of only lower-case English characters.
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        // kmp algorithm substring searching
        int ind = -1;
        if(haystack.empty() && needle.empty()){
            return 0;
        }
        else if(needle.empty())
        {
            return 0;
        }
        else if(haystack==needle)
        {
            return 0;
        }
        else if(haystack.size()>=needle.size() && !haystack.empty() && !needle.empty()){
            int arr[needle.length()+2];
            int len = 0;
            arr[0] = 0;
            arr[1] = 0;
            for(int i = 1 ; i<needle.size(); i++){
                if(needle[i]==needle[len])
                {
                        len++;
                        arr[i+1] = len;
                }
                else if(len!=0){
                    len = arr[len-1+1];
                    i--;
                }
                else{
                    arr[i+1] = 0;
                    len = 0;
                }
            }
            reverse(needle.begin(),needle.end());
            needle.push_back('0');
            reverse(needle.begin(),needle.end());
            
            int j = 0;
            int end = needle.length()-2;
            int e = needle.size();
       
            for(int i = 0 ; i<haystack.length();i++){
                if(haystack[i]==needle[j+1])
                {
                    j++;
                }
                else
                {
                    if(j!=0)
                    {
                        j  = arr[j];
                        i--;
                    }
                }
                
                if(j+1==e)
                {
                    return i-end;
                }
            }
           
            
        }
        return ind;
    }
};
