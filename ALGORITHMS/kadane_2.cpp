#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define ll long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
using namespace std;
int arr[26];
void permutation(int a,int b,int c)
{
	 for(int i = 0 ; i<26;i++)
	 {
	 	if(i%3==0)
	 	{
	 		arr[i] = a;
		}
		else if(i%3==1)
	 	{
	 		arr[i] = b;
		}
		else if(i%3==2)
	 	{
	 		arr[i] = c;
		}
	 }
}
int check(int array[],int len)
{
	int sum  = 0;
	int ans = INT_MIN;
	for(int i = 0 ; i<len;i++)
	 {
	 	sum = sum + array[i];
	 	if(sum<array[i])
	 	{
		 	sum = array[i];
		}
		ans =  max(ans,sum);
	 }
	 return ans;
}
int  main()
{
	ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		int array[1000000];
	 int len;
	 int ans = 0;
	 cin>>len;
	 int a,b,c;
	 cin>>a>>b>>c;
	 string temp;
	 cin>>temp;
	 permutation(a,b,c);
	 for(int i = 0 ; i<len;i++)
	 {array[i] = arr[temp[i]-97];}
	 int  n = check(array,len);
	 ans = max(n,ans);
	
	 permutation(a,c,b);
	 for(int i = 0 ; i<len;i++)
	 {array[i] = arr[temp[i]-97];}
	  n = check(array,len);
	 ans = max(n,ans); 
	 
	 permutation(c,a,b);
	 for(int i = 0 ; i<len;i++)
	 {array[i] = arr[temp[i]-97];}
	  n = check(array,len);
	 ans = max(n,ans); 
	 
	 permutation(c,b,a);
	 for(int i = 0 ; i<len;i++)
	 {array[i] = arr[temp[i]-97];}
	 int n = check(array,len);
	 ans = max(n,ans);
	 
	 permutation(b,a,c);
	 for(int i = 0 ; i<len;i++)
	 {array[i] = arr[temp[i]-97];}
	 int n = check(array,len);
	 ans = max(n,ans);

		 permutation(b,c,a);
	 for(int i = 0 ; i<len;i++)
	 {array[i] = arr[temp[i]-97];}
	 int n = check(array,len);
	 ans = max(n,ans);
	 
	 cout<<ans<<endl;
}


