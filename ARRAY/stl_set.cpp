#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define int  long long 
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;
int32_t  main()
{
	int n;
	cin>>n;
	set<pair<int,int>> array;
	for(int  i = 0 ;i<n;i++)
	{
		int a;
		cin>>a;
		array.insert({i+1,a});
	}
	int q;
	cin>>q;
	while(q--)
	{
		int ans = 0;
		int x,k,y;
		cin>>x>>k;
		y = k;
		auto it  = array.lower_bound({x,0});
			while(it!=array.end() && k>0)
		{
			if(it->ss>k)
			{
				ans+=((k)*(it->ff-x));
				array.insert({it->ff,it->ss-k});
				k = 0;
			}
			else
			{
				ans+=((it->ss)*(it->ff-x));
				k-=it->ss;
						auto itr = it;
				it++;
				array.erase(itr);
			}
		}
			cout<<ans<<endl;
		}
		
		
	
	}



