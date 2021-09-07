/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
 

Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.
*/

class trie
{
  public:
    bool last;
    trie* next[26];
    trie()
    {
      for(int i = 0;  i<26;i++)
      {
        next[i] = NULL;
      }
     last = false; 
    }
};


class Trie {
public:
    trie* root;
    /** Initialize your data structure here. */
    Trie() {
       trie* temp = new trie();
      root = temp;
    }
    
    /** Inserts a word into the trie. */
    void insert(string Word) {
        trie* word = root;
        for(int i = 0;i<Word.length();i++)
        {
          int val =  Word[i]-'a';
          if(word->next[val]==NULL)
          {
            trie* temp =  new trie();
            word->next[val] = temp;
            word = temp;
          }
          else
          {
            word = word->next[val];
          }
          
          if(i==Word.length()-1)
          {
            word->last = true;
          }
        }
      
    }
    
    /** Returns if the word is in the trie. */
    bool search(string Word) {
      trie* word = root;
        for(int i = 0;i<Word.length();i++)
        {
          int val =  Word[i]-'a';
          if(word->next[val]==NULL)
          {
            return false;
          }
          else
          {
            word = word->next[val];
          }
        }
      return word->last;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string Word) {
      trie* word = root;
        for(int i = 0;i<Word.length();i++)
        {
          int val =  Word[i]-'a';
          if(word->next[val]==NULL)
          {
            return false;
          }
          else
          {
            word = word->next[val];
          }
        }
      return true;
    }
};
