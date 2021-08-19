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

class trie
{
	public:
		trie* next[26];
		bool word_end;
		trie()
		{
			for(int i =  0 ; i<26;i++)
			{
				next[i] = NULL;
			}
			word_end = false;
		}
};
int  main()
{
	trie* parent = new trie();
	while(1)
	{
		cout<<" \n\n\t1.Insert Word Into Trie \n\n\t2.Search Word In The Trie \n\n\t3.EXIT   \n\n\tCHOICE-> ";
		int choice;
		cin>>choice;
		if(choice==1)
		{
			string val;
			cout<<"\nEnter the string you want to store in the trie -> ";
			cin>>val;
			trie* temp = parent;
			for(int  i = 0 ; i<val.length();i++)
			{
				if(temp->next[val[i]-97]!=NULL)
				{
					temp = temp->next[val[i]-97];
				}
				else
				{
					trie* yy =  new trie();
					temp->next[val[i]-97] = yy;
					temp = yy;
				}
			}
			temp->word_end=true;
		}
		else if(choice==2)
		{
			string val;
			cout<<"\nEnter the string you want to find in the trie -> ";
			cin>>val;
			bool check = true;
			trie* temp = parent;
			for(int i = 0 ; i<val.length();i++)
			{
				if(temp->next[val[i]-97]!=NULL)
				{
					temp = temp->next[val[i]-97];
				}
				else
				{
					check = false;
					break;
				}
			}
			if(check && temp->word_end==true)
			{
				cout<<"The Given String "<<val<<"  exist in the trie"<<endl;
			}
			else
			{
				cout<<"The Given String "<<val<<" Doesnt exist in the trie"<<endl;
			}
		}
		else if(choice==3)
		{
			break;			
		}
		else
		{
			cout<<"\nDefault input";
		}
	}
}


