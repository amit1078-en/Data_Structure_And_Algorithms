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
//ll arr[1000001];
//ll bower[1000001];
//void precompute(string t)
//{
//	memset(bower,0,sizeof(bower));
//	memset(arr,0,sizeof(arr));
//	ll temp = 0;
//	ll p = 1;
//	ll pr = 1000003;
//	for(int i=0 ; i<t.length();i++)
//	{
//		temp = temp+((t[i]-'a'+1)*p)%mod;
//		bower[i] = p%mod;
//		p = (p*pr)%mod;
//		arr[i] = temp%mod;
//	}
//}
//void hash_value(ll temp,string ans,ll n,string sub)
//{
//	int flag=0;
//
//			for(int i = 0 ;i+n-1<ans.length();i++)
//			{
//				if(i==0)
//				{
//					if((arr[n-1]+mod)%mod == ((bower[0])*(temp%mod))%mod)
//					{
//						cout<<i<<endl;
//					}
//				}
//				else
//				{
//				//	cout<<arr[n+i-1]-arr[i-1]<<" "<<(bower[i]%mod *   temp%mod)%mod<<" ";
//					if((arr[n+i-1]-arr[i-1]+mod)%mod == (bower[i]*temp)%mod) 
//					{
//						cout<<i<<endl;
//					}
//				}
//			}
//}
int  main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	 cin>>test;
	 while(test--)
	 {
	 	string ss = "";
		string sub = "";
	 	int n;
	 	cin>>n;
	 	cin>>sub>>ss;
	 	for(int i  = 0 ;i+n-1<ss.length();i++)
	 	{
	 		if(sub[0]==ss[i] )
	 		{
	 			int flag=1;
	 			for(int j = 0;j<n;j++)
	 			{
	 				if(sub[j]!=ss[i+j])
	 				{
	 					flag=0;
	 					break;
					 }
				 }
				 if(flag==1)
				 {
				 	cout<<i<<endl;
				 }
			}
		 }
		cout<<endl;
	 }
}

