/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a
 queen and an empty space, respectively.

 

Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 

Constraints:

1 <= n <= 9
*/

class Solution {
public:
    int ans;
     bool track[9][9];
    bool queen(int c,int r,int n)
    {
        bool fin = true;
        int i = r-1;
        while(i>=0)
        {
            if(track[i][c])
            {
                fin = false;break;
            }
            i--;
        }
        i = r-1;
        int j = c+1;
        while(i>=0 && j<n)
        {
             if(track[i][j])
            {
                fin = false;break;
            }
            i--;
            j++;
        }
        i = r-1;
        j = c-1;
        
          while(i>=0 && j>=0)
        {
             if(track[i][j])
            {
                fin = false;break;
            }
            i--;
            j--;
        }
        
        return fin;
    }
    void help(int n,int row)
    {
     //handle base case
         for(int i = 0 ;  i<n;i++)
         {
             track[row][i] = true;
             bool check = queen(i,row,n);
             if(check)
             {
                 if(row+1==n)
                 {
                     ans++;
                 }
                 else
                 {
                     help(n,row+1);
                 }
             }
             track[row][i] = false;
         }
        return ;
    }
    int totalNQueens(int n) {
        // this is basically a backtracking problem
        ans = 0
            // we are doing  
            memset(track,false,sizeof(n));
            help(n,0);
    
        //we are returing ans which is a global varaible 
        return ans;
    }
};
