//maximum differene between Node and ancestor
/*
Given the root of a binary tree, find the maximum value V for which there exist different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.

A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.

 

Example 1:


Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
Example 2:


Input: root = [1,null,2,null,0,3]
Output: 3
 

Constraints:

The number of nodes in the tree is in the range [2, 5000].
0 <= Node.val <= 105
Accepted
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
    int maxAncestorDiff(TreeNode* root) {
        int ans = INT_MIN;
		//        in this question we will take ans as intmin

        queue<pair<TreeNode*,pair<int,int>>> Q;
        //we will take queue with first as tree pointer and we will take pair with max and min value  
        Q.push({root,{root->val,root->val}});
        while(!Q.empty())
        {
		//        	doing simple bfs
            int size = Q.size();
            while(size--)
            {
            	// we will take front data from queue
                TreeNode* front = Q.front().first;
                int  parent = Q.front().second.first;
                int mp = Q.front().second.second;
				//				then we will pop out the values

                Q.pop();
                //checking left subtree
                if(front->left!=NULL)
                {
                  // we will push the current pointer child data in queue and in max we will take parent and pointer max value
//                  and for min we will take already present min value and pointer value
                  Q.push({front->left,{max(front->val,parent),min(front->val,mp)}});
                  int a = abs(front->val-front->left->val);
                  int b = abs(front->left->val-parent);
                  int c = abs(front->left->val-mp);
                  ans = max(ans,max(a,max(b,c)));
                }
//                checking right subtree
                if(front->right!=NULL)
                {
                   Q.push({front->right,{max(front->val,parent),min(front->val,mp)}});
                   int a = abs(front->val-front->right->val);
                  int b = abs(front->right->val-parent);
                  int c = abs(front->right->val-mp);
                  ans = max(ans,max(a,max(b,c)));
                }
            }
        }
        return ans;
    }
};
