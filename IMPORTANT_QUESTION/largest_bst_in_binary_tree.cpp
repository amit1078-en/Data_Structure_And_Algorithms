/*
373. Maximum Sum BST in Binary Tree
Hard

578

79

Add to List

Share
Given a binary tree root, the task is to return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:



Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
Output: 20
Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.
Example 2:



Input: root = [4,3,null,1,2]
Output: 2
Explanation: Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.
Example 3:

Input: root = [-4,-2,-5]
Output: 0
Explanation: All values are negatives. Return an empty BST.
Example 4:

Input: root = [2,1,3]
Output: 6
Example 5:

Input: root = [5,4,8,3,null,6,3]
Output: 7
 

Constraints:

The given binary tree will have between 1 and 40000 nodes.
Each node's value is between [-4 * 10^4 , 4 * 10^4].
Accepted
*/
class nodee{
  public:
  long long left  = INT_MIN; 
  long long right = INT_MAX;
  long long val = 0;
  nodee(int d)
  {
    val = d;
  }
};
class Solution {
public:
    unordered_map<TreeNode*,nodee*> help;
  long long ans = 0;
    void rec(TreeNode* root)
    {
      if(root==NULL)
      {
        return ;
      }
      rec(root->left);
      rec(root->right);
      if(root->left==NULL && root->right==NULL)
      {
        ans = max(ans,(long long)root->val);
        nodee* ptr = new nodee(root->val);
        ptr->left = root->val;
        ptr->right = root->val;
        help[root] = ptr;
        return ;
      }
      else
      {
        if(root->left==NULL)
        {
          if(root->right->val>root->val && help[root->right]->left>root->val)
          {
            nodee* ptr = new nodee(root->val+help[root->right]->val);
            ans = max(ans,root->val+help[root->right]->val);
            ptr->left = root->val;
            ptr->right = help[root->right]->left;
            help[root] = ptr;
            return ;
          }
        }
        else if(root->right==NULL)
        {
            if(root->left->val<=root->val && help[root->left]->right<=root->val)
            {
              nodee* ptr = new nodee(root->val+help[root->left]->val);
              ans = max(ans,root->val+help[root->left]->val);
              ptr->left = help[root->left]->right;
              ptr->right = root->val;
              help[root] = ptr;
              return ;
            }
        }
        else
        {
          if(root->left->val<=root->val && root->right->val>root->val && help[root->left]->right<=root->val && root->val<help[root->right]->left)
          {
              nodee* ptr = new nodee(root->val+help[root->left]->val+help[root->right]->val);
              ans = max(ans,root->val+help[root->left]->val+help[root->right]->val);
              ptr->left = min((long long )root->val,help[root->left]->right);
              ptr->right = help[root->right]->right;
              help[root] = ptr;
              return ;
          }
          
        }
        nodee* ptr = new nodee(0);
           help[root] = ptr;
        return ;
      }
    }
    int maxSumBST(TreeNode* root) {
      ans = INT_MIN;
      rec(root);
      if(ans<0)
      {
        return 0;
      }
      return ans;
    }
};



