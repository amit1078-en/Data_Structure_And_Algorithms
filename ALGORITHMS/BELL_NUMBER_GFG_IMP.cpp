/*
Bell Numbers 
Easy Accuracy: 42.7% Submissions: 1285 Points: 2
Given a set of n elements, find number of ways of partitioning it.

 

Example 1:

Input:
N = 2
Output: 2
Explanation:
Let the set be 
{1, 2}:
{ {1}, {2} } { {1, 2} }
 

Example 2:

Input:
N = 3
Output: 5

Your Task:  
You don't need to read input or print anything. Your task is to complete the function bellNumber() which takes the integer N 
as input parameters and returns the number of ways of partitioning n elements. Since the value can be quite large print the 
value modulo 109+7.

Expected Time Complexity: O(N^2)
Expected Auxiliary Space: O(N^2)

 

Constraints:

1 = N = 1000
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

bool track = true;
int arr[1001][1001];
int mod = 1000000007;
class Solution{
public:
    
    int bellNumber(int n)
    {
        if(track)
        {
            track = false;
            arr[0][0] = 1;
            arr[1][0] = 1;
            arr[1][1] = 2;
            for(int i = 2;i<=1000;i++)
            {
                arr[i][0] = arr[i-1][i-1];
                for(int j = 1 ; j<=i;j++)
                {
                    arr[i][j] = (arr[i][j-1]+arr[i-1][j-1])%mod;
                }
            }
        }
     return arr[n-1][n-1];
    }
};


// { Driver Code Starts.



int main()
{
    Solution obj;
    int t; cin >> t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<obj.bellNumber(n)<<"\n";
    }
    return 0;
} 
