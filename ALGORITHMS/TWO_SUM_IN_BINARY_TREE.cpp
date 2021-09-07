/*
LINK -> https://leetcode.com/submissions/detail/542787048/
Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

 

Example 1:


Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
Example 2:


Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
Example 3:

Input: root = [2,1,3], k = 4
Output: true
Example 4:

Input: root = [2,1,3], k = 1
Output: false
Example 5:

Input: root = [2,1,3], k = 3
Output: true
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105
*/class Solution {
public:
    void help(vector<int> &ans,TreeNode* root)
    {
        if(root==NULL)
        {
            return ;
        }
        help(ans,root->left);
        ans.push_back(root->val);
        help(ans,root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        help(ans,root);
        int l = 0;
        int r  = ans.size()-1;
        while(l<r)
        {
            int t = ans[l]+ans[r];
            if(t==k)
            {
                return true;
            }
            else if(t>k)
            {
                r--;
            }
            else
            {
                l++;
            }
        }
        return false;
    }
};
