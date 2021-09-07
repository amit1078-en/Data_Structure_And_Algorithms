/*
SWAP NODES IN PAIRS


link -> https://leetcode.com/submissions/detail/544093244/


Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes 
(i.e., only nodes themselves may be changed.)

 

Example 1:


Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
Output: [1]
 

Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL )
        {
          return head;
        }
        int one = 1;
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            if(temp->next==NULL)
            {
              break;
            }
            ListNode* next = temp->next->next;
            if(prev==NULL)
            {
              head = head->next;
              ListNode* t1 = temp->next;
              t1->next = temp;
              temp->next = next;
              prev = temp;
            }
            else
            {
              ListNode* t1 = temp->next;
              t1->next = temp;
              temp->next = next;
              prev->next = t1;
              prev = temp;
            }
            temp = next;
        }
        return head;
    }
};
