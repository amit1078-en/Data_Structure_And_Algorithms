/*
Count the number of possible triangles 
Medium Accuracy: 45.44% Submissions: 18980 Points: 4
Given an unsorted array arr[] of n positive integers. Find the number of triangles that can be formed with three different array elements as lengths of three sides of triangles. 

Example 1:

Input: 
n = 3
arr[] = {3, 5, 4}
Output: 
1
Explanation: 
A triangle is possible 
with all the elements 5, 3 and 4.
Example 2:

Input: 
n = 5
arr[] = {6, 4, 9, 7, 8}
Output: 
10
Explanation: 
There are 10 triangles
possible  with the given elements like
(6,4,9), (6,7,8),...
 

Your Task: 
This is a function problem. You only need to complete the function findNumberOfTriangles() that takes arr[] and n as input parameters and returns the count of total possible triangles.

Expected Time Complexity: O(n2).
Expected Space Complexity: O(1).

Constraints:
3 <= n <= 103
1 <= arr[i] <= 103
*/
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int find(int e,int ar[],int n)
    {
        int ans  =0;
        int l = 0;
        int r =n;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(ar[mid]>=e)
            {
                r = mid-1; 
            }
            else
            {
                ans = mid;
                l = mid+1;
            }
        }
        return ans;
    }
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int ar[], int n){
        int ans = 0;
        
        sort(ar,ar+n);
        for(int i = 0 ; i<n-2;i++)
        {
            int s = ar[i];
            for(int l = i+1 ; l<n-1;l++)
            {
                int ele = s+ar[l];
                if(ele>ar[n-1])
                {
                    ans+=(n-1-l);
                }
                else
                {
                    int  ind = find(ele,ar,n-1);
                  //  cout<<ar[i]<<" "<<ar[l]<<" "<<ar[ind]<<endl;
                    ans+=(ind-l);
                }
            }
            
        }
        // approach 
        //firstly we have to sort theb array 
        //then we have to
        
        return ans;
    }

};


// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.findNumberOfTriangles(arr,n) <<endl;
    }
    return 0;
} 
