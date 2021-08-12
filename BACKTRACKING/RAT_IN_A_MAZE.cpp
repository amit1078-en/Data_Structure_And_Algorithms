/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.
Example 2:
Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is 
blocked.
Your Task:  
You don't need to read input or print anything. 
Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters and returns the list of paths in 
lexicographically increasing order. 
Note: In case of no path, return an empty list. The driver will output "-1" automatically.

Expected Time Complexity: O((N2)4).
Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

Constraints:
2 = N = 5
0 = m[i][j] = 1
*/

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool check[6][6];
    void find(vector<string> &amit,int n,vector<vector<int>> m,string &temp,int x,int y){
        if(x+1==n && y+1==n){
            amit.push_back(temp);
           //temp.pop_back();
            return ;
        }
        if(x-1>=0){
            if(m[x-1][y]==1 && check[x-1][y]==false){
                check[x][y]=true;
                temp.push_back('U');
                find(amit,n,m,temp,x-1,y);
                if(!temp.empty())
                {
                    temp.pop_back();
                }
                 check[x][y]=false;
            }
            //upward 
        }
        if(y-1>=0){
            if(m[x][y-1]==1 && check[x][y-1]==false){
                check[x][y]=true;
                temp.push_back('L');
                find(amit,n,m,temp,x,y-1);
                  if(!temp.empty())
                {
                    temp.pop_back();
                }
                 check[x][y]=false;
            }
            //left
        }
        if(x+1<n){
            if(m[x+1][y]==1 && check[x+1][y]==false){
                check[x][y]=true;
                temp.push_back('D');
                find(amit,n,m,temp,x+1,y);
                if(!temp.empty())
                {
                    temp.pop_back();
                }
                 check[x][y]=false;
            }
            //donwward
        }
        if(y+1<n){
            if(m[x][y+1]==1 && check[x][y+1]==false){
                check[x][y]=true;
                temp.push_back('R');
                find(amit,n,m,temp,x,y+1);
                  if(!temp.empty())
                {
                    temp.pop_back();
                }
                 check[x][y]=false;
            }
            //rightward
        }
        return ;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> amit;
        string temp = "";
        memset(check,false,sizeof(check));
        if(m[0][0]==1){
            find(amit,n,m,temp,0,0);
        }
        
        if(amit.empty())
        amit.push_back("-1");
        
        else
        {
            sort(amit.begin(),amit.end());
        }
        return amit;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
