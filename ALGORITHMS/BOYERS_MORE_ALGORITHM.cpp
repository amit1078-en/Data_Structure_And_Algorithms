// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find majority element in the array
// a: input array
// size: size of input array
int majorityElement(int a[], int size)
{
   //BOYERS MOORE VOTING ALGORITHM TO FIND THE OCCURANCE OF ELEMENTING MORE THAN N/2 TIMES IN ARRAY,LINKEDLIST
   //STEP 1 IS TRAVERSE ARRAY
   int ans = a[0];
   int index = 1;
   for(int i   =1 ; i<size   ;i++)
   {
      if(a[i]==ans)
      {
          index++;
      }
      else if(a[i]!=ans &&   index == 1)
      {
          index=1;
          ans = a[i];
      }
      else
      {
          index--;
      }
      
   }
   index =0;
   for(int i =0;i<size;i++)
   {
       if(a[i]==ans)
       {
           index++;
       }
   }
   if(index <=size/2)
   return -1;
   
   
   else
   return ans;
}

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        cout << majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends
