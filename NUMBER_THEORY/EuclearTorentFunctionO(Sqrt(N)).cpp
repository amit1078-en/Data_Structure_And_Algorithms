#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
ll	EuclearTorentFunction(ll number)
{
	ll ans = number;
	for(ll i=2;i<=sqrt(number);i++)
	{
		if(number%i==0)
		{
			ans*=(i-1);
			ans/=i;
			while(number%i==0)
			{
				number/=i;
			}
		}
	}
	if(number>1)
	{
		ans/=number;
		ans*=(number-1);
	}
	return ans;
}
int main() {
	
    ll  test;
    cin>>test;
    ll number;
    while(test--)
    {
    	cout<<"Enter The Number-> ";
    	cin>>number;
    	cout<<"Total Number From 1 To N (Which Are Coprime To N) Are -> ";
    	ll ans = EuclearTorentFunction(number);
    	cout<<ans<<endl;
	}
	return 0;
}

