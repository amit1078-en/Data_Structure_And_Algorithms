#include<bits/stdc++.h>
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;
int Linear[1000001];
int Linear_Replacement[1000001];

void linear_probling_with_replacement(int data,int size)
{
	if(Linear_Replacement[data%size]==-1)
	{
		Linear_Replacement[data%size] = data;
	}
	else
	{
		int k = data%size;
		int temp = Linear_Replacement[data%size];
		Linear_Replacement[data%size] = data;
		data = temp;
		k++;
		while(k%size!=data%size)
		{
			if(Linear_Replacement[k%size]==-1)
			{
				Linear_Replacement[k%size] = data;
				break;
			}
			k++;
		}
	}
}
void linear_probling_without_replacement(int data,int size)
{
	if(Linear[data%size]==-1)
	{
		Linear[data%size] = data;
	}
	else
	{
		int k = data%size;
		k++;
		while(k%size!=data%size)
		{
			if(Linear[k%size]==-1)
			{
				Linear[k%size] = data;
				break;
			}
			k++;
		}
	}
}
int search(int array[],int size,int element)
{
	int x = element%size;
	if(array[x]==element)
	{
		return x;
	}
	x++;
	while(x%size!=element%size)
	{
		if(array[x%size]==element)
		{
			return x%size;
		}
		x++;
	}
	return -1;
}
int  main()
{
	int size;
	cout<<"Enter size of array-> ";
	cin>>size;
	int arr[size];
	cout<<endl;
	cout<<"Enter Value you want to insert -> ";
	int data;
	for(int i = 0 ; i<size;i++)
	{
		Linear[i] = -1;
		Linear_Replacement[i] = -1;
	}
	for(int i = 0 ; i<size;i++)
	{
		cout<<"\nEnter Value  -> ";
		int data;
		cin>>data;
		linear_probling_with_replacement(data,size);
		linear_probling_without_replacement(data,size);
		cout<<"\nLinear Probling Without Replacement \n";
		for(int i = 0; i <size;i++)
		{
			cout<<"\nAT Index "<<i<<" Value is "<<Linear[i];
		}
		cout<<"\n\nLinear Probling With Replacement \n";
		for(int i = 0; i <size;i++)
		{
			cout<<"\nAT Index "<<i<<" Value is "<<Linear_Replacement[i];
		}
	}
	bool track = true;
	while(track)
	{
		cout<<"\n\n1.Enter Element you want to search \n\n2.EXIT \n\n\tEnter choice-> ";
		int choice;
		cin>>choice;
		if(choice==1)
		{
			cout<<"\n\neneter element you want to search -> ";
			int ch;
			cin>>ch;
			int first  =  search(Linear,size,ch);
			int second =  search(Linear_Replacement,size,ch);
			if(first==-1)
			{
				cout<<"\n\n Given number "<<ch<<" is not present\n";
			}
			else
			{
				cout<<"\n In Without Replacement it is present in index "<<first<<endl;
				cout<<"\n In With Replacement it is present in index "<<second<<endl;
			}
		}
		else if(choice==2)
		{
			track = false;
		}
	}
}



