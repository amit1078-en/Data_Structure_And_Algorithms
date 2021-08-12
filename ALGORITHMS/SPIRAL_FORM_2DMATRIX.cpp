/*
Spirally traversing a matrix 
Medium Accuracy: 48.39% Submissions: 39207 Points: 4
Given a matrix of size r*c. Traverse the matrix in spiral form.

Example 1:

Input:
r = 4, c = 4
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
Explanation:

link 



code  ->   https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/
*/
#include <bits/stdc++.h> 
using namespace std; 


class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> arr;
        // we will take 4 pointers named up down left and right for keeping track of pointers
        int up = 0;
        int down = r-1;
        int left = 0;
        int right = c-1;
        int l = 0;
        int y;
        if(r>=c)
        {
            y = c;
        }
        else
        {
            y = r;
        }
        y--;
        
        // we will traverse the loop unit smallest of (min(r,c)-1)/2;
        while(l<=y)
        {
        	// firstly we will traverse from  coloumn left to right of  row up and we also increment up
            for(int i = left ; i<=right;i++)
            {
                arr.push_back(matrix[up][i]);
            }
            up+=1;
            
            
            //then we will track from up to down row of right coloumn and decrement right
            for(int i  = up;i<=down;i++)
            {
                arr.push_back(matrix[i][right]);
            }
            right-=1;
            
            // we will check two conditions and traverse from right to left and then from down to up 
            if(right>=left && up<=down)
            {
                for(int j = right;j>=left;j--)
                {
                    arr.push_back(matrix[down][j]);
                }
            }
            down-=1;
            if(up<=down && right>=left)
            {
                for(int j = down;j>=up;j--)
                {
                    arr.push_back(matrix[j][left]);
                }  
            }
            left+=1;
            l+=1;
            y-=1;
        }
        return arr;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
