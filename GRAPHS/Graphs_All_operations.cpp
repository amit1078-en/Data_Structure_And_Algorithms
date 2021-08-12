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
	for(int g  = 0 ;g<total_edges;g++)
	{
		s++;     
		int C = INT_MAX;
		int x;
		int y;
		for(int i =  0 ;i<s;i++) 
		{
			for(int j =  0 ; j<nodes;j++)  {
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


class disjointset
{
public:
    int djset[20];

    disjointset(int v)
    {
        for(int i=0;i<=v;i++)
        {
            djset[i] = i;
        }
    }

    int find_root(int v)
    {
        while(v != djset[v])
        {
            v = djset[v];
        }
        return v;
    }

    void take_union(int v1, int v2)
    {
        int r1 = find_root(v1);
        int r2 = find_root(v2);

        if(v1 == r1 && v2 == r2)
        {
            djset[v1] = v2;
        }
        else if(v1 != r1 && v2 == r2)
        {
            djset[v2] = v1;
        }
        else if(v1 == r1 && v2!= r2)
        {
            djset[v1] = v2;
        }
        else if(v1 != r1 && v2 != r2)
        {
            djset[r1] = r2;
        }
    }
};
class edge
{
public:
    int v1;
    int v2;
    int wt;
};

class GRAPHH
{
public:
    int v;
    int e;
    edge ed[20];

    GRAPHH(int vertices, int edges)
    {
        v = vertices;
        e = edges;
    }

    void accept_graph();
    void display_graph();
    void kruskal_mst();
    void sort_edges();

};

void GRAPHH::sort_edges()
{
    edge temp;
    for(int i=0;i<e;i++)
    {
        for(int j=0;j<e-i-1;j++)
        {
            if(ed[j].wt > ed[j+1].wt)
            {
              temp.v1 = ed[j].v1;
              temp.v2 = ed[j].v2;
              temp.wt = ed[j].wt;
			         
              ed[j].v1 = ed[j+1].v1;
              ed[j].v2 = ed[j+1].v2;
              ed[j].wt = ed[j+1].wt;

              ed[j+1].v1 = temp.v1;
              ed[j+1].v2 = temp.v2;
              ed[j+1].wt = temp.wt;
            }
        }
    }
}
void GRAPHH::kruskal_mst()
{
    edge mst[20];
    int mst_ctr = 0;
    int mst_cost = 0;
    disjointset dj(v);
    sort_edges();
    cout<<"\n Edges after sorting: ";
    display_graph();
    cout<<"\n";

    for(int i=0;i<e;i++)
    {
        int r1 = dj.find_root(ed[i].v1);
        int r2 = dj.find_root(ed[i].v2);
        if(r1 != r2)
        {
            mst[mst_ctr].v1 = ed[i].v1;
            mst[mst_ctr].v2 = ed[i].v2;
            mst[mst_ctr].wt = ed[i].wt;
            mst_ctr++;
            mst_cost = mst_cost + ed[i].wt;
            dj.take_union(ed[i].v1,ed[i].v2);
        }
    }

    cout<<"\n MST is : ";
    for(int i=0;i<mst_ctr;i++)
    {
        cout<<"\n   "<<mst[i].v1<<"     "<<mst[i].v2<<"     "<<mst[i].wt;
    }
    cout<<"\n Total cost of MST is: "<<mst_cost;

}
void GRAPHH::accept_graph()
{
    int temp = 0;
    for(int i  = 0;i<v;i++)
    {
    	for(int j = i+1;j<v;j++)
    	{
    		  ed[temp].v1 = i;
       		  ed[temp].v2 = j;
        	  ed[temp].wt = graph[i][j];
    		temp++;
		}
	}
}

void GRAPHH::display_graph()
{
    for(int i=0;i<e;i++)
    {
        cout<<"\n   "<<ed[i].v1<<"     "<<ed[i].v2<<"     "<<ed[i].wt;
    }
}
int  main()
{
	int c  = 1;
	cout<<"Enter The number of vertices of Graph-> ";
	int nodes;
	cin>>nodes;
	memset(graph,-1,sizeof(graph));
	for(int i=0;i<=nodes;i++)
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
	/*
	*/
	// if there exist any slef loop remove it
	REP(i,nodes)
	{
		graph[i][i] = 0;
	}
	GRAPHH g(nodes, (nodes*(nodes-1))/2);
	g.accept_graph();
	while(c)
	{
		int data;
		cout<<"\nChose the option \n1.Output for graph  \n2.Minimum Spanning Tree (Prim's Algorithm)   \n3.Minimum Spanning Tree (Krushkals Algorithm)  \n4.EXIT \nChose option -> ";
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
			  g.display_graph();
    		g.kruskal_mst();
    		cout<<endl;
				break;
			case 4:
				c=0;
				break;
			default:
				cout<<"\nInvalid input"<<endl;
		}
	}
}


