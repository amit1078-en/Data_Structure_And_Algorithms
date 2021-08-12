/*
857. Minimum Cost to Hire K Workers
Hard

1247

144

Add to List

Share
There are n workers.  The i-th worker has a quality[i] and a minimum wage expectation wage[i].

Now we want to hire exactly k workers to form a paid group.  When hiring a group of k workers, we must pay them according to the following rules:

Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.
Every worker in the paid group must be paid at least their minimum wage expectation.
Return the least amount of money needed to form a paid group satisfying the above conditions.

 

Example 1:

Input: quality = [10,20,5], wage = [70,50,30], k = 2
Output: 105.00000
Explanation: We pay 70 to 0-th worker and 35 to 2-th worker.
Example 2:

Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], k = 3
Output: 30.66667
Explanation: We pay 4 to 0-th worker, 13.33333 to 2-th and 3-th workers seperately. 
 

Note:

1 <= k <= n <= 10000, where n = quality.length = wage.length
1 <= quality[i] <= 10000
1 <= wage[i] <= 10000
Answers within 10-5 of the correct answer will be considered correct.
Accepted
39.9K
Submissions
78.6K
Seen this question in a real interview before?
*/


class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>> help;
        for(int i = 0 ;i<quality.size();i++){
            help.push_back({(double) wage[i]/quality[i],quality[i]});
        }
        sort(help.begin(),help.end());
        priority_queue<double> Q;
        double sumheap = 0;
        for(int i = 0;i<k;i++){
            sumheap+=help[i].second;
            Q.push(help[i].second);
        }
        double heapsum   = sumheap*help[k-1].first;
        
        for(int i = k;i<quality.size();i++){
            double check = help[i].first;
            if(!Q.empty() &&   help[i].second<Q.top())
            {
                sumheap-=Q.top();
                Q.pop();
                Q.push(help[i].second);
                sumheap+=help[i].second;
            }
            double temp = double(check*sumheap);
            heapsum = min(heapsum,temp);
        }
        return heapsum;
    }
};

