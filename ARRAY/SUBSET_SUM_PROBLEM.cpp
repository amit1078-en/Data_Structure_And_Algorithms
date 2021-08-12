/*
Partition Equal Subset Sum 
Medium Accuracy: 38.0% Submissions: 33144 Points: 4
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explaination: 
The two parts are {1, 5, 5} and {11}.
*/
#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define ll long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;
int  main()
{
	while(1)
	{
		int n;
		cout<<"\n Enter size-> ";
		cin>>n;
		int arr[n+1];
		int sum = 0;
		cout<<endl;
		for(int i =0 ; i<n;i++) cin>>arr[i],sum+=arr[i];
		cout<<endl;
		cout<<"\nEnter the given subset sum you want to check if exist in array of not -> ";
		int given ;
		cin>>given;
		
		bool dp[n+1][sum+1];
		
		for(int i = 0 ;i<sum+1;i++)dp[0][i] = false;
		
		for(int i = 0 ;i<n+1;i++)dp[i][0] = true;
		
		for(int i = 1;i<=n;i++)
		{
			for(int j = 1;j<=sum;j++)
			{
				if(arr[i-1]<=j)
				{
					dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
				}
				else
				{
					dp[i][j] = dp[i-1][j];
				}
			}
		}
		if(given > sum)
		{
			cout<<"\n check weather given subset sum exist is false";
		}
		else
		{
			if(dp[n][given]==true) cout<<"\n Given sum Exist\n";
			
			else cout<<"\n It dosnt exist \n";
		}
	}
}


