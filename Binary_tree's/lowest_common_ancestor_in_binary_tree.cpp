/*


36. Lowest Common Ancestor of a Binary Tree
Medium

6240

211

Add to List

Share
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the tree.
Accepted

YOUR's ONE UPVOTE BRINGS SMILE TO MY FACE
algo
1.just do preorder traversal for bt
2.incase we encounter any node that is p or q we will return true'
3.incase root become null we return false
4.so we are returning pl| pr in end means that if either of them is true then only it will return true and we will store value of temp in wich both are true
*/


class Solution {
public:
    TreeNode* track;
    TreeNode* w;
    bool help(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(root==NULL)return false;
        
        if(root==p || root==q)
        {
            w = root;
            return true;
        }
        bool cl = help(root->left,p,q);
        bool cr = help(root->right,p,q);
        if(cl==true && cr==true && track==NULL)
        {
            track = root;
        }
        return cl|cr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        track = NULL;
        bool r = help(root,p,q);
        if(track==NULL)
        {
            return w;
        }
        return track;
    }
};
