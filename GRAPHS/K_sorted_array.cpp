/*
k sorted array 
Easy Accuracy: 48.64% Submissions: 2742 Points: 2
Given an array of n distinct elements. Check whether the given array is a k sorted array or not. A k sorted array is an array where each element is at most 
k distance away from its target position in the sorted array.


Example 1:

Input:
N=6
arr[] = {3, 2, 1, 5, 6, 4} 
K = 2
Output: Yes
Explanation:
Every element is at most 2 distance 
away from its target position in the
sorted array.  
Example 2:

Input:
N=7
arr[] = {13, 8, 10, 7, 15, 14, 12}
K = 1
Output: No

Your Task:
Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function 
isKSortedArray() that takes array arr, integer n and integer k as parameters and return "Yes" if the array is a k sorted array else return "No".


Expected Time Complexity: O(NlogN).
Expected Auxiliary Space: O(N).


Constraints:
1 = N = 105
0 = K = N
*/
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k)
    {
        vector<int> temp;
        unordered_map<int,int> track;
        for(int i = 0;i<n;i++)
        {
            temp.push_back(arr[i]);
        }
        sort(temp.begin(),temp.end());
        for(int i = 0 ;i<n;i++)
        {
            int element = arr[i];
            int index = lower_bound(temp.begin(),temp.end(),element)-temp.begin();
            index+=track[element];
            if(abs(index-i)>k)
            {
                return "No";
            }
            track[element]+=1;
        }
        return "Yes";
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    cin>>k;
	    Solution ob;
	cout <<ob.isKSortedArray(arr, n, k)<<endl;
	}
	return 0;	 
} 
