/*
https://leetcode.com/problems/accounts-merge/
721. Accounts Merge

Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

 

Example 1:

Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Explanation:
The first and second John's are the same person as they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
Example 2:

Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]
 

Constraints:

1 <= accounts.length <= 1000
2 <= accounts[i].length <= 10
1 <= accounts[i][j] <= 30
accounts[i][0] consists of English letters.
accounts[i][j] (for j > 0) is a valid email.
*/

//approach 1 : DISJOINT UNION SET
class Solution {
public:
    int rec(int curr,int dp[])
    {
        if(curr==dp[curr])
        {
            return curr;
        }
        return rec(dp[curr],dp);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        vector<vector<string>> answer;
        int size = accounts.size();
        int dp[size+1];
        for(int i = 0; i<size;i++)
        {
            dp[i]=i;
        }
        unordered_map<string,int> maap;
        for(int i=0;i<size;i++)
        {
            int minimum = i;
             for(int k = 1;k<accounts[i].size();k++)
            {
                string temp = accounts[i][k];
                 if(maap.find(temp)!=maap.end())
                {
                    int parentoftemp = rec(maap[temp],dp);
                    minimum = min(minimum,parentoftemp);
                }
            }
            for(int k = 1;k<accounts[i].size();k++)
            {
                string temp = accounts[i][k];
                if(maap.find(temp)!=maap.end())
                {
                    int parentoftemp = rec(maap[temp],dp);
                    dp[parentoftemp] = minimum;    
                    accounts[i][k] = "-1";
                }
                dp[i] = minimum;
                maap[temp] = i;
            }
        }
    
        map<int,vector<string>> ok;
        for(int i = 0; i<size;i++)
        {
            int curr = rec(i,dp);   
            for(int k =1;k<accounts[i].size();k++)
            {
                if(accounts[i][k]!="-1")
                {
                    ok[curr].push_back(accounts[i][k]);
                }
            }
        }
        for(auto it = ok.begin();it!=ok.end();it++)
        {
            vector<string> my  = it->second;
            vector<string> press;
            press.push_back(accounts[it->first][0]);
            sort(my.begin(),my.end());
            for(string y:my)
            {
                press.push_back(y);
            }
            answer.push_back(press);
        }
        return answer;
    }
};


//Approaach 2-> DFS & HASH
class Solution {
public:
    void rec(vector<vector<string>>accounts,int curr,bool visited[],unordered_map<string,vector<int>> maap,vector<string> &w,unordered_set<string> &sh)
    {
        visited[curr] = true;
        for(int x= 1;x<accounts[curr].size();x++)
        {
            string here = accounts[curr][x];
            if(sh.find(here)==sh.end())
            {
                w.push_back(here);
                sh.insert(here);
                vector<int> all = maap[here];
                for(int i:all)
                {
                    if(!visited[i])
                    {
                        visited[i] = true;
                        rec(accounts,i,visited,maap,w,sh);
                    }
                }
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> answer;
        unordered_map<string,vector<int>> maap;
        for(int i = 0; i<accounts.size();i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                maap[accounts[i][j]].push_back(i);
            }
        }
        bool visited[accounts.size()];
        memset(visited,false,sizeof(visited));
        for(int i = 0; i<accounts.size();i++)
        {
            if(!visited[i])
            {
                unordered_set<string> ok;
                visited[i] = true;
                vector<string> temp;
                rec(accounts,i,visited,maap,temp,ok);
                sort(temp.begin(),temp.end());
                vector<string> allll;
                allll.push_back(accounts[i][0]);
                for(string s:temp)
                {
                    allll.push_back(s);
                }
                answer.push_back(allll);
            }
        }
        return answer; 
    }
};
