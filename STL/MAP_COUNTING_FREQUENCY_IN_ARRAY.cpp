/ { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

vector<int> countFreq(int a[], int n) ;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,sum=0;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    vector<int> v;
	    v = countFreq(arr, n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout<<'\n';
	}
	return 0;
}// } Driver Code Ends


vector<int> countFreq(int a[], int n) 
{ 
    map<int,int> amit;
    vector<int> kumar;
    for(int i = 0  ; i  < n ;i++ )
    {
        amit[a[i]]++;
    }
    for(auto i = amit.begin();i!=amit.end();i++)
    {
        int l  = i->second;
        kumar.push_back(l);
    }
    return kumar;
} 
