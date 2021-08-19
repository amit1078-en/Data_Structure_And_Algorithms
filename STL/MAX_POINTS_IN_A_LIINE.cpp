/*
count of points in a line


https://leetcode.com/submissions/detail/539879124/



Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that 
lie on the same straight line.

 

Example 1:


Input: points = [[1,1],[2,2],[3,3]]
Output: 3
Example 2:


Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
 

Constraints:

1 <= points.length <= 300
points[i].length == 2
-104 <= xi, yi <= 104
All the points are unique.


*/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;

        int len = points.size();
      
        for(int i =  0 ; i<len;i++)
        {
          unordered_map<string,int> help;
          int x = points[i][0];
          int y = points[i][1];
          int vertical = 0;
          int horizontal = 0;
          for(int j = i+1;j<len;j++)
          {
            
            int x1 = points[j][0];
            int y1 = points[j][1];
            
            if(x1==x)
            {
              vertical+=1;
              continue;
            }
            if(y1==y)
            {
              horizontal+=1;
              continue;
            }
            
            int xdif = x1-x;
            int ydif = y1-y;
            
            
            
            int gccd = __gcd(xdif,ydif);
            
            xdif/=gccd;
            ydif/=gccd;
            
            help[to_string(xdif)+to_string(ydif)]+=1;
            
          }
          for(auto it = help.begin();it!=help.end();it++)
          {
            ans = max(it->second+1,ans);
          }
          ans = max(ans,vertical+1);
          ans = max(ans,horizontal+1);
        }
        return ans;
    }
};
