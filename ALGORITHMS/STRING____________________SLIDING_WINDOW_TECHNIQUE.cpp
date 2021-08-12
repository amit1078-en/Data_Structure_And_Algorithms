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

//SLIDING WINDOW TECHNIQUE ALGORITHM HAS 2 POINTERS USING WHICH WE CAN FIND THE MAXIMUM OR MINIMUM INDEX IN ARRAY OR LINKEDLIST's
{
//	ios_base::sync_with_stdio(false);
//		cin.tie(NULL);
	 ll test;
	 cin>>test;
	 while(test--)
	 {
			ll N,K,D;
			cin>>N>>K>>D;
			ll inf[N+1];
			for(ll i  = 0 ; i<N		;i++)
			{
				cin>>inf[i];
			}
			ll count = 0;
			ll start = 0 ;
			ll end = 0;
			ll s = 0;
			ll n = 0;
			while(end<N)
			{
				
				if(inf[end]>=D)
				{
					end++;
				}
				else
				{
					if(s<=K)
					{
						s++;
						end++;
					}
					if(s>K)
					{
						while(s>K)
						{
							if(inf[start]<D)
							{
								s--;
							}
							start++;
						}
					}	
				}
				count = max(count,end-start);
			}
			cout<<count<<endl;
	 }
}


