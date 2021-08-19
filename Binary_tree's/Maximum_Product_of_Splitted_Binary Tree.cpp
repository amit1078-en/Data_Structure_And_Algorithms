/*
Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is
 maximized.

Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.

Note that you need to maximize the answer before taking the mod and not after taking it.

 

Example 1:


Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)
Example 2:


Input: root = [1,null,2,3,4,null,null,5,6]
Output: 90
Explanation: Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)
Example 3:

Input: root = [2,3,9,10,7,8,6,5,4,11,1]
Output: 1025
Example 4:

Input: root = [1,1]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 5 * 104].
1 <= Node.val <= 104




https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/615/week-3-august-15th-august-21st/3903/

*/
class Solution {
public:
    unordered_map<TreeNode*,pair<long long ,long long >> help;
    long long ans = INT_MIN;
    long long sum = 0;
    int mod = 1e9+7;
    long long check(TreeNode* root)
    {
      if(root==NULL)
      {
        return 0;
      }
      sum+=root->val;
      // sum%=mod;
      long long l = check(root->left);
      long long r = check(root->right);
      help[root] = {l,r};
      return (l+r+root->val);
    }
    void pre(TreeNode* root)
    {
      if(root==NULL)
      {
        return ;
      }
      pre(root->left);
      pre(root->right);
      long long left  = help[root].first;
      long long right = help[root].second;
      ans = max(ans,max(((sum-left)*left),((sum-right)*right)));
      
    }
    int maxProduct(TreeNode* root) {
        sum = 0;
        help.clear();
        ans = INT_MIN;
        check(root);
        pre(root);
        return ans%mod;
    }
};
