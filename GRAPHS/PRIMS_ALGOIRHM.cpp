#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int graph[1000][1000];

void prims(int nodes)
{
	//Implementation of prims algorithm 
	int cost = 0;
	int total_edges = nodes-1;
	bool track[nodes];//checks whether nodes have been inserted or not
	
	for(int i = 0 ;i<nodes;i++) track[i]  =false;
	
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
		
		  
		
		for(int i =  0 ;i<s;i++)//traverses the nodes inserted
		{
			for(int j =  0 ; j<nodes;j++){
				//if node is inserted or not && connection between nodes is present or not && current cost should be less than before
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


int  main()
{
	int c  = 1;
	cout<<"Enter The number of vertices of Graph-> ";
	int nodes;
	cin>>nodes;
	//adjance matrix
	//2 d array

	for(int i = 0 ;i<nodes;i++)
	{
		for(int j = i+1;j<nodes;j++)
		{
			graph[i][j] = -1;
		}
	}
	
	for(int i=0;i<=nodes;i++)
	{
		graph[i][i] = 0;
	}
	
	int i = 0;
	for(i = 0;i<nodes;i++)
	{
		int j =0;
		//taking input for graph in a adjance matrix 
		for(j = 0;j<nodes;j++)
		{
			if(graph[i][j]==-1)  // value not inserted
			{
				int data;
				cout<<"\nEnter the Vertex length for "<<i<<" to "<<j<<" -> ";
				cin>>data;
				graph[i][j] = graph[j][i] = data;
			}
		}
	}
	/*
	*/
	// if there exist any slef loop remove it
	for(int i = 0;i<nodes;i++)
	{
		graph[i][i] = 0;
	}
	while(c)
	{
		int data;
		cout<<"\nChose the option \n1.Output for graph  \n2.Minimum Spanning Tree (Prim's Algorithm)   \n3.EXIT \nChose option -> ";
		cin>>data;
		switch(data)
		{
			case 1:
				cout<<endl;
				cout<<"\n\nGraph is shown below as";
				i = 0;
				for(i = 0;i<nodes;i++)
				{
					int j =0;
					for(j  = 0;j<nodes;j++)
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
				c=0;
				break;
			default:
				cout<<"\nInvalid input"<<endl;
		}
	}
}



