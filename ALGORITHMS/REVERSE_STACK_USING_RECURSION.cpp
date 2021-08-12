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
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;
stack<int> arr;
string temp;
void insert_in_string(int data)
{
	temp.push_back('_');
	string a = "";
	stringstream geek;
	geek<<data;
	geek>>a;
	for(int i  = 0;i<a.length();i++)
	{
		temp.push_back(a[i]);
	}
	
}
void reverse()
{
	if(arr.empty()==true)
	{
		return ;
	}
	int data = arr.top();
	arr.pop();
	reverse();
	insert_in_string(data);
}
int  main()
{																																																			
//	ios_base::sync_with_stdio(false);
//		cin.tie(NULL);

	 ll test;
	 cin>>test;
	 while(test--)
	 {
	 	temp = "";
	 	int size,l;
		cin>>size;
		while(size--)
		{
			cin>>l;
			arr.push(l);
		}
		cout<<" stack is shown below -> ";
//		show();
  	reverse();
  	string z = "";
  	for(int i = temp.length()-1;i>=0;i--)
  	{
  		if(temp[i]!='_')
  		{
  			z.push_back(temp[i]);
		}
		if(temp[i]=='_')
		{
			stringstream geek(z);
			int a = 0;
			geek>>a;
			arr.push(a);
			z="";									
		}						
	}
 		while(arr.empty()==false)
		{
			cout<<arr.top()<<" ";
			arr.pop();
		}
		cout<<endl;
	 }
}


