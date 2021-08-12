#include<bits/stdc++.h>
using namespace std;
int mod = INT_MIN;
int matrix[3][10000];
bool cycle;
int position[3];
void intialise_matrix()
{
	for(int i = 0 ; i<3;i++)
	{
		for(int j = 0 ;  j<mod;j++)
		{
			matrix[i][j] = INT_MIN;
		}
	}
}
void printhashtable()
{
	cout<<"\nHash Tables Are Shown Below\n";
	cout<<"Table 1"<<setw(30)<<"Table2"<<endl;
	for(int i = 0 ; i<mod;i++)
	{
		int x = matrix[0][i];
		int y = matrix[1][i];
		cout<<x<<setw(30)<<y<<endl;
	}
}
void  cuckoo_insert(int element,int c,int count)
{
	if(count==mod)
	{
		cycle = true;
		cout<<"\nCycle Present Rehash \n";
		return ;
	}
	for(int i = 0 ;  i<2;i++){
		int x;
		if(i==0)
		{	
			x = element%mod;
		}
		else if(i==1)
		{
			x = (element/mod)%mod;
		}
		
		position[i] = x;
		if(matrix[i][position[i]]==element)
		{
			return ;
		}
	}
    if (matrix[c][position[c]]!=INT_MIN)
    {
        int dis = matrix[c][position[c]];
        matrix[c][position[c]] = element;
        c++;
        cuckoo_insert(dis,c%3,count++);
    }
    else //else: place the new key in its position
       matrix[c][position[c]] = element;
}
void search()
{
	int element;
	cin>>element;
	int x = element%mod;
	int y = (element/mod)%mod;
	
	if(matrix[0][x]==element)
	{
			cout<<"\nelement found at row 1 position "<<x<<"\n";
	}
	else if(matrix[1][y]==element)
	{
			cout<<"\nelement found at row 1 position "<<y<<"\n";
	}
	else
	{
		cout<<"\nGiven Element Is Not Present in Hash Table\n";
	}
}
int  main()
{
	cout<<"\nEnter The Size of Cuckoo Filter-> ";
	cin>>mod;
	intialise_matrix();
	bool end = false;
	int tot = 0;
	while(!end)
	{
		int option;
		cout<<"\n\n1.Insert Element In Filter \n\n2.Search Element in hash table \n\n3.Exit \n\n\tSearch -> ";
		cin>>option;
		switch(option)
		{
			case 1:
			if(tot<mod)
			{
				int d;
				cin>>d;
				cycle = false;
				cuckoo_insert(d,0,0);
				if(cycle==false)
				{
					tot++;
					printhashtable();
				}
			}
			else
			{
				cout<<"\nCant insert ";
			}	
				break;
			case 2:
				if(tot==0)
				{
					cout<<"\nHash Table is Empty \n";
				}
				else
				{
					cout<<"\nEnter Element you want to search -> ";
					search();
				}
				break;
			case 3:
				end = true;
				break;
			default:
				cout<<"\nPlease enter correct option\n";
		}
	}
	
}


