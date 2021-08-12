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
ll Egcd(ll a ,ll b,ll *x,ll *y)
{
	if(b==0)
	{
		*x = 1;
		*y = 0;
		return a;
	}
	ll x1,y1;
	ll d = Egcd(b,a%b,&x1,&y1);
	*x = y1;
	*y = x1 -y1*(a/b);
	return d;
}
int  main()
{
	ll test;
	cin>>test;
	for(ll i=1;i<=test;i++)
	{
		 ll a,b,c;
		 cin>>a>>b>>c;
		 ll x,y;
		 ll ans = Egcd(a,b,&x,&y);
		 if(((a*(x*(c/ans)))+(b*(y*(c/ans))))==c)
		 {
		 		x = x*(c/ans);
				 y = y*(c/ans);
				 cout<<"Case "<<i<<": Yes"<<endl;
				 cout<<x<<" "<<y<<endl;
		 }
		 
		 else
		 
		 	cout<<"Case "<<i<<": No"<<endl;
	}
}

