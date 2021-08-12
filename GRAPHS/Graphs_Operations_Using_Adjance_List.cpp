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

void BFS(int V, vector<int> adj[],int s)
    {
        vector<int> ans;
        queue<int> Q;
        Q.push(s);
        bool arr[V+1];
        memset(arr,false,V+1);
        while(Q.empty()==false)
        {
            int ind = Q.front();
            
            for(auto x :adj[ind])
            {
            	int l = x;
                if(arr[l] == false)
                {
                    Q.push(l);
                    arr[l] = true;
                }
                              
            }
             arr[ind] = true;
             cout<<ind<<" ";
            Q.pop();
        }
    }
void DFS(int V, vector<int> adj[],int s)
    {
        stack<int> Q;
        Q.push(s);
        bool arr[V+1];
        memset(arr,false,V+1);
        arr[s] = true;
        cout<<s<<" ";
        while(Q.empty()==false)
        {
            int ind = Q.top();
            bool fl = false;
            for(auto x :adj[ind])
            { 
            	int l = x;
                if(arr[l] == false)
                {
                	cout<<l<<" ";
                    Q.push(l);
                    arr[l] = true;
                    fl = true;
                    break;
                }
            }
            if(fl==false)
            Q.pop();
        }
    }
    void bfs(int M,vector<int> arr[])
    {
    	cout<<"\nThe BFS is shown below -> \n";
			cout<<"Enter the starting element for your traversal ->";
			int x = 0;
			cin>>x;
			BFS(M,arr,x);
			cout<<endl;
	}
	void dfs(int M,vector<int> arr[])
	{
		cout<<"\nThe DFS is shown below -> \n";
			cout<<"Enter the starting element for your traversal ->";
			int x = 0;
			cin>>x;
			DFS(M,arr,x);
			cout<<endl;
	}
int  main()
{
	int M,ch,data,data1;
	cout<<"\nAdjance list representation of graph using dynamic array\n";
	cout<<"\nEnter size of graph -> ";
	cin>>M;
	vector<int> arr[M+1];
	int  p = 0;
	while(p==0)
	{
		cout<<"\n1.Add join \n2.print \n3.BFS \n4.DFS \n4.Exit\n\t choice->";
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"Enter the edge1 you want to connect to edge2 -> ";
			cin>>data>>data1;
			arr[data].push_back(data1);
			arr[data1].push_back(data);
			break;
		case 2:
			for(int i = 0;i<M;i++)
			{
				cout<<"\nThe edge "<<i<<" Is connected to edges  ->   ";
				bool flag = 0;
				for(auto i:arr[i])
				{
					flag=  1;
					cout<<i<<" ";
				}
				if(flag==0)
				{
					cout<<"NULL";
				}
			//	cout<<endl;
			}
			break;
		case 3:	
			bfs(M,arr);
			break; 		
			case 4:
			dfs(M,arr);
			break; 	
		
	}
	}

}


