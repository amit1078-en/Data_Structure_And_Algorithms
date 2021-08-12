/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45
*/
//memonization
class Solution {
public:
    int arr[46];
    int  help(int n,int steps)
    {
        if(n<steps)
        {
            return  0 ;
        }
        if(n==steps)
        {
           
            return 1;
        }
        
        if(arr[steps]>0)
        {
            return arr[steps];
        }
        
        
         arr[steps] = help(n,steps+1) + help(n,steps+2);
        return arr[steps];
    }
    int climbStairs(int n) {
       // memset(arr,-1,sizeof(arr));
        int ans = help(n,0);
        //dynamic problem
         for(int i = 0;  i<n;i++)
        {
            cout<<arr[i]<<endl;
        }
        return ans;
        
    }
};

//bottom upclass Solution {
public:
    int arr[48];
    int climbStairs(int n) {
       arr[n] = 1;
        arr[n+1] = 0;
        for(int i =  n-1;i>=0;i--)
        {
            arr[i] = arr[i+1]+arr[i+2];
        }
        return arr[0];       
    }
};

