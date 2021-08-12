/*
Given a binary array arr of size N and an integer M. Find the maximum number of consecutive 1's produced by flipping at most M 0's.
 

Example 1:

Input:
N = 3
arr[] = {1, 0, 1}
M = 1
Output:
3
Explanation:
Maximum subarray is of size 3
which can be made subarray of all 1 after
flipping two zeros to 1.
Example 2:

Input:
N = 11
arr[] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1}
M = 2
Output:
8
Explanation:
Maximum subarray is of size 8
which can be made subarray of all 1 after
flipping two zeros to 1.
 

Your Task:
Complete the function findZeroes() which takes array arr and two integers n, m, as input parameters and returns an integer denoting the answer.
 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
 

Constraints:
1 <= N <= 107
0 <= M <= N
0 <= arri <= 1

Company Tags
Topic Tags
Related Courses
Related Interview Experiences



link -> https://practice.geeksforgeeks.org/problems/maximize-number-of-1s0905/1#https://practice.geeksforgeeks.org/problems/maximize-number-of-1s0905/1#
*/
// { Driver Code Starts.
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) 
    {
        int start = -1;
        int end = -1;
        int zero = 0;
        
        if(m==0)
        {
             int answer = 0;
            for(int i = 0 ; i<n;i++)
            {
               if(arr[i]==1)
               {
                    int k = i+1;
                    while(k<n && arr[k]==1)
                    {
                        k++;
                    }
                    answer = max(answer,k-i);
                    i = k-1;
               }
            }
            return answer;
        }
        
        for(int i = 0 ; i<n;i++)
        {
            if(arr[i]==0)
            {
                if(start==-1)
                {
                    start = i;
                }
                zero+=1;
                if(zero==m)
                {
                    end = i;
                    break;
                }
            }
        }
        
        if(end==n-1 || end==-1 )
        {
            return n;      
        }
        
        int ans = end+1;
        int k=0;
        
        for(int i = end+1;i<n;i++)
        {
            if(arr[i]==0)
            {
              
                int l = k;
                for(int j = start+1;j<n;j++)
                {
                    if(arr[j]==0)
                    {
                        start = j;
                        break;
                    }
                    if(arr[j]==1)
                    {
                        if(l==k)
                        {
                            k = j;
                        }
                    }
                }
                if(k==l)
                {
                    k = start;
                }
            }
            ans= max(ans,i-k+1);
        }
        return ans;
    }  
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends


