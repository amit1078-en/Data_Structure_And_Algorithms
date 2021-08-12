#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define x first
#define y second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define int long long
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;
vi leaves;
bool vis[1000009];
void dfs(vector<ii> adj[],int u, int c,int val)
{
    vis[u]=true;
    bool ok = true;
    //cout<<u<<' ';
    for(auto i : adj[u])
    {
    	int f = i.x;
        if(!vis[f])
        {
            dfs(adj,i.first,c+1,val + i.second*c);
            ok=false;
        }
    }
    if(ok)
    {
        //cout<<u<<'\n';
        leaves.push_back(val);
    }
}
int32_t main()
{
	 int  test;
	 cin>>test;
	 while(test--)
	 {
	 	leaves.clear();
		int  path,n;
		cin>>path>>n;
		vector<int> que;
		for(int i = 0 ; i<n;i++)
		{
			int t;
			cin>>t;
			que.push_back(t);
		}
		vector<ii> adj[path+2];
		for(int i = 0 ; i<path-1;i++)
		{
			int x,y,val;
			cin>>x>>y>>val;
			adj[x].push_back({y,val});
			adj[y].push_back({x,val});
		}
		sort(que.begin(),que.end());
		int  ans = 0;
		memset(vis,false,sizeof(vis));
		dfs(adj,1,1,0);
		sort(leaves.begin(),leaves.end());
		int f = 0;
		int s = 0;
		while(f<n && s<leaves.size())
		{
			if(que[f]>=leaves[s])
			{
				ans++;
				f++;
				s++;
			}
			else
			{
				f++;
			}
		}
		cout<<ans<<endl;
	 }
}


