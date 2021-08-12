#include<bits/stdc++.h> 
using namespace std; 
  
// Returns sum of XORs of all subsets 
int xorSum(int arr[], int n,int m) 
{ 
    int bits = 0; 
  
    // Finding bitwise OR of all elements 
    for (int i=0; i < n; ++i) 
        bits |= arr[i]; 
  
    int ans = bits * pow(2, m-1); 
  
    return ans; 
} 
  
// Driver code 
int main() 
{ 
	int t;
	cin>>t;
	int arr[t];
	for(int i = 0 ; i<t;i++)
	{
	   	cin>>arr[i];
	}
	int queries;
	cin>>queries;	
     while(queries--)
	{
	    
		int m;
		cin>>m;
		cout<<xorSum(arr,t,t)<<"\n";
	}
} 
