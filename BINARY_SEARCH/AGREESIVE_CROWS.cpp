/*
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
*/
#include<bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++)
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
int element;
bool check(int arr[],int mid,int crows,int size)
{
	int c = 0;
	int s = 1;
	int l = arr[0];
	for(int i = 1 ;i<size;i++)
	{
		if(l+mid<=arr[i])
		{
			element = min(element,arr[i]-l);
			l = arr[i];
			c = 0;
			s++;
		}
	}
	if(s<crows)
	return false;
	
	else
	return true;
}
int  main()
{
	ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	 ll test;
	 cin>>test;
	 while(test--)
	 {
	 	int size,crows;
	 	cin>>size>>crows;
	 	int arr[size];
	 	int i = 0;
	 	REP(i,size)cin>>arr[i];
	 	sort(arr,arr+size);
	 			int ans = INT_MIN;	
			int left = 0;
			int right = arr[size-1]-arr[0]+1;
			while(left<=right)
			{
				int mid = (left+right)/2;
				element = INT_MAX;
				bool track = check(arr,mid,crows,size);
				
				if(track==true)
				{
						left = mid+1;
						ans = element;
				}
				else
				{
					right = mid-1;
				}
			}
			cout<<ans<<endl;
	 }
}


