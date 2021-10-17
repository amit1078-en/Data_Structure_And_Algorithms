/*
WORD SEARCH

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 

Follow up: Could you use search pruning to make your solution faster with a larger board?

*/
class Solution {
public:
    bool rec(int i,int j,int row,int col,string word,int k,vector<vector<char>>& board)
    {
        if(i<0 || j<0 || i==row || j==col)
        return false;
        
        if(k==word.size())
        return true;
        
        if(board[i][j]==' ')
        {
            return false;
        }
        
        bool ok=false;
        if(board[i][j]==word[k])
        {
            char v = board[i][j];
            if(k==word.size()-1)
            {
                return true;
            }
            board[i][j] = ' ';
            bool u = rec(i+1,j,row,col,word,k+1,board)||rec(i-1,j,row,col,word,k+1,board);
            bool m = rec(i,j+1,row,col,word,k+1,board)||rec(i,j-1,row,col,word,k+1,board);
            board[i][j] = v;
            ok = m||u;
        }
        return ok;
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        int row = board.size();
        int col = board[0].size();
        for(int i = 0; i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                if(board[i][j]==word[0] && rec(i,j,row,col,word,0,board))
                {
                    return true;
                }
            }
        }
        return  false;
    }
};
