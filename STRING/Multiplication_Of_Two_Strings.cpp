/*


Given two numbers as stings s1 and s2. Calculate their Product.


Example 1:

Input:
s1 = "33"
s2 = "2"
Output:
66
Example 2:

Input:
s1 = "11"
s2 = "23"
Output:
253

Your Task:

You don't need to read input or print anything. Your task is to complete the function multiplyStrings() which takes two strings s1 and s2 as input and returns their product as a string.


Expected Time Complexity: O(n1* n2)
Expected Auxiliary Space: O(n1 + n2) ; where n1 and n2 are sizes of strings s1 and s2 respectively.


Constraints:
1 = length of s1 and s2 = 103


*/

#include<bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string num1, string num2) 
    {
      int dp[num2.length()+2][(num1.length()+num2.length())+(num2.length())+10];
        memset(dp,0,sizeof(dp));
        
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int neg1 = 1;
        int neg2 = 1;
        if(num1[num1.length()-1]=='-')
        {
            neg1=-1;
            num1.pop_back();
        }
        if(num2[num2.length()-1]=='-')
        {
            neg2 = -1;
            num2.pop_back();
        }
        int maxx  = num2.length();
        for(int i = 0 ;i<num2.length();i++)
         {
            int k = 0;
            int carry = 0;
            for(int j = 0 ;j<num1.length();j++)
            {
                
                carry+=((num2[i]-'0') * (num1[j]-'0'));
                dp[i][j+i] = carry%10;
                 carry/=10;
                maxx = max(maxx,i+j);
            }
            int z = num1.length();
            while(carry>0)
            {
                 maxx = max(maxx,i+z);
                dp[i][z+i] = carry%10;
                carry/=10;
                z++;
            }
        }
    
        string ans ;
        string temp;
        int carry = 0;
        for(int k = 0 ; k<=maxx;k++)
        {
           
            for(int j = 0;j<num2.length();j++)
            {
                carry+=(dp[j][k]);
            }
          
                 temp.push_back('0'+carry%10);
                  carry/=10;
    
        }
        // cout<<temp<<endl;
        
        while(carry>0)
        {
            temp.push_back('0'+carry%10);
            carry/=10;
        }
        while(temp.length()>1  && temp[temp.length()-1]=='0')
        {
            temp.pop_back();
        }
        if(neg1==-1 || neg2==-1)
        {
            if(neg1==-1 && neg2==-1)
            {
                reverse(temp.begin(),temp.end());
        return temp;
            }
            else
            {
                if(temp[temp.length()-1]!='0')
                {
                temp.push_back('-');    
                }
                
            }
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }

};

// { Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}  // } Driver Code Ends
