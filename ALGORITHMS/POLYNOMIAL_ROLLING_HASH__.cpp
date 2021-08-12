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
using namespace std;
ll polynomial_Rolling_hashing(string give)
{
	ll ans = 0;
	ll prime  = 1000003;
	ll p = 1;
	for(char ch : give)
	{
		ans = ans + ((ch-'a'+1)*p)%mod;
		ans = ans%mod;
		p = ((p%mod)*(prime%mod))%mod;
	}
	return ans;
}
using namespace std;
int  main()
{
	 ll test;
	 cin>>test;
	 while(test--)
	 {
		cout<<"Enter the string -> ";
		string aa;
		cin>>aa;
		if(aa=="." || aa==",")
		cout<<"\nInvalid choice \n";
		
		else
		cout<<"The hashing number calculated for given string is -> "<<polynomial_Rolling_hashing(aa)<<endl;
	 }
}


