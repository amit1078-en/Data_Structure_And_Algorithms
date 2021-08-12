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
int arr[10000];
int x = -1;
int binary_search(int find,int left,int right)
{
	if(left<=right)
	{
		int mid = (left+right)/2;
		if(arr[mid]==find)
		{
			x = mid;
		}
		else if(arr[mid]>find)
		{
			binary_search(find,left,mid-1);
		}
		else
		{
			binary_search(find,mid+1,right);
		}
	}
}
int main()
{
	int size;
	cin>>size;
	for(int i =  0 ; i<size;i++)
	{
		cin>>arr[i];
	}
	while(1)
	{
		x = -1;
		int element;
		cin>>element;
		int val = 1;
		int left = 0;
		while(1)
		{
			if(arr[val]<element)
			{
				left = val;
				val = val*2;
			}
			else
			{
				break;
			}
		}
		binary_search(element,left,val);
		if(x==-1)
		{
			cout<<"\n element is not present in the array \n";
		}
		else
		{
			cout<<"\n "<<element <<" is present at position "<<x;
		}
	}
}
