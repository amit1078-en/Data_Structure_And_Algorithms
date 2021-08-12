int ans  = 0;
unordered_map<int,int> height;
vector<int> graph[40001];
int rec(int root,int p)
{
    bool b  = true;
    vector<int> t;
    int maxx = INT_MIN;
    for(int i  :graph[root])
    {
        if(i==p)
        {
            continue;
        }
         b = false;
        int l =rec(i,root);
        height[i] = l; 
        t.push_back(l);
    }
    if(b)
    {
        return 1;
    }
    int l = 0;
    maxx = t[l];
    for(int i = 0 ; i<t.size();i++)
    {
        if(t[i]>t[l])
        {
            l = i;
            maxx = max(maxx,t[i]);
        }
    }
    return maxx+1;
}
int Solution::solve(vector<int> &A) {
    int rot =  0;
    height.clear();
    for(int i = 0 ; i<A.size();i++)
    {
        if(A[i]==-1) 
        {
            rot = i;
        }
        else
        {
            graph[i].push_back(A[i]);
            graph[A[i]].push_back(i);
        }
    }
    ans = 0;
    height[rot] = rec(rot,-1);
     ans = max(ans,height[rot]-1);
     int temp;
    while(1)
    {
        temp = rot;
        int k = 0;
        height[k];
        bool ch  = true;
        int vv = graph[temp][0];
        for(int k:graph[temp])
        {
            if(k==rot)
            {
                continue;
            }
            if(k!=rot)
            {
                if(height[vv]<=height[k])
                {
                    vv = k;
                }
            }
            ch = false;
        }
        if(ch)
        {
            break;
        }
        ans = max(ans,height[vv]-1);
         for(int k:graph[temp])
        {
            
            if(k!=rot && k!=vv)
            {
                ans = max(ans,height[vv]+height[k]);
            }
            
        }
        rot = vv;
    }
    return ans;
}

