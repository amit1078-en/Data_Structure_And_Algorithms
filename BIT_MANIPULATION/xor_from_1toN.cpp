#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll  long long int
int main() {
//	ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
	ll test;
	 cin>>test;
	 while(test--)
	 {
	     ll num;
	     cin>>num;
	   		if(num&1)
	   		{
	   			if((num>>1)&1)
	   			cout<<0<<endl;
	   			else
	   			cout<<1<<endl;
			}
	   		else
	   		{	if((num>>1)&1)
	   			cout<<num+1<<endl;
	   			else
	   			cout<<num<<endl;
	   			
			   }
	 }
	return 0;
}

