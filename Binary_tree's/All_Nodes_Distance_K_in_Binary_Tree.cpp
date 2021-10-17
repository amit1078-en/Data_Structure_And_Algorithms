/**
863. All Nodes Distance K in Binary Tree


 Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
Example 2:

Input: root = [1], target = 1, k = 3
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000

 */
class Solution {
public:
    vector<int> graph[501];
    void rec(TreeNode* root,int &val,TreeNode* target)
    {
        if(root==NULL)
        {
            return ;   
        }
        if(root==target)
        {
            val = root->val;
        }
        if(root->left!=NULL)
        {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }
        if(root->right!=NULL)
        {
              graph[root->val].push_back(root->right->val);
              graph[root->right->val].push_back(root->val);
        }
        rec(root->left,val,target);
        rec(root->right,val,target);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
         for(int i = 0; i<=500;i++)
         {
             vector<int> m;
             graph[i] = m;
         }
        int val;
         rec(root,val,target);
         vector<int> answer;
        if(k==0)
        {
            answer.push_back(target->val);
            return answer;
        }
        if(graph[target->val].empty())
            {
                return answer;
            }
        int step = 0;
        
        queue<int> q;
        bool visited[501];
        memset(visited,false,sizeof(visited));
        q.push(target->val);

        while(!q.empty() && step<k)
        {
            step+=1;
            int size = q.size();
            while(size--)
            {
                int front = q.front();
                q.pop();
                visited[front] = true;
                for(int m:graph[front])
                {
                    if(!visited[m])
                    {
                        visited[m] = true;
                        if(step==k)
                        {
                            answer.push_back(m);
                           
                        }
                         q.push(m);
                    }
                }
            }
        }
        return answer;
    }
};
