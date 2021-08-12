// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
// Prints minimum number of platforms reqquired 

class Solution {
  public:
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<pair<int,int>>temp;
       vector<int> answer;
       int quan = 0;
       int cost = 0;
       for(int i =  0 ; i <n;i++)
       {
            temp.push_back({arr[i].profit,arr[i].dead});
       }
        
        
        bool dis[101];
    	memset(dis,false,sizeof(dis));
        for(int i = 0 ; i<n;i++)
        {
            bool ys = false;
            for(int j = temp[i].second;    j>0;   j--)
            {
                if(dis[j]==false)
                {
                    ys = true;
                    dis[j] = true;
                    break;
                }
            }
            if(ys==true)
            {
                quan++;
                cost+=(temp[i].first);
            }
        }
       answer.push_back(quan);
       answer.push_back(cost);
       return answer;
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}

