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
	ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	 ll test;
	 cin>>test;
	 while(test--)
	 {
		ll size;
		cin>>size;
		vector<int> arr;
		for(int i = 0 ; i <  size;i++)
		{
			int t;
			cin>>t;
			arr.push_back(t);
		}
		sort(arr.begin(),arr.end());
		int count = 0;
		bool ans = false;;
		for(int i = 0 ;  i <size  ;i++)
		{
			if(arr[i]>i+1)
			{
				ans= true;
			}
			else
			{
				count = count  + i+1-arr[i];
			}
		}
		if(ans==false)
		{
			if(count&1)
			{
				cout<<"First"<<endl;
			}
			else
			{
				cout<<"Second"<<endl;
			}
		}
		else
		{
			cout<<"Second"<<endl;
		}
	 }
}


