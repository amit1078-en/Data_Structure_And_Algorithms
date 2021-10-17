/*

Valid Pair Sum 

Given an array of size N, find the number of distinct pairs {i, j} (i != j) in the array such that the sum of a[i] and a[j] is greater than 0.

Example 1:

Input: N = 3, a[] = {3, -2, 1}
Output: 2
Explanation: {3, -2}, {3, 1} are two 
possible pairs.
Example 2:

Input: N = 4, a[] = {-1, -1, -1, 0}
Output: 0
Explanation: There are no possible pairs.
Your Task:  
You don't need to read input or print anything. Complete the function ValidPair() which takes the array a[ ] and size of array N as input parameters and returns the count of such pairs.

Expected Time Complexity: O(N * Log(N))
Expected Auxiliary Space: O(1)

Constraints:
1 = N = 105 
-104  = a[i] = 104
*/
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++


class Solution{
    
    public:
    long long ValidPair(int a[], int n) 
    { 
    	sort(a,a+n);
    	long long sum = 0;
    	for(int i = 1;i<n;i++)
    	{
    	    if(a[i]>0)
    	    {
    	        int element = 1-a[i];
    	        int index = lower_bound(a,a+n,element)-a;
    	        if(index<i)
                {
                    if(a[index]+a[i]>0)
                    {
                        sum+=i-index;   
                    }
                    else if(a[index]+a[i]<=0)
                    {
                        sum+=((i-(index))-1);
                    }
                }
    	    }
    	}
    	return sum;
    }   
};

// { Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int array[n];
		for (int i = 0; i < n; ++i)
			cin>>array[i];
	    Solution obj;
		cout << obj.ValidPair(array, n) <<"\n";
	}
	return 0; 
} 

  // } Driver Code Ends
