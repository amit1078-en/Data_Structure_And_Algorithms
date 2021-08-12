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
int arr[1000001];
int minheap[1000001];
int maxheap[1000001];
int l = 0;
void heapinsertion(int element)
{
	l++;
	arr[l] = element;
}

void minheapdeletion()
{
	int p = l;
	while(p!=0)
	{
		cout<<minheap[1]<<" ";
		minheap[1] = minheap[p];
		p--;
		int m = 1;
		while(m*2<=p)
		{
			if((m*2)+1<=p)
			{
				if(minheap[m]>minheap[m*2] || minheap[m]>minheap[(m*2)+1])
				{
					if(minheap[m*2]>minheap[(m*2)+1])
					{
						swap(minheap[m],minheap[(m*2)+1]);
						m = m*2;
						m = m+1;
					}
					else
					{
							swap(minheap[m],minheap[m*2]);
							m = m*2;
					}
				}
				else
				{
					break;
				}
			}
			else
			{
				if(minheap[m]>minheap[m*2])
				{
					swap(minheap[m],minheap[m*2]);
					m = m*2;
				}
				else
				{
					break;
				}
			}
		}
	}
}

void maxheapdeletion()
{
	int p = l;
	while(p!=0)
	{
		cout<<maxheap[1]<<" ";
		maxheap[1] = maxheap[p];
		p--;
		int m = 1;
		while(m*2<=p)
		{
			if((m*2)+1<=p)
			{
				if(maxheap[m]<maxheap[m*2] || maxheap[m]<maxheap[(m*2)+1])
				{
					if(maxheap[m*2]<maxheap[(m*2)+1])
					{
						swap(maxheap[m],maxheap[(m*2)+1]);
						m = m*2;
						m = m+1;
					}
					else
					{
							swap(maxheap[m],maxheap[m*2]);
							m = m*2;
					}
				}
				else
				{
					break;
				}
			}
			else
			{
				if(maxheap[m]<maxheap[m*2])
				{
					swap(maxheap[m],maxheap[m*2]);
					m = m*2;
				}
				else
				{
					break;
				}
			}
		}
	}
}
void minheapinsertion()
{
	for(int i = 1 ; i<=l;i++)
	{
		minheap[i] = arr[i];
		int k = i;
		while(k/2!=0)
		{
			if(minheap[k] < minheap[k/2])
			{
				swap(minheap[k],minheap[k/2]);
				k = k/2;
			}
			else
			{
				break;
			}
		}
	}
	minheapdeletion();
}
void maxheapinsertion()
{
	for(int i = 1 ; i<=l;i++)
	{
		maxheap[i] = arr[i];
		int k = i;
		while(k/2!=0)
		{
			if(maxheap[k] > maxheap[k/2])
			{
				swap(maxheap[k],maxheap[k/2]);
				k = k/2;
			}
			else
			{
				break;
			}
		}
	}
	maxheapdeletion();
}

int  main()
{
	cout<<"Heap Sort \n\n";
	int n;
	int loop = 1;
		int k = 0;
	while(loop==1)
	{
		int data;
		cout<<"\n1.Insert Number \n2.Display In Ascending Order \n3.Display In Decending order\n4.Exit \n\n\tChoice -> ";
		cin>>data;
	
		switch(data)
		{
			case 1:
				int dd;
				cout<<"\n\nEntered the data you want to insert -> ";
				cin>>dd;
				heapinsertion(dd);
				
			break;
			
			case 2:
				cout<<"\n\nThe data shown in ascending order is shown below \n\n";
				minheapinsertion();
				cout<<endl<<endl;
			break;
			
			case 3:
				cout<<"\n\nThe data shown in desending  order is shown below \n\n";
				maxheapinsertion();
				cout<<endl<<endl;
			break;
			
			case 4:
				loop = 0;
			break;
			
			default:
			cout<<"\n\nInalid choice entered by you \n";	
		}
	}
}
/*
Heap Sort


1.Insert Number
2.Display In Ascending Order
3.Display In Decending order
4.Exit

        Choice -> 1


Entered the data you want to insert -> 45  1  60 1   55  1   0  1  50

1.Insert Number
2.Display In Ascending Order
3.Display In Decending order
4.Exit

        Choice ->

Entered the data you want to insert ->
1.Insert Number
2.Display In Ascending Order
3.Display In Decending order
4.Exit

        Choice ->

Entered the data you want to insert ->
1.Insert Number
2.Display In Ascending Order
3.Display In Decending order
4.Exit

        Choice ->

Entered the data you want to insert ->
1.Insert Number
2.Display In Ascending Order
3.Display In Decending order
4.Exit

        Choice ->

Entered the data you want to insert ->
1.Insert Number
2.Display In Ascending Order
3.Display In Decending order
4.Exit

        Choice -> 2


The data shown in ascending order is shown below

0 45 50 55 60


1.Insert Number
2.Display In Ascending Order
3.Display In Decending order
4.Exit

        Choice -> 3


The data shown in desending  order is shown below

60 55 50 45 0


1.Insert Number
2.Display In Ascending Order
3.Display In Decending order
4.Exit

        Choice -> 1


Entered the data you want to insert -> 65

1.Insert Number
2.Display In Ascending Order
3.Display In Decending order
4.Exit

        Choice -> 1


Entered the data you want to insert -> 545565656

1.Insert Number
2.Display In Ascending Order
3.Display In Decending order
4.Exit

        Choice -> 2


The data shown in ascending order is shown below

0 45 50 55 60 65 545565656


1.Insert Number
2.Display In Ascending Order
3.Display In Decending order
4.Exit

        Choice -> 3


The data shown in desending  order is shown below

545565656 65 60 55 50 45 0


1.Insert Number
2.Display In Ascending Order
3.Display In Decending order
4.Exit

*/

