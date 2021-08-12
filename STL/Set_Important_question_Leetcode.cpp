/*
1395. Count Number of Teams
Medium

1202

131

Add to List

Share
There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

 

Example 1:

Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 
Example 2:

Input: rating = [2,1,3]
Output: 0
Explanation: We can't form any team given the conditions.
Example 3:

Input: rating = [1,2,3,4]
Output: 4
 

Constraints:

n == rating.length
3 <= n <= 1000
1 <= rating[i] <= 105
All the integers in rating are unique.
Accepted
63,510
Submissions
88,078
*/
class Solution {
public:
    int numTeams(vector<int>& rating) {
     
        set<int> help;
        int size = rating.size();
        int LP[size];
        int UP[size];
        LP[size-1] = UP[size-1] =0;
         help.insert(rating[size-1]);
        for(int i = size-2;i>=0;i--)
        {
            help.insert(rating[i]);
            auto lb = lower_bound(help.begin(),help.end(),rating[i]);
            auto hb = upper_bound(help.begin(),help.end(),rating[i]);
            int ind = distance(help.begin(),lb);
          
            LP[i]=ind;
            UP[i] = help.size()-distance(help.begin(),hb);
        }
        int ans = 0;
        for(int i = 0 ; i<size-2;i++)
        {
              for(int j = i+1 ; j<size ;j++){
                   if(rating[i]>rating[j])
                     ans+=LP[j];
                   
                  else if(rating[i]<rating[j])
                    ans+=UP[j];
                   
              } 
        }
      return ans;
    }
};
