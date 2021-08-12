/*
https://leetcode.com/problems/permutation-sequence/submissions/
60. Permutation Sequence
Hard

2337

367

Add to List

Share
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

 

Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
Example 3:

Input: n = 3, k = 1
Output: "123"
 

Constraints:

1 <= n <= 9
1 <= k <= n!
Accepted
228.4K
Submissions
572.5K
Seen this question in a real interview before?
*/
class Solution {
public:
    unordered_set<string> SET;
    int tot;
    void backtrack(string temp,string &ans,int index,int n,int k)
    {
        if(index==n)
        {
            return ;  
        }

        for(int i  =index;i<n;i++)
        {
            swap(temp[i],temp[index]);
            if(SET.find(temp)==SET.end())
            {
           //     cout<<temp<<endl;
                SET.insert(temp);
                tot++;
                if(tot==k)
                {
                    if(ans.empty())
                    {
                        ans = temp;
                    }
                    return ;
                }
                
            }
            backtrack(temp,ans,index+1,n,k);
            if(tot==k)
            {
                return ;
            }
         //   swap(temp[i+1],temp[i]);

        }
    }
    string getPermutation(int n, int k) {
        tot = 0;
        string temp;
        SET.clear();
        for(int i = 0 ;  i<n;i++)
        {
            temp.push_back(char('1'+i));
        }
        string ans;
        backtrack(temp,ans,0,n,k);
        return ans;
    }
};



//optimised solution

int fact[10];
int flag = 1;
class Solution {
public:
    Solution()
    {
        if(flag==1)
        {
            flag = 0;
            int num = 1;
           for(int i =  1; i<10;i++)
           {
               num*=i;
               fact[i] = num;
           }
        }
    }
    string getPermutation(int n, int k) {
        k--;
        string ans;
        bool track[n+1];
        memset(track,false,sizeof(track));
        for(int i = 0 ; i<n-1;i++)
        {
            int res = k/fact[(n-1-i)];
            int ind = 0;
            for(int j = 1 ; j<n+1;j++)
            {
                if(!track[j])
                {
                    
                    if(ind==res)
                    {
                        track[j] = true;
                        ans.push_back(char('0'+j));
                        break;
                    }
                    ind++;
                }
            }
            if(k!=0)
            {
                k  = k%(fact[n-i-1]);
            }
        }
        for(int i = 1 ; i<n+1;i++)
        {
            if(!track[i])
            {
                ans.push_back(char('0'+i));
                break;
            }
        }
        return ans;
    }
};
