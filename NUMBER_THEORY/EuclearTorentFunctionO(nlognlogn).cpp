#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
int arr[1000001];
void precompute()
{
	for(int i=1;i<1000001;i++)
	{
		arr[i]=i;
	}
	for(int i=2;i<1000001;i++)
	{
		if(arr[i]==i)
		{
			for(int j=i;j<1000001;j+=i)
			{
				arr[j]/=i;
				arr[j]*=(i-1);
			}
		}
	}
}
int main() {
	precompute();
    ll  test;
    cin>>test;
    ll number;
    while(test--)
    {
    	cout<<"Enter The Number-> ";
    	cin>>number;
    	cout<<"Prime Factorization of number is ->";
    	cout<<arr[number]<<endl;
	}
	return 0;
}

