#include <iostream>
#include<string>
using namespace std;
int main()
{
 int T;
 string s;
 int sum1=0,sum2=0,abs;
 cin>>T;
 cin>>s;
 while(T>0)
 {
  sum1=0;
  sum2=0;
  abs=0;
  for (int i = 1; i <= s.length(); i++)
  {
   if(i%2==0)
   {
    sum1+=(int)s[i];
   }
   else
   {
    sum2=(int)s[i];
   }
  }
  if(sum1>sum2)
  { abs=sum1-sum2;}
  else
  { abs=sum2-sum1;}
  
  if(abs%3==0||abs%5==0||abs%7==0)
  { cout<<"Prime String"<<endl;}
  else
  { cout<<"Causal String"<<endl;}
  
  T--;
  sum1=0;
  sum2=0;
  abs=0;
 }
 return 0;
}
