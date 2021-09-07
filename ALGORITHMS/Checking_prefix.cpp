/*

link -> https://leetcode.com/submissions/detail/543537776/


Given a sentence that consists of some words separated by a single space, and a searchWord, check if searchWord is a prefix of any word in sentence.

Return the index of the word in sentence (1-indexed) where searchWord is a prefix of this word. If searchWord is a prefix of more than one word, return the index of the first word (minimum index). If there is no such word return -1.

A prefix of a string s is any leading contiguous substring of s.

 

Example 1:

Input: sentence = "i love eating burger", searchWord = "burg"
Output: 4
Explanation: "burg" is prefix of "burger" which is the 4th word in the sentence.
Example 2:

Input: sentence = "this problem is an easy problem", searchWord = "pro"
Output: 2
Explanation: "pro" is prefix of "problem" which is the 2nd and the 6th word in the sentence, but we return 2 as it's the minimal index.
Example 3:

Input: sentence = "i am tired", searchWord = "you"
Output: -1
Explanation: "you" is not a prefix of any word in the sentence.
Example 4:

Input: sentence = "i use triple pillow", searchWord = "pill"
Output: 4
Example 5:

Input: sentence = "hello from the other side", searchWord = "they"
Output: -1
 

Constraints:

1 <= sentence.length <= 100
1 <= searchWord.length <= 10
sentence consists of lowercase English letters and spaces.
searchWord consists of lowercase English letters.

*/
class Solution {
public:
    bool found(string a,string b)
    {
      int i = 0;
      while(i<b.length())
      {
        if(a[i]!=b[i])
        {
          return false;
        }
        i++;
      }
      return true;
    }
    int isPrefixOfWord(string sentence, string searchWord) {
      sentence.push_back(' ');
      string temp;
      int w = 0;
      for(int i = 0 ; i<sentence.length();i++)
      {
        if(sentence[i]==' ')
        {
          
          if(temp.length()>=searchWord.length())
          {
            bool check = found(temp,searchWord);
            if(check)
            {
              return w+1;
            }
          }
          w++;
          temp.clear();
        }
        else
        {
          temp.push_back(sentence[i]);
        }
      }
      return -1;
    }
};