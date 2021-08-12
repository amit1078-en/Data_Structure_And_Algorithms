/*
QUESTION 2

The task is to find the smallest number with given sum of digits as S and number of digits as D.

 

Example 1:

Input:
S = 9 
D = 2
Output:
18
Explanation:
18 is the smallest number
possible with sum = 9
and total digits = 2.
 

Example 2:

Input:
S = 20
D = 3
Output:
299
Explanation:
299 is the smallest number
possible with sum = 20
and total digits = 3.
 

Your Task:

You don't need to read input or print anything. Your task is to complete the function smallestNumber() which takes the two integers S and D and returns a string which is the smallest number if possible, else return "-1".

 

Expected Time Complexity: O(D)
Expected Auxiliary Space: O(1)
*/



#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    char getans(int num)
    {
        if(num==0)
        {
            return '0';
        }
        if(num==1)
        {
            return '1';
        }
        if(num==2)
        {
            return '2';
        }
        if(num==3)
        {
            return '3';
        }
        if(num==4)
        {
            return '4';
        }
        if(num==5)
        {
            return '5';
        }
        if(num==6)
        {
            return '6';
        }
        if(num==7)
        {
            return '7';
        }
        if(num==8)
        {
            return '8';
        }
        if(num==9)
        {
            return '9';
        }
    }
    
    
    string smallestNumber(int S, int D){
        if(D*9<S  || (D>1 && S==1))
        {
            return "-1";
        }
        else if(D==1 && S<10)
        {
        	string ans = "";
        	char s = getans(S);
        	ans.push_back(s);
            return ans;
        }
        else
        {
            string ans  = "";
            for(int i = 0;i<D;i++)
            {
            	if(i==0)
            	{
            		for(int j = 1  ;j<10;j++)
                   {
                   		if( (S-j)<=(D-i-1)*9)
                        {
                            char c = getans(j);
                            ans.push_back(c);
                            S=S-j;
                            break;
                        }
					} 
				}
                else if(i+1==D)
                {
                	 char c = getans(S);
                	ans.push_back(c);
				}
                else
                {
                    for(int j = 0  ;j<10;j++)
                   {
                   		if( (S-j)<=(D-i-1)*9)
                        {
                            char c = getans(j);
                            ans.push_back(c);
                            S=S-j;
                            break;
                        }
					} 
                }
            }
            return ans;
        }
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}   // } Driver Code Ends

