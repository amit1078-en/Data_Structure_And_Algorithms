/*
Swap all odd and even bits 
Given an unsigned integer N. The task is to swap all odd bits with even bits. For example, if the given number is 23 (00010111), it should be converted to 43(00101011). Here, every even position bit is swapped with adjacent bit on the right side(even position bits are highlighted in the binary representation of 23), and every odd position bit is swapped with an adjacent on the left side.

Example 1:

Input: N = 23
Output: 43
Explanation: 
Binary representation of the given number 
is 00010111 after swapping 
00101011 = 43 in decimal.
Example 2:

Input: N = 2
Output: 1
Explanation: 
Binary representation of the given number 
is 10 after swapping 01 = 1 in decimal.

Your Task: Your task is to complete the function swapBits() which takes an integer and returns an integer with all the odd and even bits swapped.


Expected Time Complexity: O(1).
Expected Auxiliary Space: O(1).

Constraints:
1 = N = 109
*/
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
    {
    	vector<int> maap;
    	while(n>0)
    	{
    	    if(n&1)
    	    {
    	        maap.push_back(1);
    	    }
    	    else
    	    {
    	        maap.push_back(0);
    	    }
    	    n/=2;
    	}
    	for(int i=0 ;i<maap.size();i+=2)
    	{
    	    if(i+1<maap.size())
    	    {
    	        swap(maap[i],maap[i+1]);
    	    }
    	    if(i+1==maap.size())
    	    {
    	        if(maap[i]==1)
    	        {
    	         maap.push_back(0);
                    swap(maap[i],maap[i+1]);
    	        }
    	    }
    	}
    	int ans =0;
    	for(int i = 0; i<maap.size();i++)
    	{
    	    if(maap[i]==1)
    	    {
    	        ans+=pow(2,i);
    	    }
    	}
    	return ans;
    }
};

// { Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;//testcases
	while(t--)
	{
		unsigned int n;
		cin>>n;//input n
		
		Solution ob;
		//calling swapBits() method
		cout << ob.swapBits(n) << endl;
	}
	return 0;
}  // } Driver Code Ends
