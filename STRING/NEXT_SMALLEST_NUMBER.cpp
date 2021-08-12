/*
Problem Description

Given a number A in a form of string.

You have to find the smallest number that has same set of digits as A and is greater than A.

If A is the greatest possible number with its set of digits, then return -1.



Problem Constraints
 1 <= A <= 10100000

 A doesn't contain leading zeroes.



Input Format
First and only argument is an numeric string denoting the number A.



Output Format
Return a string denoting the smallest number greater than A with same set of digits , if A is the largest possible then return -1.



Example Input
Input 1:

 A = "218765"
Input 2:

 A = "4321"


Example Output
Output 1:

 "251678"
Output 2:

 "-1"


Example Explanation
Explanation 1:

 The smallest number greater then 218765 with same set of digits is 251678.
Explanation 2:

 The given number is the largest possible number with given set of digits so we will return -1.


Note:You only need to implement the given function. Do not read input, instead use the arguments to the function. Do not print the output, instead return values as specified. Still have a doubt? Checkout Sample Codes for more details.
submission-count
11928
successful submissions.
*/

string Solution::solve(string A) {
    string temp = A;
    if(temp.length()==1)
    {
        return "-1";
    }
    A = temp;
    int len = A.length()-1; 
    for(int i = len;i>=0;i--)
    {
    if(i==0)
     {
         return "-1";
     }
     if(A[i]-'0'<=A[i-1]-'0')
     {
        continue; 
     }
         int break_point = i-1;
         int s;
         for(int k = len;k>=i;k--)
         {
             if(A[k]-'0' > A[i-1]-'0')
             {
                 s = k;
                 break;
             }
         }
         swap(A[s],A[break_point]);
          reverse(A.begin()+i,A.end());
        break;
    }
    return A;  
}
