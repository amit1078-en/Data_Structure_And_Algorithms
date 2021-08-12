#include<bits/stdc++.h>
#define LOOP(i,n) for (int i = 0; i < n; i++)
#define mod 1000000007
#define ll long long int
#define INF 1000000000
#define endl '\n'
using namespace std;
int graph[11][11];
void show(int nodes)
{
	cout<<"\n\nGraph is shown below as";
	int i = 0;
	LOOP(i,nodes)
	{
		int j =0;
		LOOP(j,nodes)
		{
		
				cout<<"\nVertex length of "<<i<<" to "<<j<<" is "<<graph[i][j]<<" ";
			
		}
		cout<<endl;
	}
}
void primsalgorithm(int nodes)
{
	//algortihm -> Prims Algorithm
	int N = 0;
	int cost = 0;
	int mst[nodes];
	int k[nodes];
	bool track[nodes];
	for(int i = 0 ; i<nodes;i++)
	{
	k[i] = 10000;
		track[i] = false;
	}
	k[0] = 0;
	
	while(N-1<nodes)
	{
	
		N++;
	}
	cout<<"\nTotal cost calculated using prims algorithm is "<<cost<<endl;
}
int  main()
{
	cout<<"Enter The number of edges of Graph-> ";
	int nodes;
	cin>>nodes;
	memset(graph,-1,sizeof(graph));
	for(int i=0;i<=nodes;i++)
	{
		graph[i][i] = 0;
	}
	int i = 0 ;
	LOOP(i,nodes)
	{
		int j =0;
		LOOP(j,nodes)
		{
			if(graph[i][j]==-1)
			{
				int data;
				cout<<"\nEnter the Vertex length for "<<i<<" to "<<j<<" -> ";
				cin>>data;
				graph[i][j] = graph[j][i] = data;
			}
		}
	}
	show(nodes);
	primsalgorithm(nodes);
}


