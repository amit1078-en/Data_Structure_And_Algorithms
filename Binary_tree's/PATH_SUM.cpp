/*

 Path Sum II

Solution
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where each path's sum equals targetSum.

A leaf is a node with no children.

 

Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: []
Example 3:

Input: root = [1,2], targetSum = 0
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000


LINK -> https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/613/week-1-august-1st-august-7th/3838/
*/



class Solution {
public:
  vector<vector<int>> ans;
  vector<int> rr;
  bool b = true;
    void check(TreeNode* root,int target,int r)
    {
      if(root==NULL)
      {
        return ;
      }
     if(root->left==NULL && root->right==NULL)
     {
       rr.push_back(root->val);
          if(r+root->val==target  )
          {
            b= false;
            ans.push_back(rr);
          }
       rr.pop_back();
           return ;
     }
      
      b = true;
      rr.push_back(root->val);
      check(root->left,target,r+root->val);
      check(root->right,target,r+root->val);
      rr.pop_back();
    }
     
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
      ans.clear();
      b =true;
       vector<int> rr;
      check(root,targetSum,0);
      return ans;
    }
};
