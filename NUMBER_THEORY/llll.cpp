#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long 
int countBits( int n) 
{ 
   int count = 0; 
   while (n>0) 
   { 
        count++; 
        n >>= 1; 
    } 
    return count; 
} 
int main() {
	ll size,k;
	cin>>size>>k;
	ll arr[size];
	ll temp;
	cin>>arr[0];
	ll prev = arr[0];
	for(ll i = 1 ; i<size ; i++)
	{
		cin>>temp;
	    arr[i] = temp^prev;
	    prev=temp;
	}
	
	ll i = 0;
	ll count = 0;
	
	for(ll i = 0;i<size;i++)
	{
		if(arr[i]&(1<<(k-1)))
		count++;
	}
	cout<<count<<endl;
	return 0;
}

