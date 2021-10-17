#include<bits/stdc++.h>
#define LOOP(i,n) for (int i = 1; i <= n; i++)
#define MOD 1000000007
#define endl '\n'
#define ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;


int  main()
{
	 int row,col;
	 cin>>row>>col;
	 int arr1[row][col];
	 	 int arr2[row][col];
	 for(int i = 0;i<row;i++)
	 {
		for(int j = 0;j<col;j++)
		{
			cin>>arr1[i][j];
			arr2[i][j] = arr1[i][j];
		}
	 }


	int p,q;
	cin>>p>>q;
	int sum1,sum2;
	sum1 = sum2 = 0;
	for(int i = 0;i<col;i++)
	{
		if(p==i)
		{
			continue;
		}
		arr1[0][i] = 0;
	}
	int l = arr2[row-1][q];
	for(int i = 0;i<col;i++)
	{
	
		arr2[row-1][i] = 0;
	}
	arr2[row-1][q] = l;
	 
	 for (int i = 1; i < row; i++) {
        for (int j = 0; j < col; j++) {
 
            
            if (j > 0 && j < col - 1)
                arr1[i][j] += max(arr1[i - 1][j],
                             max(arr1[i - 1][j - 1],
                             arr1[i - 1][j + 1]));
 
         
            else if (j > 0)
                arr1[i][j] += max(arr1[i - 1][j],
                            arr1[i - 1][j - 1]);
 
         
            else if (j < col - 1)
                arr1[i][j] += max(arr1[i - 1][j],
                            arr1[i - 1][j + 1]);
 
      
        }
    }

    for (int j = 0; j < col; j++)
     {
     	   sum1 = max(arr1[row-1][j], sum1);
	 }
     
    
    
     for (int i = 1; i < row; i++) {
        for (int j = 0; j < col; j++) {
 
            
            if (j > 0 && j < col - 1)
                arr2[i][j] += max(arr2[i - 1][j],
                             max(arr2[i - 1][j - 1],
                             arr2[i - 1][j + 1]));
 
         
            else if (j > 0)
                arr2[i][j] += max(arr2[i - 1][j],
                            arr2[i - 1][j - 1]);
 
         
            else if (j < col - 1)
                arr2[i][j] += max(arr2[i - 1][j],
                            arr2[i - 1][j + 1]);
 
      
        }
    }
 
    for (int j = 0; j < col; j++)
    {
    	    sum2 = max(arr2[row-1][j], sum2);
	}

    
	cout<<max(sum1,sum2)<<"\n";
}


