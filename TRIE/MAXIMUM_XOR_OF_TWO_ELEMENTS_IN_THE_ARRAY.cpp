//question

/*
Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

 

Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.
Example 2:

Input: nums = [0]
Output: 0
Example 3:

Input: nums = [2,4]
Output: 6
Example 4:

Input: nums = [8,10,2]
Output: 10
Example 5:

Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127
 

Constraints:

1 <= nums.length <= 2 * 105
0 <= nums[i] <= 231 - 1
Accepted
*/


//implementation of the code
class trie{
  public:
  trie* val[2];
  trie(){
    val[0] = val[1] = NULL;
  }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mx = 0;
        int ans = INT_MIN;
        
      
        //finding out the max length in bits of each element in the array
        for(int i :nums)
        {
          int h = 0;
          if(i>0)
          {
            h = log2(i);
          }
          mx = max(mx,h);
        }
      
        //creating the parent of trie
        trie* parent = new trie();
        
      
        // traveresing the array
        for(int i = 0 ; i<nums.size();i++)
        {
          
          
          
          
            // taking the string t and filling them with thier bitwise values
            string t;
            int num = nums[i];
            while(num>0)
            {
              if(num&1)
              {
                t.push_back('1');
              }
              else
              {
                t.push_back('0');
              }
              num = num/2;
            }
          int n = mx-t.length()+1;
          while(n>0)
          {
            t.push_back('0');
            n--;
          } 
          
          
          //now inserting the bit values in the trie
          trie* curr  = parent;
          for(int j = mx;j>=0;j--)
          {
            int v = t[j]-'0';
            if(curr->val[v]==NULL)
            {
              trie* newn = new trie();
              curr->val[v] = newn;
              curr = newn;
            }
            else
            {
              curr = curr->val[v];
            }
          }
          
          
          
          // now checking for the largest oppsite bit wise values in the trie
          int yy =0;
          curr = parent;
           for(int j = mx;j>=0;j--)
             {
                   int v = t[j]-'0';
                    if(v==0)
                    {
                      v = 1;
                    }
                    else 
                    {
                      v = 0;
                    }
               if(curr->val[v]!=NULL)
               {
                 yy+=(pow(2,j));
                 curr = curr->val[v];
               }
               else
               {
                 curr = curr->val[t[j]-'0'];
               }
             }
          
          ans = max(ans,yy);
        }
        
      
      
      return ans;
    }
};
