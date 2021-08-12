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
ll test;
string temp;
ll arr[1000];
ll bower[1000];
ll bipower(ll a,ll r)
{
	ll ans = 1;
	while(r>0)
	{
		if(r&1)
		{
			ans = ((ans%mod)*(a%mod))%mod;
			r--;
		}
		else
		{
			a =  ((a)%mod *(a%mod))%mod;
			r/=2;
		}
	}
	return ans;
}
void precompute(string t)
{
	ll temp = 0;
	ll p = 1;
	ll pr = 31;
	for(int i=0 ; i<t.length();i++)
	{
		temp = temp+((t[i]-'a'+1)*p)%mod;
		bower[i] = (bipower(p,mod-2))%mod;
		p = (p*pr)%mod;
		cout<<bower[i]<<" ";
		arr[i] = temp;
	}
}
ll hash_value(ll l,ll r)
{
	ll ans;
	if(l==0 && r<temp.length())
	{
		return (arr[r])%mod;
	}
	if(r<temp.length())
	{
		return ((arr[r]-arr[l-1])*bower[l])%mod;
	}
	else
	{
		return -1;
	}
//	return ans;
}
bool substringhash(string tmp);
int  main()
{
	 cout<<"Enter the test cases -> ";
	 cin>>test;
	 cout<<"Enter the string -> ";
	 cin>>temp;
	 precompute(temp);
	 while(test--)
	 {
		ll l,r;
		cin>>l>>r;
		cout<<hash_value(l,r)<<endl;
	 }
}


