/*
SUBMISSON LINK ->https://leetcode.com/submissions/detail/543957299/


NEXT GREATER NODE IN LINKED LIST 

You are given the head of a linked list with n nodes.

For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a 
strictly larger value than it.

Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater
 node, set answer[i] = 0.

 

Example 1:


Input: head = [2,1,5]
Output: [5,5,0]
Example 2:


Input: head = [2,7,4,3,5]
Output: [7,0,5,5,0]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 104
1 <= Node.val <= 109
*/
class Solution {
public:
  void rec(ListNode* head,stack<ListNode*> &stack,vector<int> &y)
  {
    if(head->next==NULL)
    {
         y.push_back(0);
      stack.push(head);
      return ;
    }
    rec(head->next,stack,y);
    while(!stack.empty() && stack.top()->val<=head->val)
    {
      stack.pop();
    }
    if(stack.empty())
    {
      y.push_back(0);
    }
    else
    {
      y.push_back(stack.top()->val);
    }
    stack.push(head);
    
  }
    vector<int> nextLargerNodes(ListNode* head) {
       stack<ListNode*> stack;
      vector<int> y;
       rec(head,stack,y);  
      reverse(y.begin(),y.end());
        return y;
    }
};
