// write a programe to add two numbers

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
int knapSack(int W, int wt[], int val[], int n) 
    { 
      int arr[n+1][W+1];
      for(int i = 0;i<=n;i++)
      {
          for(int j = 0;j<=W;j++)
          {
              arr[i][j]=0;
          }
      }
      for(int i = 0;i<n;i++)
      {
          int weight = wt[i];
          int cost = val[i];
          for(int j = 1;j<=W;j++)
          {
              if(j<weight)
              {
                  arr[i+1][j] = arr[i][j];
              }
              else
              {
                  int val = cost+(arr[i][j-weight]);
                  if(val>arr[i][j])
                  {
                      arr[i+1][j] = val;
                  }
                  else
                  {
                      arr[i+1][j] = arr[i][j];
                  }
              }
          }
      }
      int ans = arr[n][W];
      return ans;
    }
    int findsub(int minutes[],int marks[],int n,int k,int ans){
    	int A = 0;
        for(int i = 0;i<n;i++){
        	for(int j = i+1;j<n;j++){
        		if(marks[i]>marks[j]){
        			swap(marks[i],marks[j]);
        			swap(minutes[i],minutes[j]);
				}
			}
		}
		float freq = float (ans)/float(k);
		for(int i = 0;i<n;i++)
		{
			if(minutes[i]<=k)
			{
				float  temp = float (marks[i])/float(minutes[i]);
				if(temp<freq || freq-temp<0.00001)
				{
					A = marks[i];
					break;
				}
			}
		}
		cout<<freq<<" frequency"<<endl;
    	return A;
	}
int  main()
{
	ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	 ll test;
	 cin>>test;
	 while(test--)
	 {
			int n,k;
			cin>>n>>k;
			int marks[n+1];
			int minutes[n+1];
			for(int i =0;i<n;i++){
				int f,s;
				cin>>f>>s;
				marks[i] = f;  
				minutes[i] = s;
			}
			int arr[2][k+1];
			for(int i = 0  ;i <2;i++){
				for(int j = 0;j<=k;j++){
					if(i == 0)
					{
						arr[i][j] = 0;
					}
					else
					{
						arr[i][j] = INT_MIN;	
					}
				}
			}
			 for(int i = 0;i<n;i++){
			 	int temp = minutes[i];
			 	for(int j =k-temp;j>=0;j--){
			 		arr[0][j+temp] = max(arr[0][j+temp],marks[i]+arr[0][j]);
			 		arr[1][j+temp] = max({arr[1][j+temp],marks[i]+arr[1][j],arr[0][j]});
				 }
			 }
			cout<<arr[1][k]<<endl;     
			
	 }
}


