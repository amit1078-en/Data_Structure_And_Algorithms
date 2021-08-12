//Matchsticks to Square



/*


You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. 
You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, 
and each matchstick must be used exactly one time.

Return true if you can make this square and false otherwise.


Input: matchsticks = [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
Example 2:

Input: matchsticks = [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks.

*/
 
 
 
 class Solution {
public:
    vector<int> r;
    bool flag = false;
    long long int arr[4];
    vector<vector<int>> ar;
      vector<vector<int>> ab;
    void check(vector<int> array,int size,int i,long long int req,long long int sum,vector<int> &a,vector<int> &b)
    {
        
        if(i==size ||arr[0]>req || arr[1]>req)
        {
            if(arr[0]==arr[1] && arr[0]==req)
            {
                flag = true;
                ar.push_back(a);
                ab.push_back(b);
            }
            
           return ; 
        }
        if(arr[0]+array[i]<=req)
        {
            a.push_back(array[i]);
            arr[0]+=array[i];
            check(array,size,i+1,req,sum,a,b);
            arr[0]-=array[i];
            a.pop_back();
            
        }
        
        else{
            return ;
        }
        
        
        if(arr[1]+array[i]<=req)
        {
              b.push_back(array[i]);
            arr[1]+=array[i];
            check(array,size,i+1,req,sum,a,b);
            arr[1]-=array[i];
            b.pop_back();
        }
    
            return ;
    }
    
    
    bool help(vector<int> ans, int l,int  r,long long int track,long long int req)
    {
        if(req==track)
            return true;
        
        
        if(track>req)
        {
            return false;
        }
        
        if(l==r)
        {
            if(req==track)
            return true;
            
            
            return false;
        }
        
        bool re =  help(ans,l+1,r,track+ans[l],req);
        bool er = help(ans,l+1,r,track,req);
        return re|er;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        flag = false;
        long long int sum = 0;
        for(int i:matchsticks)
        {
            sum+=i;
        }
        if(sum%4!=0)
        {
            return false;
        }
        
        memset(arr,0,sizeof(arr));
        vector<int> arr1;
        vector<int> arr2;
        check(matchsticks,matchsticks.size(),0,sum/2,sum,arr1,arr2);
        
        
        
        if(flag)
        {
            for(int i = 0 ;i<ar.size();i++)
            {
                vector<int> re = ar[i];
                bool e = help(re,0,re.size(),0,sum/4);
                
                if(e)
                {
                    bool f =  help(ab[i],0,ab[i].size(),0,sum/4);
                
                   if(f)
                      return true;
 
                }               
            }
            
        }
        return false;
    }
};
