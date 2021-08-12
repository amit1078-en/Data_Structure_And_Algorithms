/*

Find All Four Sum Numbers 
Medium Accuracy: 41.1% Submissions: 14144 Points: 4
Given an array of integers and another number. Find all the unique quadruple from the given array that sums up to the given number.

Example 1:

Input:
N = 5, K = 3
A[] = {0,0,2,1,1}
Output: 0 0 1 2 $
Explanation: Sum of 0, 0, 1, 2 is equal
to K.
Example 2:

Input:
N = 7, K = 23
A[] = {10,2,3,4,5,7,8}
Output: 2 3 8 10 $2 4 7 10 $3 5 7 8 $
Explanation: Sum of 2, 3, 8, 10 = 23,
sum of 2, 4, 7, 10 = 23 and sum of 3,
5, 7, 8 = 23.
Your Task:
You don't need to read input or print anything. Your task is to complete the function fourSum() which takes the array arr[] and the integer k as its input and returns an array containing all the quadruples in a lexicographical manner. Also note that all the quadruples should be internally sorted, ie for any quadruple [q1, q2, q3, q4] the following should follow: q1 <= q2 <= q3 <= q4.  (In the output each quadruple is separate by $. The printing is done by the driver's code)

Expected Time Complexity: O(N3).
Expected Auxiliary Space: O(N2).

Constraints:
1 <= N <= 100
-1000 <= K <= 1000
-100 <= A[] <= 100


*/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > fourSum(vector<int> &a, int k);

// Position this line where user code will be pasted.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<int> > ans = fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}// } Driver Code Ends


// User function template for C++

// arr[] : int input array of integers
// k : the quadruple sum required
vector<vector<int> > fourSum(vector<int> &arr, int k) {
    vector<vector<int>> answer;
    if(arr.size()>=4)
    {
        sort(arr.begin(),arr.end());
        int i = 0 ;
        while(i+1<arr.size())
        {
            int j = i+1;
            while(j+1<arr.size())
            {
                int sum = k-arr[i]-arr[j];
                int l = j+1;
                int r = arr.size()-1;
                while(l<r)
                {
                    int sumtemp = arr[l]+arr[r];
                    if(sumtemp<sum)
                    {
                        l++;
                    }
                    else if(sumtemp>sum)
                    {
                        r--;
                    }
                    else
                    {
                        vector<int> temp;
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[l]);
                        temp.push_back(arr[r]);
                        answer.push_back(temp);
                        
                        
                        while(l<r && temp[2]==arr[l])l++;
                        
                        while(l<r && temp[3]==arr[r]) r--;
                    }
                }
                
            int p = arr[j];
            while(j+1<arr.size() && p==arr[j]) j++;
            }
            int p = arr[i];
            while(i+1<arr.size() && p==arr[i]) i++;
        }
    }
    return answer;
}
