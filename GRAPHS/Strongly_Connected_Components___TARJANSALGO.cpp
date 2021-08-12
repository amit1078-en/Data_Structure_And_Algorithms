class Solution {
public:
    void dfs(long long dis[],long long help[],long long top,vector<long long> array[],unordered_set<long long> seet,bool check[],vector<vector<int>> &ans,stack<long long> MYSTACK,long long n){
        static long long k = 0;
        dis[top] = help[top] = ++k;
        MYSTACK.push(top);
        check[top] = true;
       
        for(long long ok:array[top])
        {
            if(dis[ok]==-1)
            {
            	dfs(dis,help,ok,array,seet,check,ans,MYSTACK,n);
            		help[top] = min(help[top],help[ok]);
                if(help[top]!=help[ok])
                {
                     if((seet.count((ok*n)+top)==0 && seet.count((top*n)+ok)==0))
                        {
                            vector<long long> uu;
                            uu.push_back(ok);
                             uu.push_back(top);
                            ans.push_back(uu);
                            seet.insert((ok*n)+top);
                            seet.insert((top*n)+ok);
                        }
                }
			}
			 if(check[ok]==true)
			{
				help[top] = min(help[top],dis[ok]);
                //     if(help[top]!=help[ok])
                // {
                //      if((seet.count((ok*n)+top)==0 && seet.count((top*n)+ok)==0))
                //         {
                //             vector<long long> uu;
                //             uu.push_back(ok);
                //              uu.push_back(top);
                //             ans.push_back(uu);
                //             seet.insert((ok*n)+top);
                //             seet.insert((top*n)+ok);
                //         }
                // }
			}
        }
        if(dis[top]==help[top])
        {
            
        	while(top!=MYSTACK.top())
        	{
        		check[MYSTACK.top()]  = false;
        		MYSTACK.pop();
			}
			check[MYSTACK.top()]  = false;
			MYSTACK.pop();
            
		}
		return ;
    }
    vector<vector<int>> criticalConnections(long long n, vector<vector<int >>& connections) {
        bool check[n];
        long long dis[n];
        long long help[n];
        unordered_set<long long> seet;
        vector<long long> array[n];
         vector<pair<int,long long>> lol;
        for(long long i  = 0; i <connections.size();i++)
        {
            array[connections[i][0]].push_back(connections[i][1]);
            lol.push_back({connections[i][1],connections[i][0]});
        }
        for(long long i = 0 ; i<n;i++)
        {
            check[i] = false;
            dis[i] = -1;
            help[i] = -1;
        }
        connections.clear();
        stack<long long> MYSTACK;
        for(long long i  =0 ;i<n;i++)
        {
            if(dis[i]==-1)
            {
                dfs(dis,help,i,array,seet,check,connections,MYSTACK,n);
            }
        }
          for(long long i  = 0; i <lol.size();i++)
        {
            array[lol[i].first].push_back(lol[i].second);
        }
       if(connections.empty()==true)
       {
           for(long long i  = 0 ; i<n;i++)
           {
               
               long long ele = 0;
               long long one = 1;
               for(long long j:array[i])
               {
                   one = j;
                   ele++;
               }
               if(ele==1)
               {
                   if(seet.count(((n*one)+i)%1000)==0 && seet.count((n*i)+one)==0)
                   {
                   	
                       vector<int > tem;
                       tem.push_back(one);
                       tem.push_back(i);
                       connections.push_back(tem);
                       seet.insert((n*one)+i);
                        seet.insert((n*i)+one);
                   }
               }
           }
       }
            return connections;
    }
};
