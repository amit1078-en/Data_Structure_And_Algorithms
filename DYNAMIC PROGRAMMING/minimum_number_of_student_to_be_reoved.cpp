/*
Accuracy: 38.01% Submissions: 3521 Points: 50


Input:
N = 6
H[] = {9, 1, 2, 3, 1, 5}
Output:
2
Explanation:
We can remove the students at 0 and 4th index.
which will leave the students with heights
1,2,3, and 5.
Example 2:
Input:
N = 3
H[] = {1, 2, 3} 
Output :
0
Explanation:
All of the students are able to see the
assembly without removing anyone.



*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int H[], int N) {
        //longest increasig subsequence
        
        int dp[N+1];
        for(int i  = 0 ; i<=N;i++)
        {
            dp[i] = INT_MAX;
        }
        dp[0]= INT_MIN;
        for(int i = 0 ; i<N;i++)
        {
            int ind = upper_bound(dp,dp+N+1,H[i])-dp;
            if(dp[ind-1]<H[i] && dp[ind]>H[i]){
                dp[ind] = H[i];
            }
        }
        
        for(int j = N;j>0;j--)
        {
            if(dp[j]!=INT_MAX)
            {
                return N-j;
                break;
            }
        }
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
