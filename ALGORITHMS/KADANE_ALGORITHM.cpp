#include<bits/stdc++.h>
using namespace std;
//KADANE ALGORITHM IS USED TO FIND SUM OF GREATEST SUBARRAY IN ARRAY
int maxSubarraySum(int arr[], int n)
{
     int temp[n];
     int sum =0;
    int maximum = -100000000;
    for(int i = 0;i<n;i++)
    {
        sum+=arr[i];
        if(sum<arr[i])
        {
            sum=arr[i];
        }
        maximum = max(maximum,sum);
    }
    return maximum;
}

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        
        cout << maxSubarraySum(a, n) << endl;
    }
}
