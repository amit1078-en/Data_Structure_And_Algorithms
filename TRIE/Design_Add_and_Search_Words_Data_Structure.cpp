/*
211. Design Add and Search Words Data Structure
https://leetcode.com/problems/design-add-and-search-words-data-structure/

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 

Constraints:

1 <= word.length <= 500
word in addWord consists lower-case English letters.
word in search consist of  '.' or lower-case English letters.
At most 50000 calls will be made to addWord and search.
*/
class trie
{
    public:
        bool last;
        trie* next[26];
    trie()
    {
        last = false;
        for(int i = 0;i<26;i++)
        {
            next[i] = NULL;
        }
    }
};
class WordDictionary {
public:
    trie* root;
    WordDictionary() 
    {
        root = NULL;
    }
    
    void addWord(string word) 
    {
        if(root==NULL)
        {
            trie* r = new trie();
            root = r;
        }
        trie* temp = root;
        for(int i = 0; i<word.length();i++)
        {
            if(temp->next[word[i]-97]!=NULL)
            {
                temp = temp->next[word[i]-97];
            }
            else
            {
                trie* r = new trie();
               temp->next[word[i]-97]= r;
                temp = r;
            }
            if(i==word.length()-1)
            {
                temp->last = true;
            }
        }
    }
    bool rec(int ind,int len,string word,trie* root,bool &ans)
    {
        if(ind==len || root==NULL)
        {
            return false;
        }
        if(word[ind]=='.')
        {
            for(int i = 0;i<26;i++)
            {
                if(root->next[i]!=NULL)
                {
                    if(ind+1==len && root->next[i]->last)
                    {
                        ans = true;
                        return true;
                    }
                    rec(ind+1,len,word,root->next[i],ans);
                }
            }
        }
        else
        {
            if(root->next[word[ind]-97]!=NULL)
            {
                if(ind+1==len && root->next[word[ind]-97]->last)
                {
                    ans = true;
                    return true;
                }
                rec(ind+1,len,word,root->next[word[ind]-97],ans);
            }
        }
        return false;
    }
    bool search(string word) 
    {
        bool ans = false;
         rec(0,word.length(),word,root,ans);
        return  ans;
    }
    
};


