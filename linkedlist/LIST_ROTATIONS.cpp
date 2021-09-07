/**

ROTATE LIST


Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
        {
          return head;
        }
        int size = 1;
        ListNode* temp = head;
        while(temp->next!=NULL)
        {
          size+=1;
          temp = temp->next;
        }
      ListNode* last = temp;
       k=k%size;
      if(k==0)
      {
        return head;
      }
      temp = head;
      int i = 0;
      ListNode* prev;
      while(i<size-k)
      {
        prev = temp;
        temp = temp->next;
        i++;
      }
      prev->next = NULL;
      last->next=head;
      head = temp;
      return head;
    }
};
