/*
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
You must solve the problem without using any built-in library for handling large integers (such as BigInteger).
 You must also not convert the inputs to integers directly.

 

Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"
Example 2:

Input: num1 = "456", num2 = "77"
Output: "533"
Example 3:

Input: num1 = "0", num2 = "0"
Output: "0"
 

Constraints:

1 <= num1.length, num2.length <= 104
num1 and num2 consist of only digits.
num1 and num2 don't have any leading zeros except for the zero itself.



Link-> https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/614/week-2-august-8th-august-14th/3875/
*/



class Solution {
public:
  string ans(string &num1,string &num2,int l1,int l2)
  {
      int carry = 0 ;
          while(l1>=0 && l2>=0)
          {
            int sum = carry+num1[l1]-'0' + num2[l2]-'0';
            carry = sum/10;
            num1[l1] = (sum%10)+'0';
            l1-=1;
            l2-=1;
          }
          while(l1>=0)
          {
            int sum = carry+num1[l1]-'0';
            carry = sum/10;
            num1[l1] = (sum%10)+'0';
            l1-=1;
          }
          reverse(num1.begin(),num1.end());
          while(carry>0)
          {
            num1.push_back('0'+carry%10);
            carry/=10;
          }
          reverse(num1.begin(),num1.end());
          return num1;
  }
    string addStrings(string num1, string num2) {
        int l1 = num1.size()-1;
        int l2 = num2.size()-1;
        if(l1>=l2)
        {
          return ans(num1,num2,l1,l2);
        }
        return ans(num2,num1,l2,l1);
    }
};
