/* 
PROBLEM STATEMENT
Rahul has n strings each of lowercase English Letters. In one move he can rotate a string towards left by 1.For example, if he has the string “banana”, in one move he can transform it into the string “ananab”.

After the Plenty of moves(possibly zero) if a string si is equal to string sj then si will be equal to 0.

Now Rahul asks himself: what is minimum moves to make n strings 0!!

NOTE: Strings may have different characters too!!
Input
The first line contains integer n (1 = n = (5 * 10^5)) — the number of strings.

This is followed by n lines which contain a string each. The i-th line corresponding to string si.
Lengths of strings are equal. Lengths of each string is positive and don't exceed 3*10^3.
Output:
Print the minimal number of moves Rahul needs in order to make all the strings equal otherwise print  - 1 if there is no solution.
INPUT:
4
ABBCD
BCDAB
BBCDA
ABBCD
OUTPUT:
5
EXPLANATION:
In the first sample testcase the optimal scenario is to perform operations in such a way as to transform all strings into "BCDAB" and it turns to be 0.
*/



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
int  main()
{
	ios_base::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
		unordered_map<string,int> Arr1;
	 ll test;
	 cin>>test;
	 string temp;
	 while(test--)
	 {
		cin>>temp;
		Arr1[temp]++;
	 }
	 if(Arr1.size()==1)
	 {
	 	cout<<0<<endl;
	 }
	 else
	 {
	 	unordered_set<string> PP;
	 	//storing all the left rotations of string first element in unoreded map
	 	unordered_map<string,int>  Arr2;	
		 PP.insert({temp});
	 	Arr2[{temp,0}];
	 	for(int i = 1 ; i<temp.length();i++)
	 	{
	 		string tem1 = "";
	 		tem1 = temp.substr(0,i);
	 		string tem2;
	 		tem2 = temp.substr(i,temp.length()-1);
	 		string final = "";
	 		final  = tem2+tem1;
	 		Arr2.insert({final,i});
	 		PP.insert({final});
		}
		int g = temp.length();
		int ans = INT_MAX;
		for(auto i = Arr1.begin();i!=Arr1.end();i++)
		{
			int k1 = Arr2[i->first];	
			string m="";
			int te = 0;
			
			if(PP.count(i->first)==0)
			{
				ans = -1;
				break;
			}
			for(auto j = Arr1.begin();j!=Arr1.end();j++)
			{
			
				int q1 = Arr2[j->first];	
				int q = j->second;
				if(PP.count(j->first)==0)
				{
					m=j->first;
					break;
				}
				else
				{
					int h = q1-k1;
					if(h!=g && h>0)
					{
						h = g-h;
					}
					h = abs(h);
					h = h*q;
					te = te + h;
				}
			}
			if(m!="")
			{
				ans = -1;
				break;
			}
			else
			{
				ans = min(ans,te);
			}
		}
		cout<<ans<<endl;
	 }
}


