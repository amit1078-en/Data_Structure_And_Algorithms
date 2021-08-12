#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
bool sieve[100001];
bool segments[1000001];
ll arr[1000001];
ll x = 0;
void sievealgo()
{
	memset(sieve,false,sizeof(sieve));
	sieve[0] = sieve[1] = true;
	for(ll i=2;i<=100000;i++)
	{
		if(sieve[i]==false)
		{
			arr[x] = i;
			x++;
			for(ll j=2*i;j<=100000;j+=i)
			{
				sieve[j]  = true;
			}
		}
	}
}
void segmentsieve(ll left,ll right){
		memset(segments,false,sizeof(segments));
	for(ll i=0;i<x && arr[i]<=sqrt(right);i++)
	{
		ll l = left;
		while(l%arr[i]!=0)
		{
			l++;
		}
		for(ll k = l ; k<=right ; k+=arr[i])
		{
			if(k!=arr[i])
			{
					segments[k-left] = true;  
			}
		} 
	}
	for(ll i = left ; i<=right ; i++)
	{
		if(segments[i-left] == false)
		{
			cout<<i<<endl;
		}
	}
}
int main()
{
	sievealgo();
	int test;
	cin>>test;
	while(test--)
	{
		ll left,right;
		cin>>left>>right;
		if(left==1)
		{
			left++;
		}
		segmentsieve(left,right);
		cout<<endl;
	}
}
