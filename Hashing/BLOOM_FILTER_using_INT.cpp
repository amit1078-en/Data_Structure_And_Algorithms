#include<bits/stdc++.h>
#define mod 101;
using namespace std;
bool track[101];
int first(int num)
{
	long long int ans  = 0;
	while(num>0)
	{
		ans = ans+(num%10);
		ans = ans*num;
		num = num/10;
	}
	return ans%mod;
}
int second(int num)
{
		long long int ans  = 0;
	while(num>0)
	{
		long long int v = pow(11,(num%10));
		v = v%mod;
		ans = ans+v;
		ans = ans%mod;
		num = num/10;
	}
	return ans%mod;
}
int third(int num)
{
		long long int ans  = 1;
	while(num>0)
	{
		ans = (ans*3)%mod;
		if(num%10!=0)
		{
			ans = ans*(num+1);
		}
		ans  = ans%mod;
		num = num/10;
	}
	return ans%mod;
}
int four(int num)
{
	long long int ans  = 0;
	int i = 0 ;
	while(num>0)
	{
		long long int g  =(num%10*pow(7,i));
		g = g%mod;
		ans+=(ans*7)+g;
		ans = ans%mod;
		num = num/10;
		
		i++;
	}
	return ans%mod;
}
bool check(int num)
{
	int f1 = first(num);
	int f2 = second(num);
	int f3 = third(num);
	int f4 = four(num);
	if(track[f1]==true && track[f2]==true  && track[f3]==true && track[f4]==true)
	return true;
	
	else
	return false;
}
void insert(int num)
{
	int f1 = first(num);
	int f2 = second(num);
	int f3 = third(num);
	int f4 = four(num);
	track[f1] = track[f2] = track[f3] = track[f4] = true;
	cout<<"The Hash Value Generated via 4 hash functions were "<<f1<<" "<<f2<<" "<<f3<<" "<<f4<<endl;
}
int main()
{
	for(long long int i = 0 ; i<101;i++)track[i] = false;
	
	long long int size;
	cout<<"\nEnter how many Integer you want to store ->";
	cin>>size;
	long long int array[size+1];
	for(long long int i = 0 ;i<size;i++)
	{
		cout<<"\nEnter Value at Index "<<i<<" ";
		cin>>array[i];
		insert(array[i]);
	}
	while(1)
	{
		long long int ch;
		cout<<"\n\n1.Check if Given Integer Exist \n\n2.Exit \n\t Enter choice -> ";
		cin>>ch;
		cout<<endl;
		if(ch==1)
		{
			long long int num;
			cout<<"\nEnter number you want to search -> ";
			cin>>num;
			bool c = check(num);
			if(c==true)
			{
				cout<<"\n "<<num<<" May be present in the array \n";
			}
			else
			{
				cout<<"\n Value "<<num<<" is Not Present \n\n";
			}
		}
		else
		{
			break;
		}
	}
}


