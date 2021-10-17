/*
All Unique Permutation of an array

Given an array arr[] of length n. Find all possible unique permutations of the array.


Example 1:

Input: 
n = 3
arr[] = {1, 2, 1}
Output: 
1 1 2
1 2 1
2 1 1
Explanation:
These are the only possible unique permutations
for the given array.
Example 2:

Input: 
n = 2
arr[] = {4, 5}
Output: 
4 5
5 4

Your Task:
You don't need to read input or print anything. You only need to complete the function uniquePerms() that takes an integer n, and an array arr of size n as input and returns a sorted list of lists containing all unique permutations of the array.


Expected Time Complexity:  O(n*n!)
Expected Auxilliary Space: O(n*n!)
 

Constraints:
1 = n = 10
1 = arri = 10
*/
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void rec(int ind,int size, set<vector<int>> &maap,vector<int> &arr)
    {
        for(int i = size;i>=0;i--)
        {
            swap(arr[i],arr[size]);
            if(maap.find(arr)==maap.end())
            {
                maap.insert(arr);
                rec(i,size,maap,arr);
            }
             swap(arr[i],arr[size]);
            
        }
    }
    vector<vector<int>> uniquePerms(vector<int> arr ,int n) 
    {
        vector<int> temp;
        sort(arr.begin(),arr.end());
        set<vector<int>> maap;
        rec(n-1,n-1,maap,arr);
        vector<vector<int>> answer;
        for(auto it = maap.begin();it!=maap.end();it++)
        {
            answer.push_back(*it);
        }
        return answer;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends
