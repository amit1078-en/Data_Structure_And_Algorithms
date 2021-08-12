/*
37. Sudoku Solver
Hard

3269

116

Add to List

Share
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

 

Example 1:


Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:


 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.
Accepted
257.5K
Submissions
526K
Seen this question in a real interview
*/

class Solution {
public:
    bool submatrix[10][10];
    bool row[10][10];
    bool col[10][10];
    bool track = true;
  vector<vector<char>> matrix;
  bool check(vector<vector<char>>& board,int r,int c,int val)
  {
    for(int j=  0;j<9;j++)
    {
      if(board[j][c]=='0'+val)
      {
        return false;
      }
    }
    for(int j=  0;j<9;j++)
    {
      if(board[r][j]=='0'+val)
      {
        return false;
      }
    }
    r = (r/3)*3;
    c = (c/3)*3;
    int k = 0;
    int j = 0;
    while(k<3)
    {
      j=0;
      while(j<3)
      {
        if(board[k+r][j+c]=='0'+val)
        {
          return false;
        }
        j++;
      }
      k++;
    }
    return true;
  }
    void rec(vector<vector<char>>& board,int r,int c)
    {
        if(c>=9)
        {
          r+=1;
          if(r==9)
          {
            track=true;
            matrix = board;
            return ;
          }
          c = 0;
          
        }
        
        if(board[r][c]!='.')
        {
          rec(board,r,c+1);
        }
        else
        {
          bool g = false;
            for(int j = 1;j<=9;j++){
              if(!check(board,r,c,j))
              {
                continue;
              }
              board[r][c]='0'+j;
              rec(board,r,c+1);
              if(track==true)
              {
                return ;
              }
              board[r][c]='.';
            }
         
        }
    }
  
    void solveSudoku(vector<vector<char>>& board) 
    { 
      track = false;
      rec(board,0,0);
      board = matrix;
    }
};
