/*
Given an array containing N integers and an integer K., Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.

 

Example 1:
 

Input :
A[] = {10, 5, 2, 7, 1, 9}
K = 15
Output : 4
Explanation:
The sub-array is {5, 2, 7, 1}.
Example 2:

Input : 
A[] = {-1, 2, 3}
K = 6
Output : 0

Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function smallestSubsegment() that takes an array (A), sizeOfArray (n),  sum (K)and returns the required length of the longest Sub-Array. The driver code takes care of the printing.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
*/
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    {
        int ans = 0;
        unordered_map<int,int> array;
        array[arr[0]] = 0;
        for(int i  = 1;i<n;i++)
        {
            arr[i]+=arr[i-1];
            array[arr[i]] = i;
        }
        for(int i = 0 ; i<n;i++)
        {
            if(i==0)
            {
                auto it = array.find(k);
                if(it!=array.end())
                {
                    int dis = it->second-i+1;
                    ans = max(ans,dis);
                }
            }
            else
            {
                int element  =arr[i]-arr[i-1];
                int search = k-element;
                auto it = array.find(search+arr[i]);
                if(it!=array.end())
                {
                    int dis = it->second-i+1;
                    ans = max(ans,dis);
                }
            }
        }
        return ans;
    } 

};
int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
