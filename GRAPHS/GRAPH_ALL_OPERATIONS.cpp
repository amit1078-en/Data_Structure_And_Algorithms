#include<bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++)
#define endl '\n'
using namespace std;
int graph[1000][1000];
void  dijakstra(int starting,int vertices)
{
	int  answer[vertices];
	bool track[vertices];
	for(int i = 0; i<vertices;i++)
	{
		track[i] = false;
		answer[i] = 10000007;
	}
	answer[starting] = 0;
	int total = vertices;
	while(total--)
	{
		int ind = 0;
		int rt = INT_MAX;
		for(int i  =0;i<vertices;i++)
		{
			if(answer[i]<rt && track[i]==false)
			{
				rt = answer[i];
				ind = i;
			}
		}
		track[ind] =  true;
		for(int i = 0 ; i<vertices;i++)
		{
			if(track[i]==false && graph[ind][i]!=0)
			{
				int m = rt+graph[ind][i];
				if(m<answer[i])
				{
					answer[i] = m;
				}
			}
		}
	}
	
				int i = 0;
				for(int j = 0 ; j<vertices;j++)
				{
					cout<<"\nShortest Path from "<<i<<" To "<<j<<" is "<<answer[j];
					i++;
				}
}
void prims(int nodes)
{
	//Implementation of prims algorithm 
	int cost = 0;
	int total_edges = nodes-1;
	bool track[nodes];
	memset(track,false,sizeof(track));
	//initialy add edge 0 to MSP 
	track[0] = true;
	int nodesadded[nodes]; 
	int s = 0;
	nodesadded[s] = 0;
	while(total_edges--)
	{
		s++;
		int C = INT_MAX;
		int x;
		int y;
		for(int i =  0 ;i<s;i++)
		{
			for(int j =  0 ; j<nodes;j++){
				
				if(track[j]==false && graph[nodesadded[i]][j]!=0 && graph[nodesadded[i]][j]<C){
					x =nodesadded[i];
					y = j; 
					C = graph[nodesadded[i]][j];					
				}	
			}
		}
		track[y] = true; 
		nodesadded[s] = y;
		cout<<"\nVertices "<<x<<" And "<<y<<" Are Connected In Msp With Cost "<<C;
		cost = cost + C;
	}
	cout<<"\nThe Toatl cost of MSP by Prim's algorithm is -> "<<cost<<endl;
}

bool isCycle(int V, vector<int>adj[])
	{
	    bool track[V];
	    for(int i  = 0 ; i < V;i++)
	    {
	        track[i] = false;
	    }
	   for(int i = 0 ;  i<V;i++)
	   {
	       if(track[i]==false)
	       {
	           track[i] = true;
	           queue<int> arr;
	           int check[V];
	           arr.push(i);
	           for(int i = 0 ;  i <V;i++)
	           {
	               check[i] = -1;
	           }
	           while(arr.empty()==false)
	           {
	               int top =arr.front();
	               check[top] = 1;
	               for(auto x:adj[top])
	               {
	                   if(check[x]==0 && track[x]==true)
	                   {
	                       return true;
	                   }
	                   if(check[x]==-1)
	                   {
	                       arr.push(x);
	                       track[x]=true;
	                       check[x] = 0;
	                   }
	               }
	                check[top] = 1;
	               arr.pop();
	           }
	       }
	   }
		return false;
    }
	
void krushkals(int nodes)
{
	//first we have to sort the egdges in ascending order based on thier cost
	bool first[nodes];
	int cost[nodes*nodes];
	int start[nodes*nodes];
	int end[nodes*nodes];
	int shift = 0;
	bool second[nodes];
	REP(i,nodes){
		first[i] = false;
		second[i] = false;
	}
	for(int i = 0 ;i<nodes;i++)
	{
		for(int j = 0 ;j<nodes;j++)
		{
			if(graph[i][j]!=0 && (first[j]!=true || second[i]!=true ))
			{
					first[i] = true;
					second[j] = true;
					start[shift] = i;
					end[shift] = j;
					cost[shift] = graph[i][j];
					shift++;
			}
		}
	}
	int total_edges = nodes-1;
	//using bubble sort algorithm to sort the edges
	for(int i = 0;i<shift;i++)
	{
		for(int j=i+1;j<shift;j++)
		{
			if(cost[i]>cost[j])
			{
				swap(cost[i],cost[j]);
				swap(start[i],start[j]);
				swap(end[i],end[j]);
			}
		}
	}
	int i = 0;
	int total_cost  = 0;
	vector<int> array[nodes];
	while(total_edges>0)
	{
			array[start[i]].push_back(end[i]);
			array[end[i]].push_back(start[i]);
			bool ans = isCycle(nodes,array);
			if(ans==false)
			{
					cout<<"\nVertices "<<start[i]<<" And "<<end[i]<<" Are Connected In Msp With Cost "<<cost[i];
					total_cost = total_cost+cost[i];
					total_edges--;
			}
			else
			{
				array[start[i]].pop_back();	
				array[end[i]].pop_back();	
			}
		i++;
	}
	cout<<"\nThe Total cost of Msp Using Krushkals algorithm is "<<total_cost<<endl;
}
int  main()
{
	int c  = 1;
	cout<<"Enter The number of edges of Graph-> ";
	int nodes;
	cin>>nodes;
	memset(graph,-1,sizeof(graph));
	for(int i=0;i<nodes;i++)
	{
		graph[i][i] = 0;
	}
	int i = 0;
	REP(i,nodes)
	{
		int j =0;
		//taking input for graph in a adjance matrix 
		REP(j,nodes)
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
	
	// if there exist any slef loop remove it
	REP(i,nodes)
	{
		graph[i][i] = 0;
	}
//	GRAPHH g(nodes, (nodes)*(nodes+1)/2);
//	g.accept_graph();
	while(c)
	{
		int data;
		cout<<"\nChose the option \n1.Output for graph  \n2.Minimum Spanning Tree (Prim's Algorithm)   \n3.Minimum Spanning Tree (Krushkals Algorithm) \n4.Shortest Path(Dijakstra Algorithm) \n5.EXIT \nChose option -> ";
		cin>>data;
		switch(data)
		{
			case 1:
				cout<<endl;
				cout<<"\n\nGraph is shown below as";
				i = 0;
				REP(i,nodes)
				{
					int j =0;
					REP(j,nodes)
					{
						if(graph[i][j]!=0)
						{
							cout<<"\nVertex length of "<<i<<" to "<<j<<" is "<<graph[i][j]<<" ";
						}
						
					}
					cout<<endl;
				}
				break;
			case 2:
				cout<<endl;
				cout<<"\nImplementation of MSP using prims algorithm is shown below\n";
				prims(nodes);
				cout<<endl;
				break;
			case 3:
				cout<<"\nImplementation of MSP using Krushkal's algorithm is shown below\n";
				krushkals(nodes);
				break;
			case 4:
				int vl;
				cout<<"\nDijastra algorithm \nEnter Starting vertex of Graph-> ";
				cin>>vl;
				dijakstra(vl,nodes);
				break;
			case 5:
				c=0;
				break;
			default:
				cout<<"\nInvalid input"<<endl;
		}
	}
}


