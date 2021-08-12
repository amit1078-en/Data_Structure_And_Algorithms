#include<bits/stdc++.h>
#define mod 101;
using namespace std;
bool track[101];
int first(string num)
{
	int ans = 0;
	for(int i = 0; i<num.length();i++)
	{
		ans = ans+(int(num[i])%10);
		ans = ans*(int(num[i]));
		ans = ans%mod;
	}
	return ans%mod;
}
int second(string num)
{
	int ans = 0;
	for(int i = 0; i<num.length();i++)
	{
		int v = pow(11,(int(num[i])%10));
		ans = ans+v;
		ans = ans%mod;
	}
	return ans%mod;
}
int third(string num)
{
	int ans = 1;
	for(int i = 0; i<num.length();i++)
	{
		ans = (ans*3)%mod;
		if(int(num[i])%10!=0)
		{
			ans = ans*(int(num[i])+1);
		}
		ans  = ans%mod; 
	}
	return ans%mod;
}
int four(string num)
{
		int ans = 0;
	for(int i = 0; i<num.length();i++)
	{
		long long int g  =(int(num[i])%10*pow(7,i));
		g = g%mod;
		ans+=(ans*7)+g;
		ans = ans%mod;
	}
	return ans%mod;
}
bool check(string num)
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
void insert(string num)
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
	cout<<"\nEnter how many String you want to store ->";
	cin>>size;
	string array[size+1];
	for(long long int i = 0 ;i<size;i++)
	{
		cout<<"\nEnter Value -> ";
		cin>>array[i];
		insert(array[i]);
	}
	while(1)
	{
		long long int ch;
		cout<<"\n\n1.Check if Given String Exist \n\n2.Exit \n\t Enter choice -> ";
		cin>>ch;
		cout<<endl;
		if(ch==1)
		{
			string num;
			cout<<"\nEnter String you want to search -> ";
			cin>>num;
			bool c = check(num);
			if(c==true)
			{
				cout<<"\n "<<num<<" May be present in the array \n";
			}
			else
			{
				cout<<"\n "<<num<<" is Not Present \n\n";
			}
		}
		else
		{
			break;
		}
	}
}


