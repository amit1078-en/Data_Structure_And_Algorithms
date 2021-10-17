/*
STRING ZIG ZAG PATTERN
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
 

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        
        int vis[s.length()];
        memset(vis,-1,sizeof(vis));
        for(int i = numRows;i<s.length();i+=numRows+numRows-2)
        {
            int j = numRows-2;
            for(int k = i;k-i<numRows && k<s.length();k+=1)
            {
                
                vis[k] = j;
                j-=1;
            }
            
        }
        map<int,string> maap;
        for(int i = 0;i<s.length();i++)
        {
            if(vis[i]==-1)
            {
                maap[i%(numRows+numRows-2)].push_back(s[i]);
            }
            else
            {
                maap[vis[i]].push_back(s[i]); 
            }
        }
        s.clear();
        for(auto it = maap.begin();it!=maap.end();it++)
        {
            s+=it->second;
        }
        return s;
    }
};

