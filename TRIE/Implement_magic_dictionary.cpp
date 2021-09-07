// trie class
/*

Design a data structure that is initialized with a list of different words. Provided a string, you should determine if you can change exactly one character in this string to match any word in the data structure.

Implement the MagicDictionary class:

MagicDictionary() Initializes the object.
void buildDict(String[] dictionary) Sets the data structure with an array of distinct strings dictionary.
bool search(String searchWord) Returns true if you can change exactly one character in searchWord to match any string in the data structure, otherwise returns false.
 

Example 1:

Input
["MagicDictionary", "buildDict", "search", "search", "search", "search"]
[[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
Output
[null, null, false, true, false, false]

Explanation
MagicDictionary magicDictionary = new MagicDictionary();
magicDictionary.buildDict(["hello", "leetcode"]);
magicDictionary.search("hello"); // return False
magicDictionary.search("hhllo"); // We can change the second 'h' to 'e' to match "hello" so we return True
magicDictionary.search("hell"); // return False
magicDictionary.search("leetcoded"); // return False
 

Constraints:

1 <= dictionary.length <= 100
1 <= dictionary[i].length <= 100
dictionary[i] consists of only lower-case English letters.
All the strings in dictionary are distinct.
1 <= searchWord.length <= 100
searchWord consists of only lower-case English letters.
buildDict will be called only once before search.
At most 100 calls will be made to search.

*/

class trie
{
  public:
    bool last;
    trie* next[26];
    trie()
    {
      last = true;
      for(int i = 0 ; i<26;i++)
      {
        next[i] = NULL;
      }
    }
};


class MagicDictionary {
    public:
    unordered_set<string> maap;
    trie* root;
  
    MagicDictionary() {
      maap.clear();
      trie* create = new trie();
      root = create;
    }
    
    void insert(string s)
    {
      trie* curr = root;
      for(int i = 0 ; i<s.length();i++)
      {
          int val = s[i]-'a';
          if(curr->next[val]==NULL)
          {
            trie* temp = new trie();
            curr->next[val] = temp;
            curr = temp;
          }
          else
          {
            curr = curr->next[val];
          }
      }
      curr->last = true;
    }
    void buildDict(vector<string> dictionary) 
    {
        for(string s:dictionary)
        {
            maap.insert(s);
            insert(s);
        }
    }
    
    bool search(string s) {
        trie* curr = root;
        
      for(int i = 0 ; i<s.length();i++)
      {
          int val = s[i]-'a';
          if(curr->next[val]==NULL)
          {
            for(int j = 0 ;j<26;j++)
            {
              if(val==j)
              {
                continue;
              }
              if(curr->next[j]!=NULL)
              {
                s[i] = j+'a';
                  string newword = s;

                if(maap.find(newword)!=maap.end())
                {
                  return true;
                }
              }
            }
            return false;
            
          }
          else
          {
            char d = s[i];
            s[i] = d;
            for(int j = 0 ;j<26;j++)
            {
              if(val==j)
              {
                continue;
              }
              if(curr->next[j]!=NULL)
              {
                s[i] = j+'a';
                  string newword = s;

                if(maap.find(newword)!=maap.end())
                {
                  return true;
                }
              }
            }
            
            s[i] = d;
            curr = curr->next[val];
            
          }
      }
      return false;
    }
};


