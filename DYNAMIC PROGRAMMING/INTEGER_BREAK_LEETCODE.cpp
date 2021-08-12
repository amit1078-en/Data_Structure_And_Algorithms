/*
Leetcode - 343 INTEGER BREAK
https://leetcode.com/problems/integer-break/
Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.

 

Example 1:

Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:

Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 

Constraints:

2 <= n <= 58
*/


//code
//ALGORITHM 
//1.CREATE A UNIVERSAL ARRAY KNOWS AS VAL OF SIZE OF 60
//2. THEN IN CONSTRUCTOR INITIALISE THE VALUES FROM 1 TO 4 AS THESE ONLY
//THEN TRAVERSE FROM  5 TO 58 AND ITERATE FOR JTH VALUES FROM 1 TO JTH/2
AND CHOSE MAX VALUES FOR THESE


//TOP DOWN APPROACH /ITERATIVE

int val[60];
bool  f = false;
class Solution 
{
public:
    Solution()
    {
      
    if(f==false)
    {
      f = true;
      val[1] = 1;
      val[2] = 2;
      val[3] = 3;
      val[4] = 4;
      for(int j = 5;j<59;j++)
      {
        int mx = 0;
        for(int i = 1 ; i<=j/2;i++)
        {
          mx = max(val[i]*val[j-i],mx);
        }
        val[j] = mx;
      }
      val[2] = 1;
      val[3] = 2;
    }
    }
    int integerBreak(int n) 
	{
       return val[n];
    }
};	



//bottom down approach // memonised approach 



class Solution {
public:
    int val[60];
    int help(int n)
    {
      if(n==2 || n==3 || n==1)
      {
        return n;
      }
      if(val[n]!=0)
      {
        return val[n];
      }
      int  value = 0;
      for(int j = 1;j<=n/2;j++)
      {
        val[j]    = help(j);
        val[n-j] = help(n-j);
        value  = max(val[j]*val[n-j],value);
      }
      val[n] = value;
      return val[n];
    }
    int integerBreak(int n) {
        if(n==2 || n==3)
        {
          return n-1;
        }
        memset(val,0,sizeof(val));
        return help(n);
    }
};
