/*
link -> https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/616/week-4-august-22nd-august-28th/3917/
Complex Number Multiplication

Solution
A complex number can be represented as a string on the form "real+imaginaryi" where:

real is the real part and is an integer in the range [-100, 100].
imaginary is the imaginary part and is an integer in the range [-100, 100].
i2 == -1.
Given two complex numbers num1 and num2 as strings, return a string of the complex number that represents their multiplications.

 

Example 1:

Input: num1 = "1+1i", num2 = "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
Example 2:

Input: num1 = "1+-1i", num2 = "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
 

Constraints:

num1 and num2 are valid complex numbers.

*/
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int x1,y1,x2,y2;
        x1 = 0;
        x2 = 0;
        y1 = 0;
        y2 = 0; 
        if(num1[0]=='-')
        {
            int l = 1;
            while(num1[l]>='0' && num1[l]<='9')
            {
              x1*=10;
              x1+=(num1[l]-'0');
              l++;
            }
          x1*=-1;
          l+=1;
          if(l<num1.length() && num1[l]=='-')
          {
            l+=1;
            while(l<num1.length() && num1[l]>='0' && num1[l]<='9')
            {
              y1*=10;
              y1+=(num1[l]-'0');
                l++;
            }
            y1*=-1;
          }
          else
          {
            while(l<num1.length() && num1[l]>='0' && num1[l]<='9')
            {
              y1*=10;
              y1+=(num1[l]-'0');
                l++;
            }
          }
        }
        else
        {
          int l = 0;
            while(num1[l]>='0' && num1[l]<='9')
            {
              x1*=10;
              x1+=(num1[l]-'0');
              l++;
            }
          l+=1;
          if(l<num1.length() && num1[l]=='-')
          {
            l+=1;
            while(l<num1.length() && num1[l]>='0' && num1[l]<='9')
            {
              y1*=10;
              y1+=(num1[l]-'0');
                l++;
            }
            y1*=-1;
          }
          else
          {
            while(l<num1.length() && num1[l]>='0' && num1[l]<='9')
            {
              y1*=10;
              y1+=(num1[l]-'0');
                l++;
            }
        }
        }
         if(num2[0]=='-')
        {
            int l = 1;
            while(num2[l]>='0' && num2[l]<='9')
            {
              x2*=10;
              x2+=(num2[l]-'0');
              l++;
            }
           x2*=-1;
           l+=1;
          if(l<num2.length() && num2[l]=='-')
          {
            l+=1;
            while(l<num2.length() && num2[l]>='0' && num2[l]<='9')
            {
              y2*=10;
              y2+=(num2[l]-'0');
                l++;
            }
            y2*=-1;
          }
          else
          {
            while(l<num2.length() && num2[l]>='0' && num2[l]<='9')
            {
              y2*=10;
              y2+=(num2[l]-'0');
                l++;
            }
        }
         }
        else
        {
          int l = 0;
            while(num2[l]>='0' && num2[l]<='9')
            {
              x2*=10;
              x2+=(num2[l]-'0');
              l++;
            }
           l+=1;
          if(l<num2.length() && num2[l]=='-')
          {
            l+=1;
            while(l<num2.length() && num2[l]>='0' && num2[l]<='9')
            {
              y2*=10;
              y2+=(num2[l]-'0');
                l++;
            }
            y2*=-1;
          }
          else
          {
            while(l<num2.length() && num2[l]>='0' && num2[l]<='9')
            {
              y2*=10;
              y2+=(num2[l]-'0');
                l++;
            }
          }
        }
      
      int xx  = x1*x2 - y1*y2;
      int yy = x1*y2 + y1*x2;
      
      string temp;
      if(xx<0)
      {
        xx*=-1;
        temp.push_back('-');
      }
      temp+= (to_string(xx));
      temp.push_back('+');
      if(yy<0)
      {
        yy*=-1;
        temp.push_back('-');
      }
      temp+=(to_string(yy));
      temp.push_back('i');
      return temp;
    }
};
