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

int  main()
{
	int size;
	cout<<"Enter size of array-> ";
	cin>>size;
	int arr[size];
	cout<<endl;
	cout<<"Enter Value you want to insert -> ";
	int data;
	memset(Linear,-1,sizeof(Linear));
	memset(Linear_Replacement,-1,sizeof(Linear_Replacement));
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
	
}


