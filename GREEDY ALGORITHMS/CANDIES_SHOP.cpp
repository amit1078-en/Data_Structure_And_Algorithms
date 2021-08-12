/*
GREEDY PROBLEM 3
In a candy store, there are N different types of candies available and the prices of all the N different types of candies are provided to you.
You are now provided with an attractive offer.
You can buy a single candy from the store and get at most K other candies ( all are different types ) for free.
Now you have to answer two questions. Firstly, you have to find what is the minimum amount of money you have to spend to buy all the N different candies. Secondly, you have to find what is the maximum amount of money you have to spend to buy all the N different candies.
In both the cases you must utilize the offer i.e. you buy one candy and get K other candies for free.

Example 1:

Input:
N = 4
K = 2
candies[] = {3 2 1 4}

Output:
3 7

Explanation:
As according to the offer if you buy 
one candy you can take at most two 
more for free. So in the first case, 
you buy the candy which costs 1 and 
takes candies worth 3 and 4 for free, 
also you buy candy worth 2 as well.
So min cost : 1+2 =3.
In the second case, you can buy the 
candy which costs 4 and takes candies 
worth 1 and 2 for free, also you need 
to buy candy worth 3 as well. 
So max cost : 3+4 =7.
Example 2:

Input: 
N = 5
K = 4
candies[] = {3 2 1 4 5}

Output: 
1 5

Explanation:
For minimimum cost buy the candy with
the cost 1 and get all the other candies
for free.
For maximum cost buy the candy with
the cost 5 and get all other candies
for free.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function candyStore() which takes the array candies[], its size N and an integer K as input parameters and returns the minimum amount and maximum amount of money to buy all candies according to the offer.

Expected Time Complexity: O(NLogN)
Expected Auxiliary Space: O(1)


Constraints:
1 <= N <= 100000
 0 <= K <= N-1
1 <= candies[i] <= 10000

*/
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
     void merge(int arr[],int l,int m,int r)
     {
         int L = m-l+1;
         int R = r-m;
         int la[L];
         int ra[R];
         for(int i = 0 ; i<L;i++)
         {
             la[i] = arr[i+l];
         }
         for(int i = 0 ; i<R;i++)
         {
             ra[i] = arr[m+1+i];
         }
         int i = 0;
         int j = 0;
         int k = 0;
         while(i<L && j<R)
         {
             if(la[i]>=ra[j])
             {
                 arr[l+k] = ra[j];
                 k++;
                  j++;
             }
             else
             {
                 arr[l+k] = la[i];
                 k++;
                  i++;
             }
         }
         while(i<L)
         {
             arr[l+k] = la[i];
             k++;
             i++;
         }
         while(j<R)
         {
             arr[l+k] = ra[j];
             k++;
             j++;
         }
     }
     void mergesort(int arr[],int l,int r,int n)
     {
         if(r>l)
         {
             int m = l + (r-l)/2;
             mergesort(arr,l,m,n);
             mergesort(arr,m+1,r,n);
             merge(arr,l,m,r);
         }
     }
    vector<int> candyStore(int candies[], int N, int K)
    {
        
        vector<int> ans;
        mergesort(candies,0,N-1,N);
        int n = N;
        int mincost = 0;
        int maxcost = 0;
        int i = 0;
        while(n>0)
        {
            mincost = mincost+candies[i];
            i++;
            n = n-K-1;
        }
        ans.push_back(mincost);
        i = N-1;
        n =N;
        while(n>0)
        {
            maxcost = maxcost+candies[i];
            i--;
            n = n-K-1;
        }
        ans.push_back(maxcost);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends
