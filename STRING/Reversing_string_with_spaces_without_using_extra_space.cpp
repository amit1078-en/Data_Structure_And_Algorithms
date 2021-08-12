/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
Example 4:

Input: s = "  Bob    Loves  Alice   "
Output: "Alice Loves Bob"
Example 5:

Input: s = "Alice does not even like bob"
Output: "bob like even not does Alice"
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
 

Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?
*/
class Solution {
public:
    string reverseWords(string s) {
        while(!s.empty() && s[s.length()-1]==' ')
        {
          s.pop_back();
        }
        reverse(s.begin(),s.end());
        while(!s.empty() && s[s.length()-1]==' ')
        {
          s.pop_back();
        }
        for(int i = 0;  i<s.length();i++)
        {
          if(s[i]!=' ')
          {
            int j = i+1;
          while(j<s.length() && s[j]!=' ')
          {
            j++;
          }
          
          int k = j-1;
          for(int h = 0;h<=(k-i)/2;h++)
          {
            swap(s[h+i],s[k-h]);
          }
          i = k;  
          }
        }
        int start = 0;
        while(start<s.length() && s[start]!=' ')
        {
          start+=1;
        }
        start+=1;
        int index = start;
        for(int i = start ; i<s.length();i++)
        {
          int k = i;
          while(k<s.length() && s[k]==' ')
          {
           k++; 
          }
          while(k<s.length() && s[k]!=' '){
            s[index] = s[k];
            k+=1;
            index+=1;
          }
          
          if(k<s.length())
          {
            s[index] = ' ';
                        index+=1;
          }
         
          i = k;
        }
        int l = s.length()-1;
        while(l>=index)
        {
          s.pop_back();
          l-=1;
        }
        
      return s;
    }
};
