#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below
int main()
{
     int arr[6][6];
     for(int i = 0 ; i<6;i++)
     {
         for(int j = 0 ; j<6;j++){
             cin>>arr[i][j];
         }
     }
     int MAX = -4545454;
     int  k = 0;
     for(int i = 0 ;i<6;i++)
     {
         for(int j = 0 ; j<6;j++){
             int sum = 0;
             if(i+2<6 && j+2<6){
                 
                sum = sum+ arr[i][j];
                sum = sum+arr[i][j+1];
                sum  = sum+arr[i][j+2];
                
                sum = sum+arr[i+1][j+1];
                
                sum = sum+arr[i+2][j];
                sum = sum+arr[i+2][j+1];
                sum  = sum+arr[i+2][j+2];
                k++;
             }
           //  cout<<sum<<" ";
             if(sum>MAX)
             {
                 MAX = sum;
             }
         }
        
     }
      cout<<k<<" ";
   //  cout<<MAX;
    return 0;
}

