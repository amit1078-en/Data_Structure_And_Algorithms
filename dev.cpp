#include<bits/stdc++.h>
#define LOOP(i,n) for (int i = 1; i <= n; i++)
#define MOD 1000000007
#define endl '\n'
#define ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int  main()
{
	 vector<int> ans;
	 for(int i = 0; i<100;i++)
	 {
	 	ans.push_back(i);
	 }
	 cout<<ans[lower_bound(ans.begin(),ans.end(),89)-ans.begin()]<<endl;
}


