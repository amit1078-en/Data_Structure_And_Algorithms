#include <iostream>
using namespace std;
void print2DArray(int **arr , int m ,int n) 
{
	int l = m;
	for(int i = 0  ;i<m;i++)
    {
        for(int k = 0;k<l;k++)
        {
	        for(int j = 0;j<n;j++)
	        {
	            cout<<arr[i][j]<<" ";
	        }
            cout<<"\n";
        }
        l--;
	}
}
int main() {
    int row, col;
    cin >> row >> col;

    int **input = new int*[row];
    for(int i = 0; i < row; i++) {
	    input[i] = new int[col];
	    for(int j = 0; j < col; j++) {
	        cin >> input[i][j];
	    }
    }
    print2DArray(input, row, col);
}

