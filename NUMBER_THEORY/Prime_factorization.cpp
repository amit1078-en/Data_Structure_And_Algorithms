#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
ll	PrimeFactorization(ll number)
{
	ll count=0;
	ll ans =0;
	for(ll i=2;i<=sqrt(number);i++)
	{
		ll power = 0;
		if(number%i==0)
		{
			ans++;
			while(number%i==0)
			{
				
				power++;
				number/=i;
			}
			//cout<<i<<"^"<<power<<"  ";
		}
	}
	if(number>1)
	{
		//cout<<number<<"^1"<<endl;
		ans++;
	}
	cout<<ans<<",";
}
int main() {
    ll  test;
    cin>>test;
    ll number;
    while(test--)
    {
    	cout<<"Enter The Number-> ";
    	cin>>number;
    	cout<<"Prime Factorization of number is ->";
    	for(int i = 0 ; i<=1000000;i++)
    	{
    		PrimeFactorization(i);
		}
    	cout<<endl;
	}
	return 0;
}
