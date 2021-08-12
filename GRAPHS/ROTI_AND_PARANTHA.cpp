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
int one[1001];
int two[1001];
int three[1001];
int four[1001];
int five[1001];
int six[1001];
int seven[1001];
int eight[1001];
void precompute()
{
	for(int i = 0 ;i<1001;i++)
	{
		int num = i*(i+1)/2;
		one[i] = num;
		two[i] = num*2;
		three[i] = num*3;
		four[i]  = num*4;
		five[i] = num*5;
		six[i] = num*6;
		 seven[i] = num*7;
		 eight[i] = num*8;
	}
}
 int findFloor(int v[],int  n, int  x){
        if(v[0]>x)
        return -1;
        
        else
        {
            //using binary search 
            int index = -1;
            int l = 0;
            int r = n-1;
            while(l<=r)
            {
                int mid = (l+r)/2;
                if(v[mid]<=x)
                {
                    index = max(index,mid);
                }
                if(v[mid]>=x)
                {
                    r = mid-1;
                }
                else
                {
                    l = mid+1;
                }
            }
            
            
            
            //alternative method using lower bound stl iterator
            //     vector<long long>::iterator it,up;
            //      it = lower_bound(v.begin(),v.end(),x);
            //   int  index = it-v.begin()-1;
            //   if( index+1<n && v[index+1]==x )
            //   {
            //       index++;
            //   }
            return index;
        }
    }
bool check(int arr[],long long int mid,int parantha)
{
	long long count = 0;
	if(arr[1]!=0)
	{
		int fin = findFloor(one,1001,mid);
		count = count+ (fin*arr[1]);
	}
	if(arr[2]!=0)
	{
		int fin = findFloor(two,1001,mid);
			count = count+ (fin*arr[2]);
	}
	if(arr[3]!=0)
	{
		int fin = findFloor(three,1001,mid);
			count = count+ (fin*arr[3]);
	}
	if(arr[4]!=0)
	{
		int fin = findFloor(four,1001,mid);
			count = count+ (fin*arr[4]);
	}
	if(arr[5]!=0)
	{
		int fin = findFloor(five,1001,mid);
			count = count+ (fin*arr[5]);
	}
	if(arr[6]!=0)
	{
		int fin = findFloor(six,1001,mid);
			count = count+ (fin*arr[6]);
	}
	if(arr[7]!=0)
	{
		int fin = findFloor(seven,1001,mid);
		count = count+ (fin*arr[7]);
	}
	if(arr[8]!=0)
	{
		int fin = findFloor(eight,1001,mid);
			count = count+ (fin*arr[8]);
	}
	
	if(count<parantha)
	return false;
	
	else
	return true;
}
int  main()
{
	precompute();
	ios_base::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
	 ll test;
	 cin>>test;
	 while(test--)
	 {
		int parantha;
		cin>>parantha;
		int total;
		cin>>total;
		int arr[9];
		for(int i =0 ;i<9;i++)
		{
			arr[i] = 0;
		}
		for(int i = 0 ;i<total;i++)
		{
			 int t;
			 cin>>t;
			 arr[t]++;
		}
		long long int ans = 0;
		long long int left  = 0; 
		long long int right =  100000000;
		while(left<=right)
		{
			long long mid = (left+right)/2;
			bool track = check(arr,mid,parantha);
			if(track==true)
			{
				ans = mid;
				right = mid-1;
			}
			else
			{
				left = mid+1;
			}
		}
		cout<<ans<<endl;
	 }
}


