/*

834. Sum of Distances in Tree


There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes.

 

Example 1:


Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
Output: [8,12,6,10,10,10]
Explanation: The tree is shown above.
We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
equals 1 + 1 + 2 + 2 + 2 = 8.
Hence, answer[0] = 8, and so on.
Example 2:


Input: n = 1, edges = []
Output: [0]
Example 3:


Input: n = 2, edges = [[1,0]]
Output: [1,1]
 

Constraints:

1 <= n <= 3 * 104
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
The given input represents a valid tree.

*/

class Solution {
public:
    pair<int,int> maap[30001];
    pair<int,int> bfs(vector<int> graph[],int element,bool check[])
    {
      check[element] = true;
      bool empty = true;
      int val   = 0; 
      int child = 0; 
      pair<int,int> answer;
      for(int temp:graph[element])
      {
        if(temp==element)
        {
          continue;
        }
        empty = false;
        if(!check[temp])
        {
          child+=1;
          pair<int,int> chh = bfs(graph,temp,check);
          child+=chh.first;
          val+=chh.second;
        }
      }
      if(empty==true)
      {
        pair<int,int> p;
        p.first  = 0;
        p.second = 0;
        maap[element] = p;
        answer.first = 0;
        answer.second = 0;
        return answer;
      }
      val+=(child);
      answer.first = child;
      answer.second = val;
      maap[element] = answer; 
      return answer;
    }
  
    void rec(vector<int> graph[],int element,bool check[],vector<int> &answer,int parent,int n)
    {
      check[element] = true;
      if(element==0)
      {
        answer[element] = maap[element].second;
      }
      else
      {
        // cout<<element<<" -> "<<parent<<endl;
        int val = answer[parent];
        answer[element] = val+(n-2-maap[element].first)-(maap[element].first+maap[element].second)+maap[element].second;
      }
      for(int temp:graph[element])
      {
        if(temp==element)
        {
          continue;
        }
        if(!check[temp])
        {
          rec(graph,temp,check,answer,element,n); 
        }
      }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) 
    {
            vector<int> answer;
        vector<int> graph[n+1];
        for(int i = 0;i<edges.size();i++)
        {
          int x = edges[i][0];
          int y = edges[i][1];
          graph[x].push_back(y);
          graph[y].push_back(x);
        }
      
    
       
        for(int i = 0 ; i<n;i++)
        {
          answer.push_back(0);
        }
      bool check[n];
      memset(check,false,sizeof(check));
      bfs(graph,0,check);
      memset(check,false,sizeof(check));
      rec(graph,0,check,answer,0,n);
  
      return answer;
    }
};
