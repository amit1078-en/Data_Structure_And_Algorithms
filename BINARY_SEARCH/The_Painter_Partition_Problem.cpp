/*The Painter's Partition Problem 
Hard Accuracy: 66.71% Submissions: 790 Points: 8
Dilpreet wants to paint his dog's home that has n boards with different lengths.
The length of ith board is given by arr[i] where arr[] is an array of n integers.
He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board. 
The problem is to find the minimum time to get this job done if all painters start together with the
constraint that any painter will only paint continuous boards, say boards numbered {2,3,4} or only board {1}
or nothing but not boards {2,4,5}

n = 5
k = 3
arr[] = {5,10,30,20,15}
Output: 35
Explanation: The most optimal way will be:
Painter 1 allocation : {5,10}
Painter 2 allocation : {30}
Painter 3 allocation : {20,15}
Job will be done when all painters finish
i.e. at time = max(5+10, 30, 20+15) = 35

*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool  check(int arr[],int n,int k,long long mid)
    {
        long long temp  =0;
        int worker = 1;
        for(int i = 0;i<n;i++)
        {
            temp=temp+arr[i];
            if(temp>mid)
            {
                temp = arr[i];
                worker++;
            }
        }
        if(worker>k)
            {
                return false;
            }
        return true;
    }
    long long minTime(int arr[], int n, int k)
    {
        long long ans = 0;
        int left = INT_MIN;
         long long rig = 0;
        for(int i = 0 ;i<n;i++)
        {
            left = max(left,arr[i]);
            rig = rig + arr[i];
        }
           long long lef = left;
        while(lef<=rig)
        {
            long long mid = (lef+rig)/2;
            bool track = check(arr,n,k,mid);
            
            if(track==true)
            {
                ans = mid;
                rig = mid-1;
            }
            else
            {
                lef = mid+1;
            }
        }
        return ans;
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
} 
