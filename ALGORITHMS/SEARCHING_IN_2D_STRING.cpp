/*
Given a 2D grid of n*m of characters and a word, find all occurrences of given word in grid. A word can be matched in all 8 directions at any point. Word is said be found in a direction if all characters match in this direction (not in zig-zag form). The 8 directions are, horizontally left, horizontally right, vertically up, vertically down and 4 diagonal directions.
 

Example 1:

Input: grid = {{a,b,c},{d,r,f},{g,h,i}},
word = "abc"
Output: {{0,0}}
Expalnation: From (0,0) one can find "abc"
in horizontally right direction.
Example 2:

Input: grid = {{a,b,a,b},{a,b,e,b},{e,b,e,b}}
,word = "abe"
Output: {{0,0},{0,2},{1,0}}
Explanation: From (0,0) one can find "abe" in 
right-down diagonal. From (0,2) one can
find "abe" in left-down diagonal. From
(1,0) one can find "abe" in Horizontally right 
direction.
 

Your Task:
You don't need to read or print anyhting, Your task is to complete the function searchWord() which takes grid and word as input parameter and returns a list containg the positions from where the word can be find in any direction. If there is no such position then returns the empty list.

Note: the list should be lexicographically smallest. 
 

Expected Time Complexity: O(n*m*k) where k is constant
Exected Space Complexity: O(1)
 

Constraints:
1 <= n <= m <= 100
1 <= |word| <= 10
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    vector<vector<int>> answer;
	    int i = 0;
	    int row = grid.size();
	    int coloumn  = grid[0].size();
	    int len = word.length();
	    len--;
	    for(int i = 0 ; i<row;i++){
	        for(int j = 0 ; j<coloumn;j++)
	        {
	            if(grid[i][j]==word[0])
	            {
	                        vector<int> P;
            	            bool check = true;
            	            if(j>=len)
            	            {
            	                check = true;
            	                bool track = 0;
            	                //left side
            	                int z = 0;
            	                int limit = j-len;
            	                for(int k = j ;k>=limit;k--)
            	                {
            	                    if(word[z]!=grid[i][k])
            	                    {
            	                        check = false;
            	                        break;
            	                    }
            	                    z++;
            	                }
            	                if(check==true && P.empty()==true){
            	                    P.push_back(i);
            	                    P.push_back(j);
            	                    check = false;
            	                }
            	                else
            	                {
            	                    check = true;
            	                }
            	            }
            	            if(j+len<coloumn )
                    	     {
                    	         check = true;
                    	         //right side
                    	         bool track = 0;
            	                //left side
            	                int z = 0;
            	                int limit = j+len;
            	                for(int k = j ;k<=limit;k++){
            	                    if(word[z]!=grid[i][k])
            	                    {
            	                        check = false;
            	                        break;
            	                    } 
            	                    z++;
            	                }
            	                if(check==true && P.empty()==true)
            	                {
            	                    P.push_back(i);
            	                    P.push_back(j); 
            	                     check = false;
            	                }
            	                else
            	                {
            	                    check = true;
            	                }
                    	     }
                            if(i>=len )
                    	    {
                    	        check = true;
                    	       //upward  
                    	        bool track = 0;
            	                //left side
            	                int z = 0;
            	                int limit = i-len;
            	                for(int k = i ;k>=limit;k--)
            	                {
            	                    if(word[z]!=grid[k][j])
            	                    {
            	                        check = false;
            	                        break;
            	                    }
            	                    z++;
            	                }
            	                if(check==true && P.empty()==true)
            	                {
            	                    P.push_back(i);
            	                    check = false;
            	                    P.push_back(j); 
            	                }
            	               
                    	    }
                    	    
                    	    
                    	   if(len+i<row)
                    	   {
                    	       check = true;
                    	       //downward
            	                //left side
            	                int z = 0;
            	                int limit = i+len;
            	                for(int k = i ;k<=limit;k++)
            	                {
            	                    if(word[z]!=grid[k][j])
            	                    {
            	                        check = false;
            	                        break;
            	                    }
            	                    z++;
            	                }
            	                if(check==true && P.empty()==true)
            	                {
            	                    P.push_back(i);
            	                    P.push_back(j); 
            	                }
                    	   }
                    	   if(j>=len && i>=len )
                    	   {
                    	       check = true;
                    	       //upward and left
            	                //left side
            	                int z = 0;
            	                int limit = j-len;
            	                int c = i;
            	                for(int k = j ;k>=limit;k--)
            	                {
            	                    if(word[z]!=grid[c][k])
            	                    {
            	                        check = false;
            	                        break;
            	                    }
            	                    c--;
            	                    z++;
            	                }
            	                if(check==true && P.empty()==true)
            	                {
            	                    P.push_back(i);
            	                    P.push_back(j); 
            	                    check = false;
            	                }
            	                else
            	                {
            	                    check = true;
            	                }
                    	   }
                    	   if(j+len<coloumn && i+len<row )
                    	   {
                    	       check = true;
                    	       //download and right
                    	       bool track = 0;
            	                //left side
            	                int z = 0;
            	                int c = i;
            	                int limit = j+len;
            	                for(int k = j ;k<=limit;k++)
            	                {
            	                    if(word[z]!=grid[c][k])
            	                    {
            	                        check = false;
            	                        break;
            	                    }
            	                    c++;
            	                    z++;
            	                }
            	                if(check==true && P.empty()==true)
            	                {
            	                    P.push_back(i);
            	                    P.push_back(j); 
            	                    check = false;
            	                }
            	                else
            	                {
            	                    check = true;
            	                }
                    	   }
                     	   if(i-len>=0 && j+len<coloumn )
                    	   {
                    	       //upward and right
                    	        bool track = 0;
            	                //left side
            	                int z = 0;
            	                check = true;
            	                int limit = len+j;
            	                int w = i;
            	                for(int k = j ;k<=limit;k++)
            	                {
            	                    if(word[z]!=grid[w][k]  )
            	                    {
            	                        check = false;
            	                        break;
            	                    }
            	                    w--;
            	                    z++;
            	                }
            	                if(check==true && P.empty()==true)
            	                {
            	                    P.push_back(i);
            	                    P.push_back(j); 
            	                    check = false;
            	                }
            	                else
            	                {
            	                    check = true;
            	                }
                    	   }
                    	   if(j>=len && i+len<row )
                    	   {
                    	       check = true;
                    	       //download and left
                    	        bool track = 0;
            	                //left side
            	                int z = 0;
            	                int limit = j-len;
            	                int w = i;
            	                for(int k = j ;k>=limit;k--)
            	                {
            	                    if(word[z]!=grid[w][k] )
            	                    {
            	                        check = false;
            	                        break;
            	                    }
            	                    w++;
            	                    z++;
            	                }
            	                if(check==true && P.empty()==true)
            	                {
            	                    P.push_back(i);
            	                    P.push_back(j); 
            	                }
                    	   }
                    	   if(P.empty()==false)
            	            {
            	                answer.push_back(P);
            	            }
	            }
	        }
	        
	    }
	    vector<int> v1;
	    
	    return answer;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
	}
	return 0;
}
