/*
Array of Doubled Pairs

Solution
Given an array of integers arr of even length, return true if and only if it is possible to reorder it such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2.

 

Example 1:

Input: arr = [3,1,3,6]
Output: false
Example 2:

Input: arr = [2,1,2,6]
Output: false
Example 3:

Input: arr = [4,-2,2,-4]
Output: true
Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].
Example 4:

Input: arr = [1,2,4,16,8,4]
Output: false
 

Constraints:

0 <= arr.length <= 3 * 104
arr.length is even.
-105 <= arr[i] <= 105
*/

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) 
    {
        int tot = arr.size()/2;
      
        map<int,int> help;
      int zero = 0;
        for(int i  =  0 ; i<arr.size();i++)
        {
          if(arr[i]==0)
          {
            zero+=1;
          }
          help[arr[i]]+=1; 
        }
        int total = 0;
        for(auto it = help.begin();it!=help.end();it++)
        {
          int value = it->first;
          int quan = it->second;
          if(quan==0)
          {
            continue;
          }
          if(help.find(value*2)!=help.end() && value!=value*2)
          {
            total+=min(quan,help[value*2]);
            if(quan>help[value*2])
            {
              help[value]-=help[value*2];
              help[value*2] =0;
            }
            else
            {
              help[value] = 0;
              help[value*2]-=quan;
            }
            
            
            
            
          }
        }
      total+=zero/2;
      if(total<tot)
      {
        return false;
      }
      return true;
    }
};
