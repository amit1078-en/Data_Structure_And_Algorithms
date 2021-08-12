/*
763. Partition Labels
Medium

4811

197

Add to List

Share
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Return a list of integers representing the size of these parts.

 

Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
Example 2:

Input: s = "eccbbbbdec"
Output: [10]
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.


https://leetcode.com/problems/partition-labels/
*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26];
        memset(last,0,sizeof(last));
        for(int i = s.length()-1;i>=0;i--){
            if(last[s[i]-97]==0){
                last[s[i]-97] = i;
            }
        } 
        vector<int> ans;
        int las = last[s[0]-97];
        bool check = false; 
        int start = 0;
        for(int i = 0 ;i<s.length() ; i++){
            if(i==las){
                ans.push_back(las-start+1);
                start = las+1;      
                
            }
            
                if(las<last[s[i]-97])
                {
                  
                    las  = last[s[i]-97];
                }
            
               if(start==las){
                     ans.push_back(las-start+1);
                    start = las+1;    
               } 
            
            
        }
        
        if(start==0){
            ans.push_back(s.length());
        }
        if(start==las && start==s.length()-1 && s.length()-1!=0)
        {
            ans.push_back(1);
        }
        return ans;
    }
};
