#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int builttree(int left,int right,int x,int arr[],int array[])
{
	if(left<=right)
	{
		if(left==right)
		{
			array[x] = arr[left];
			
		}
		else{
				int mid = (left+right)/2;
		 array[x]  = min(builttree(left,mid,(x*2)+1,arr,array),builttree(mid+1,right,(x*2)+2,arr,array));
		 
		}
		return array[x];
	}
}
int getans(int left,int right,int ql,int qr,int x,int array[])
{
	
		if(ql<=left && right<=qr)
		{
			return array[x];
		}
		if(left>qr || ql>right)
		
			return INT_MAX;
		}
		int mid = (left+right)/2;
		return min(getans(left,mid,ql,qr,(x*2)+1,array),getans(mid+1,right,ql,qr,(x*2)+2,array));
	
}
void update(int left,int right,int index,int value,int x,int array[])
{
	if(left<=right)
	{
		if(left==right)
		{
			array[x] = value;
			return ;
		}
		int mid = (left+right)/2;
		if(mid>=index)
		{
			update(left,mid,index,value,(x*2)+1,array);
		}
		else
		{
			update(mid+1,right,index,value,(x*2)+2,array);
		}
		array[x] = min(array[(x*2)+1],array[(x*2)+2]);
	}
}
int main() {
	int size;
	cin>>size;
	int  h = ceil(log2(size));
	h  = pow(2,h);
	h = 2*h;
	h = h-1;
	int array[h];
	int arr[size];
	for(int  i  = 0 ; i<size;i++)
	{
		cin>>arr[i];
	}
	builttree(0,size-1,0,arr,array);
	int Q;
	cin>>Q;
	
	while(Q--)
	{
		int w;
		cout<<"\n1.Range Find \n2.Update Query \n3.EXIT \n\tEnter choice -> ";
		cin>>w;
		if(w==1)
		{
			int l,r;
			cin>>l>>r;
			if(l>=0 && r<size)
			{
				int ans = getans(0,size-1,l,r,0,array);
				cout<<ans<<endl;
			}
			else
			{
				 cout<<"\n	SORRY WRONG INDEX \n";
			}
		}
		else if(w==2)
		{
			int index;
			cout<<"\nEnter Index -> ";
			cin>>index;
			if(index>=0 && index<size)
			{
				int p;
				cout<<"\nEnter value of Index -> ";
				cin>>p;
				update(0,size-1,index,p,0,array);
			}
			else
			{
				 cout<<"\n	SORRY WRONG INDEX \n";
			}
		}
		else
		{
			break;
		}
	}
	return 0;
}
