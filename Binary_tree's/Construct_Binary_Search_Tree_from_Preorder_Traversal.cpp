/**

1008. Construct Binary Search Tree from Preorder Traversal


Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

 

Example 1:


Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
Example 2:

Input: preorder = [1,3]
Output: [1,null,3]
 

Constraints:

1 <= preorder.length <= 100
1 <= preorder[i] <= 108
All the values of preorder are unique.

 */
class Solution {
public:
    int ind;
    TreeNode* rec(stack<int> &s,int miin,int present,int maax,TreeNode* root)
    {
        
        if(s.empty())
        {
            return NULL;
        }
        if(!s.empty())
        {
            int top = s.top();
            TreeNode* curr = new TreeNode(top);
            if(top<present && top>miin)
            {
                s.pop();
                root->left = curr;
                rec(s,miin,top,present,curr);
            }
            if(!s.empty())
            {
                top = s.top();
                TreeNode* x = new TreeNode(top);
                if(top>present && top<maax)
                {
                    s.pop();
                    root->right = x;
                    rec(s,present,top,maax,x);
                }
            }
        }
        return NULL;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        stack<int> s;
        reverse(preorder.begin(),preorder.end());
        for(int i:preorder)
        {
            s.push(i);
        }
        TreeNode* root = new TreeNode(s.top());
        s.pop();
        rec(s,INT_MIN,root->val,INT_MAX,root);
        return root;
    }
};
