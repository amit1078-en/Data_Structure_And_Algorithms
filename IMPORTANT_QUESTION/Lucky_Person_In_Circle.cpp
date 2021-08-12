/*
Given N people standing in a circle where 1st is having a sword, find the luckiest person in the circle, if, 
from 1st soldier who is having a sword each has to kill the next soldier and handover the sword to next soldier, 
in turn, the soldier will kill the adjacent soldier and handover the sword to next soldier such that one soldier 
remains in this war who is not killed by anyone.
 

Example 1:

Input:
N = 5
Output:
3
Explanation:
In first go 1 3 5 (remains) 
as 2 and 4 killed by 1 and 3. 
In second go 3 will remain 
as 5 killed 1 and 3rd killed 5 
hence, 3 remains alive.
Example 2:

Input:
N = 10
Output:
5
Explanation:
In first 1 3 5 7 9 
remains as 2 4 6 8 10 
were killed by 1 3 5 7 
and 9. In second 1 5 9 
are left as 1 kills 3 
and  5 kill the 7th 
soldier.In third 5th 
soldiers remain alive as 
9 kills the 1st soldier and 
5 kill the 9th soldier.

Your Task:
You don't need to read input or print anything. Your task is to complete the function find() 
which takes an integer N as input parameter and returns the output as the soldier 
who was lucky in the game.
 

Expected Time Complexity: O(log N)
Expected Space Complexity: O(1)
 

Constraints:
1<=N<=108

Topic Tags
*/

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int find(int N){
        int ans = 1;
        int step = 1;
        while(N>1)
        {
            step*=2;
            if(N&1)
            {
                ans = ans+step;
            }
            N/=2;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.find(N) << endl;
    }
    return 0; 
} 
