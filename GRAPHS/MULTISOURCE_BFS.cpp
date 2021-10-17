/*
MULTISOURCE_BFS


COVID SPREAD



VERY IMPORTANT QUESTION



Aterp is the head nurse at a city hospital. City hospital contains R*C number of wards and the structure of a hospital is in the form of a 2-D matrix.
Given a matrix of dimension R*C where each cell in the matrix can have values 0, 1, or 2 which has the following meaning:
0: Empty ward
1: Cells have uninfected patients
2: Cells have infected patients

An infected patient at ward [i,j] can infect other uninfected patient at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. Help Aterp determine the minimum units of time after which there won't remain any uninfected patient i.e all patients would be infected. If all patients are not infected after infinite units of time then simply return -1.

 


Example 1:

Input:
3 5
2 1 0 2 1
1 0 1 2 1
1 0 0 2 1 
Output:
2
Explanation:
Patients at positions {0,0}, {0, 3}, {1, 3}
and {2, 3} will infect patient at {0, 1}, 
{1, 0},{0, 4}, {1, 2}, {1, 4}, {2, 4} during 1st 
unit time. And, during 2nd unit time, patient at 
{1, 0} will get infected and will infect patient 
at {2, 0}. Hence, total 2 unit of time is
required to infect all patients.
Example 2:

Input:
3 5
2 1 0 2 1
0 0 1 2 1
1 0 0 2 1
Output:
-1
Explanation:
All patients will not be infected.
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function helpaterp() which takes a 2-D Matrix hospital as input parameter and returns the minimum units of time in which all patients will be infected or -1 if it is impossible.

Expected Time Complexity: O(R*C)
Expected Auxiliary Space: O(R*C)


Constraints:
1 = R,C = 1000
0 = mat[i][j] = 2
*/
#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++
class Solution {
public:
    int helpaterp(vector<vector<int>> &hospital)
    {
        queue<pair<int,int>> Q;
        for(int i = 0 ; i<hospital.size();i++)
        {
            for(int j = 0 ; j<hospital[0].size();j++)
            {
                if(hospital[i][j]==2)
                {
                    Q.push({i,j});
                }
            }
        }
        
        int ans = -1;
        while(!Q.empty())
        {
            ans+=1;
            int size = Q.size();
            
            while(size--)
            {
                int x = Q.front().first;
                int y = Q.front().second;
                
                Q.pop();
                
                if(x-1>=0 && hospital[x-1][y]==1)
                {
                    hospital[x-1][y] = 2;
                    Q.push({x-1,y});
                }
                if(x+1<hospital.size() && hospital[x+1][y]==1)
                {
                    hospital[x+1][y] = 2;
                    Q.push({x+1,y});
                }
                if(y-1>=0 && hospital[x][y-1]==1)
                {
                     hospital[x][y-1] = 2;
                    Q.push({x,y-1});
                }
                if(y+1<hospital[0].size() && hospital[x][y+1]==1)
                {
                     hospital[x][y+1] = 2;
                    Q.push({x,y+1});
                }
            }
        }
    
        for(int i = 0 ; i<hospital.size();i++)
        {
            for(int j = 0; j<hospital[0].size();j++)
            {
                if(hospital[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
} 
