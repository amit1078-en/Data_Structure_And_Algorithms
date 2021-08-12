#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;
ll mult(ll a,ll b,ll c)
{
	ll x = 0;
	ll y  = a%c;
	while(b>0)
	{
		if(b%2==1)
		{
			x = (x+y)%c;
			b--;
		}
		y = (y*2ll)%c;
		b/=2;
	}
	return x%c;
}
ll fastexponentiation(ll num,ll power,ll mod)
{
	ll res = 1;
	num=num%mod;
	while(power)
	{
		if(power&1)
		{
		    res	=  mult(res,num,mod);
			power--;
		}
		else
		{
			num = mult(num,num,mod);
			power/=2;
		}
	}
	return res%mod;
}
bool checkprime(ll num,int range)
{
	if(num<=4)
	{
		return num==3  || num==2;
	}
	else
	{
		ll flag=0;
		for(ll i=2;i<=range+2;i++)
		{
			
			ll a = 2+rand()%(num-3);
			ll ans = __gcd(a,num);
			if(ans == 1)
			{
				ll q=fastexponentiation(a,num-1,num);
				if(q!=1)
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		return true;
	}
}
int  main()
{
	ll num;
	cin>>num;
	while(num--)
	{
		ll number;
		cin>>number;
		bool ans  = checkprime(number,7);
		if(ans == true)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}
	return 0;
}
