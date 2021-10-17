/*
Delete Node's And Return Forest

Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.

 

Example 1:


Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]
Example 2:

Input: root = [1,2,4,null,3], to_delete = [3]
Output: [[1,2,4]]
 

Constraints:

The number of nodes in the given tree is at most 1000.
Each node has a distinct value between 1 and 1000.
to_delete.length <= 1000
to_delete contains distinct values between 1 and 1000.

*/
class Solution {
public:
    TreeNode* rec(TreeNode* root,unordered_set<int> maap,vector<TreeNode*> &answer)
    {
        if(root==NULL)
        {
            return NULL;
        }
        TreeNode* left =  rec(root->left,maap,answer);
        TreeNode* right = rec(root->right,maap,answer);
        root->left= left;
        root->right=right;
        if(maap.find(root->val)!=maap.end())
       {
            if(left!=NULL)
            {
                answer.push_back(left);
            }
            if(right!=NULL)
            {
                answer.push_back(right);
            }
           return NULL;
       }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
    {
            unordered_set<int> maap;
            for(int i:to_delete)
            {
                maap.insert(i);
            }
            vector<TreeNode*> answer;
            TreeNode* y = rec(root,maap,answer);
            if(y!=NULL)
            {
                answer.push_back(y);
            }
            return answer;
    }
};
