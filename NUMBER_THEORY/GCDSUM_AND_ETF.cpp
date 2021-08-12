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
    	ll sum=0;
    	for(int i=1;i<=sqrt(number);i++)
    	{
    		if(number%i==0 )
    		{
    			int num1 = i * arr[number/i];
    			int num2 = (number/i)*arr[i]; 
    			sum+=num1;
    			if(i!=(number/i))
    			{
    				sum+=num2;
				}
			}
		}
    	cout<<sum;
    	cout<<endl;
	}
	return 0;
}

