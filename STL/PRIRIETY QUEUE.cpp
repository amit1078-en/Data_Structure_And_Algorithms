#include <bits/stdc++.h> 
#define endl '\n'
using namespace std; 
  
void showpq( 
    priority_queue<int, vector<int>, greater<int> > gq) 
{ 
    priority_queue<int, vector<int>,  
                                greater<int> > g = gq; 
    while (!g.empty()) { 
        cout << '\t' << g.top(); 
        g.pop(); 
    } 
    cout << '\n'; 
} 
  
int main() 
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
  	cin>>t;
  	while(t--)
  	{
  		long long l;
  		long long n;
  		long long power;
  		cin>>n>>power;
  		priority_queue<int> qu;
  		for(int i = 0;i< n;i++)
  		{
  			cin>>l;
  			qu.push(l);
		}
		int count = 0;
		while(qu.top()!=0 && power>0)
		{
			count++;
			int ma = qu.top();
			power-=ma;
			ma = ma/2;
			qu.pop();
			qu.push(ma);
		}
		if(qu.top()!=0)
		{
			cout<<count<<endl;
		}
		else
		{
			cout<<"Evacuate"<<endl;
		}
	}
    return 0; 
}
