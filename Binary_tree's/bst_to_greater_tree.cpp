/*
1038. Binary Search Tree to Greater Sum Tree


Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
Example 2:

Input: root = [0,null,1]
Output: [1,null,1]
Example 3:

Input: root = [1,0,2]
Output: [3,3,2]
Example 4:

Input: root = [3,2,4,1]
Output: [7,9,4,10]
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
0 <= Node.val <= 100
All the values in the tree are unique.
root is guaranteed to be a valid binary search tree.
 
*/
class Solution {
public:
    void rec(TreeNode* root,vector<int> &vc)
    {
        if(root==NULL)
        {
            return ;
        }
        vc.push_back(root->val);
        rec(root->left,vc);
        rec(root->right,vc);
    }
    void mod(TreeNode* root,unordered_map<int,int> &maap)
    {
        if(root==NULL)
        {
            return ;
        }
        root->val = maap[root->val];
        mod(root->left,maap);
        mod(root->right,maap);
    }
    TreeNode* bstToGst(TreeNode* root) 
    {
        vector<int> vc;
        unordered_map<int,int> maap;
        rec(root,vc);
        long dp =0;
        sort(vc.begin(),vc.end());
        for(int i = vc.size()-1;i>=0;i--)
        {
            dp+=vc[i];
            maap[vc[i]] = dp;
        }
        mod(root,maap);
        return root;
    }
};
