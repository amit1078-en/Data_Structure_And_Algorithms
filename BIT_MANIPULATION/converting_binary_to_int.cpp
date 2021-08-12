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
int help(string temp)
{
	int ans = 0;
	int ind = 0;
	while(temp[ind]!='1')ind++;
	
	int p = 0;
	
	for(int i = temp.length()-1;i>=ind;i--)
	{
		if(temp[i]=='1')
		{
			ans+=(pow(2,p));
		}
		p++;
	}
	
	return ans;
}
int  main()
{
	 ll test;
	 cin>>test;
	 while(test--)
	 {
			string temp;
			cout<<"\n Enter the string -> ";
			cin>>temp;
			cout<<"Its decimal equivalance is "<<help(temp);
	 }
}


