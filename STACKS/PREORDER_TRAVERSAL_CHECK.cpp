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
vector<vector<int>> temp(200001);
set<int> seet;
unordered_map<int,int> tot;


int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}
unsigned int factorial(unsigned int n)
{
    int res = 1, i;
    for (i = 2; i <= n; i++)
        res *= i;
    return res;
}
  


int sol = 0;

void rec()
{
	sol = 0;
	tot.clear();
	seet.clear();
	for(int i =0 ;i<200001;i++)
	{
		temp[i].clear();
	}
}
int  main()
{
	ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	 ll test;
	 cin>>test;
	 while(test--)
	 {
	 		vector<int> extra;
			int size = 0;
			int tot_color = 0;
			
			cin>>size>>tot_color;
			
			rec();
			
			int array[size];
			int amit[size];
			for(int i = 0 ; i<size;i++)
			{
				amit[i] = 0;
				cin>>array[i];
				tot[array[i]]++;
				seet.insert(array[i]);
				temp[array[i]].push_back(i);
			}for(auto element:seet)
			{
	if(tot[element]>=tot_color)
{
		for(int n = 0 ; n<tot_color;n++)
	{
    		int good = n;
		amit[temp[element][n]] = good+1;
	}
	sol+=1;
}
int h = tot[element];
if(h<tot_color)
{
	for(auto fuduu:temp[element]){
    		int gh  = fuduu;
		int gggg = gh;
		extra.push_back(gggg);
	}
}
} 
		int gandu=extra.size()/tot_color;
		gandu=gandu*tot_color;
		int sd = gandu;
		sol = sol + sd;
		int help=1;
		for(int t=1;t<=sd;t++)
		{
		if((t-1)%tot_color==0) help=1;
		amit[extra[t-1]]=help;
		help+=1;
		}
        			for(int i = 0;i<size;i++)
			{
				int j = amit[i];
				int gggg = j;
				cout<<gggg<<" ";
			}
			cout<<'\n';
	 }
}


