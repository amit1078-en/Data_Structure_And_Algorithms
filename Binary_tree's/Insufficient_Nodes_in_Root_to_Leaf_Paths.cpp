/*
1080. Insufficient Nodes in Root to Leaf Paths
Medium

276

395

Add to List

Share
Given the root of a binary tree, consider all root to leaf paths: paths from the root to any leaf.  (A leaf is a node with no children.)

A node is insufficient if every such root to leaf path intersecting this node has sum strictly less than limit.

Delete all insufficient nodes simultaneously, and return the root of the resulting binary tree.

 

Example 1:


Input: root = [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14], limit = 1

Output: [1,2,3,4,null,null,7,8,9,null,14]
Example 2:


Input: root = [5,4,8,11,null,17,4,7,1,null,null,5,3], limit = 22

Output: [5,4,8,11,null,17,4,7,null,null,null,5]
 

Example 3:


Input: root = [1,2,-3,-5,null,4,null], limit = -1

Output: [1,null,-3,4]
 

Note:

The given tree will have between 1 and 5000 nodes.
-10^5 <= node.val <= 10^5
-10^9 <= limit <= 10^9
 
*/

class Solution {
public:
    TreeNode* help(TreeNode* root,int limit,int sum)
    {
        if(root==NULL)return NULL;
        
        sum = sum+root->val;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = help(root->left,limit,sum);
        root->right = help(root->right,limit,sum);
        
        if(root->left==NULL && root->right==NULL)
        {
            if(sum<limit){
                return NULL;
            }
            else if(left!=NULL || right!=NULL)
            {
                return NULL;
            }
        }
        return root;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return help(root,limit,0);

    }
};
