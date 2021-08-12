#include<bits/stdc++.h>
using namespace std;
class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    int row,coloumn;
	    row  = 0;
	    coloumn = M-1;
	    while(row<N && coloumn>=0)
	    {
	        if(mat[row][coloumn]==X)
	        {
	            return 1;
	            break;
	        }
	        if(mat[row][coloumn]>X)
	        {
	             coloumn--;
	        }
	        else if(mat[row][coloumn]<X)
	        {
	            row++;
	        }
	    }
        return 0;
	    
	}
};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}

