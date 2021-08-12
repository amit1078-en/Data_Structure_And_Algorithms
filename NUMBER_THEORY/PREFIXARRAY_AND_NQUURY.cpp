#include <iostream>
using namespace std;
#define ll long long int
#define endl "\n"
int main() {
	int test;
	cin>>test;
	while(test--)
	{
	    int num,query;
	    int arr3[100000];
	    int arr4[10000];
		   cin>>num>>query;
	    int arr[num];
	    ll sum = 0;
	    ll prefix[num];
	    for(int i=0;i<num;i++)
		{
			 cin>>arr[i];
	        sum+=arr[i];
	        prefix[i]=sum;	
	       	if(arr[i]<100000)
	        	arr3[arr[i]] = i;
	        if(arr[i]>=100000)
	        	arr4[100000-arr[i]]=i;
		}
		ll ar[query];
	   for(int k = 0;k<query;k++)
	   {
	   		int search ; 
	   		cin>>search;
	   		if(search<100000)
	   			{
	   					if(prefix[arr3[search]]>sum - prefix[arr3[search]] + search)
	   				ar[k] = sum- prefix[arr3[search]] + search;		
	   				else
	   				ar[k] = prefix[arr3[search]];
				   }
			else
			{
					if(prefix[arr4[100000-search]]>sum - prefix[100000-arr4[search]] + search)
	   				ar[k] = prefix[arr4[100000-search]] + search;		
	   				else
	   				ar[k] = prefix[arr4[100000-search]];
			}
	   }
	   for(int k = 0;k<query;k++)
	   {
	       cout<<ar[k]<<endl;
	   }
	}
	return 0;
}

