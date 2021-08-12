/*
Medium

3540

156

Add to List

Share
You are given the head of a singly linked-list. The list can be represented as:

L0 ? L1 ? � ? Ln - 1 ? Ln
Reorder the list to be on the following form:

L0 ? Ln ? L1 ? Ln - 1 ? L2 ? Ln - 2 ? �
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 

Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000
Accepted
344,305
Submissions
810,905

*/



class Solution {
public:
    ListNode* h;
    bool v = false;
    ListNode* rec(ListNode* head)
    {
      if(head==NULL)
      {
        return NULL;
      }
      ListNode* j = rec(head->next);
      if(h!=head && h->next!=head && !v)
      {
        ListNode* n = h->next;
        h->next = head;
        head->next = n;
        h = n;
      }
      else
      {
        if(v==false)
        {
          head->next = NULL;
        }
        v = true;
        
      }
        return NULL;
    }
    void reorderList(ListNode* head) {
        h = head;
        v = false;
        rec(head);
    }
};
