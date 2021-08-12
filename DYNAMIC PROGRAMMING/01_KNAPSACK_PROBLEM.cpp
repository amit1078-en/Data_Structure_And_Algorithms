#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    // Returns the maximum value that  
    // can be put in a knapsack of capacity W 
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
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends

