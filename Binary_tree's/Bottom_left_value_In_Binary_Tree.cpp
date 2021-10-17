/*
Leftmost Value in the last row of binary tree
Given the root of a binary tree, return the leftmost value in the last row of the tree.
Example 1:
Input: root = [2,1,3]
Output: 1
Example 2
Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7
Constraints:
The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1



algorithm:
1.simple use the rec function by passing root max value  and h as the perimeter
2.use preorder here max is for height whenever we see that our height is lesser than current height then
simply push the value of that node in val variable
*/
class Solution {
public:
    void rec(TreeNode* root,int &max,int &val,int h)
    {
        if(root==NULL)
        {
            return ;
        }
        if(max<h)
        {
            val = root->val;
            max = h;
        }
        rec(root->left,max,val,h+1);
        rec(root->right,max,val,h+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        int max = INT_MIN;
        int val =0;
        rec(root,max,val,0);
        return val;
    }
};
