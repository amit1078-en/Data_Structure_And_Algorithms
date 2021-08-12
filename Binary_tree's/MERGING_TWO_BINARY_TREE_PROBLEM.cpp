/*
617. Merge Two Binary Trees
Easy

4457

197

Add to List

Share
You are given two binary trees root1 and root2.

Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.

Return the merged tree.

Note: The merging process must start from the root nodes of both trees.

 

Example 1:


Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
Output: [3,4,5,5,4,null,7]
Example 2:

Input: root1 = [1], root2 = [1,2]
Output: [2,2]
 

Constraints:

The number of nodes in both trees is in the range [0, 2000].
-104 <= Node.val <= 104
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preorder(TreeNode* root1,TreeNode* root2)
    {
      
        root1->val = root1->val + root2->val;
        if(root1->left!=NULL &&root2->left!=NULL  )
        {
            preorder(root1->left,root2->left);
        }
           if( root2->right!=NULL  && root1->right!=NULL)
        {
            preorder(root1->right,root2->right);
        }
        
        if(root1->left==NULL  && root2->left!=NULL)
        {
            root1->left = root2->left;
        }
         if(root1->right==NULL  && root2->right!=NULL){
             root1->right = root2->right;
        }   
             
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL)
        {
            return root1;
        }
        else if(root1==NULL)
        {
            return root2;
        }
        else if(root2==NULL)
        {
            return root1;
        }
        preorder(root1,root2);
        return root1;
    }
};
