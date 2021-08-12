#include<bits/stdc++.h>
using namespace std;
//global array  for storing
int minheap[1000001];
int l = 0;
void upheapify(int element)
{
	l++;
	minheap[l] = element;
	int k = l;
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
void downheapify(int temp[],int p)
{
		cout<<temp[1]<<" ";
		temp[1] = temp[p];
		p--;
		int m = 1;
		while(m*2<=p)
		{
			if((m*2)+1<=p)
			{
				if(temp[m]>temp[m*2] || temp[m]>temp[(m*2)+1])
				{
					if(temp[m*2]>temp[(m*2)+1])
					{
						swap(temp[m],temp[(m*2)+1]);
						m = m*2;
						m = m+1;
					}
					else
					{
							swap(temp[m],temp[m*2]);
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
				if(temp[m]>temp[m*2])
				{
					swap(temp[m],temp[m*2]);
					m = m*2;
				}
				else
				{
					break;
				}
			}
		}
}
void deleteheap()
{
	int temp[l+1];
	for(int i = 1;  i<=l;i++)
	{
		temp[i] = minheap[i];
	}
	for(int i = 1 ; i<=l;i++)
	{
		downheapify(temp,l-i+1);
	}
}
int  main()
{
	cout<<"\nMin Heap \n\n";
	int n;
	int loop = 1;
		int k = 0;
	while(loop==1)
	{
		int data;
		cout<<"\n1.Insert Number \n2.Print Heap \n3.Get Min Value From Heap \n4.Exit \n\n\tChoice -> ";
		cin>>data;
		switch(data)
		{
			case 1:
				int dd;
				cout<<"\n\nEntered the data you want to insert In Heap -> ";
				cin>>dd;
				upheapify(dd);
			break;
			
			case 2:
				if(l==0)
				{
					cout<<"\nHeap Is Empty\n";
				}
				else
				{
					cout<<"\n\nHeap Elements Are\n\n";
					deleteheap();
					cout<<endl;
				}
				cout<<endl<<endl;
			break;
			
			case 3:
				if(l==0)
				{
					cout<<"\nHeap Is Empty\n";
				}
				else
				{
					cout<<"\nThe Smallest Element of the Heap is -> "<<minheap[1];
					cout<<endl;
				}
			break;
			case 4:
				loop = 0;
			break;
			
			default:
			cout<<"\n\nInalid choice entered by you \n";	
		}
	}
}


