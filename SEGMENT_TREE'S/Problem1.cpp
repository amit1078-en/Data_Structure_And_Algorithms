#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;
void  update(int left,int right,int ind,int v,int x,int arrayy[])
{
	if(left<=right)
	{
		if(left==right)
		{
			arrayy[x] = v;
			return ;
		}
		int mid = (left+right)/2;
		if(mid>=ind)
		{
			update(left,mid,ind,v,(x*2)+1,arrayy);
		}
		else{
			update(mid+1,right,ind,v,(x*2)+2,arrayy);
		}
		arrayy[x] = max(arrayy[(x*2)+1],arrayy[(x*2)+2]);
	}
}
int builttree(int left,int right,int x,int arr[],int arrayy[])
{
	if(left<=right)
	{
		if(left==right)
		{
			arrayy[x] = arr[left];
			return arr[left];
		}
		int mid = (left+right)/2;
		arrayy[x] = builttree(left,mid,(x*2)+1,arr,arrayy)+builttree(mid+1,right,(x*2)+2,arr,arrayy);
		return arrayy[x];
	}
}
int find(int left,int right,int lq,int lr,int x,int arrayy[])
{
	if(left<=right)
	{
		if(lq<=left && lr>=right)
		{
			return arrayy[x];
		}
		else if(lq>right || left>lr)
		{
			return 1e-9;
		}
		int mid = (left+right)/2;
		return find(left,mid,lq,lr,(x*2)+1,arrayy)+find(mid+1,right,lq,lr,(x*2)+2,arrayy);
	}
}
int32_t  main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int size;
    cin>>size;
    int h = ceil(log2(size));
	h = pow(2,h);
	h = 2*h;
    int arrayy[h];
	int arr[size];
	for(int i  =  0 ;i<size;i++)
	{
		int t;
		cin>>arr[i];
	}
	builttree(0,size-1,0,arr,arrayy);
	int Q;
	cin>>Q;
	while(Q--)
	{
		char q
		int a,b;
		cin>>q>>a>>b;
		a--;
		b--;
		if(q=='U')
		{
			b++;
			update(0,size-1,a,b,0,arrayy);
		}
		else if(q=='Q')
		{
//			int ans = 0;
//			
//			int ss;
//			int f = find(0,size-1,a,b,0,arrayy);
//			ans = ans+f;
//			ss = ll;
//			int p = arrayy[ll];
//			arrayy[ll] = INT_MIN;
//			
//			 f = find(0,size-1,a,b,0,arrayy);
//			ans = ans+f;
//			arrayy[ss] = p;			
//			cout<<ans<<endl;
		}
	}
}

