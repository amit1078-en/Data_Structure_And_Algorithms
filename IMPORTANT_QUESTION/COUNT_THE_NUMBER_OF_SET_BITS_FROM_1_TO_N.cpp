/*
Count the number of set bits from 0 to n in O(N) TIME
Count the number of set bits in integers form o to n in O(N) time only
*/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        if(n==0)
        {
          return ans;
        }
        ans.push_back(1);
        if(n==1)
        {
          return ans;
        }
        for(int i  = 2;i<=n;i++)
        {
          int a = 0;
          if(i&1)
          {
            ans.push_back(ans[i/2]+1);
          }
          else
          {
            ans.push_back(ans[i/2]);
          }
      }
      return ans;
    }
};
