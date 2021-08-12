#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
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
class trie{
	public:
		trie* arr[26];
		bool last ;
		bool yes;
		trie()
		{
			last = false;
			yes = false;
				for(int j = 0 ; j<26;j++)
				{
					arr[j] = NULL;
				}
		}
	
};
trie* root = new trie();
void insert(string  ch)
{
	trie* temp = root;
	
	for(int i = 0; i<ch.length();i++)
	{
		
		 if(temp->arr[int(ch[i])-97]==NULL){
			if(!root->last){
				
					root = temp;
				}
			
				temp->last = true;
			trie* rt = new trie();
			temp->arr[int(ch[i])-97] = rt;
				for(int j = 0 ; j<26;j++)
				{
					rt->arr[j] = NULL;
				}
				
				temp = rt;
				rt->last = false;
				
		}
		else{
			temp->last = true;
			temp = temp->arr[int(ch[i])-97];
		}
		
	}temp->yes = true;
}


void show()
{

trie* sh = root;
stack<trie*> Q;
Q.push(root);
string tr  = "";
unordered_set<trie*> hash;
unordered_set<trie*> d;
hash.insert(root);
while(!Q.empty()){
	trie* rr = Q.top();
	bool l = false;
	for(int i = 0  ;i<26;i++)
	{
		
		if(rr->arr[i]!=NULL && hash.find(rr->arr[i])==hash.end()){
			
			
			hash.insert(rr->arr[i]);
			
			if(rr->yes && d.find(rr)==d.end())
			{
				d.insert(rr);
				cout<<tr<<endl;
			}
			tr.push_back(char('a'+i));
			Q.push(rr->arr[i]);
			l = true;
			break;
		}
	}
	if(l==false)
	{
		
		if(rr->last==false){
			for(char q:tr)
			{
				cout<<q;
			}
			cout<<endl;
		}
		if(!tr.empty()){
			tr.pop_back();
		}
		Q.pop();
	}
}
root = sh;
}

int  main()
{
	
	for(int i = 0  ;i<5;i++)
	{
		string ch;
		cin>>ch;
		insert(ch);
	
	}	show();
}


