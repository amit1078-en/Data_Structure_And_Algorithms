/*

Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

 

Example 1:


Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]
 

Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200
*/

class Solution 
{
public:
    ListNode* partition(ListNode* head, int x) 
	{
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* Head = head;
        ListNode* prev = NULL;
        ListNode* last = NULL;
        ListNode* l1 = NULL;
        ListNode* l2 = NULL;
        while(Head!=NULL)
        {
                ListNode* t1 = new ListNode(Head->val);
            if(x>Head->val)
            {
                 if(l1==NULL)
                 {
                     prev = t1;
                     l1 = t1;
                 }
                else
                {
                    l1->next = t1;
                    l1 = t1;
                }
            }
            else
            {
                 if(l2==NULL)
                 {
                     last = t1;
                     l2 = t1;
                 }
                else
                {
                    l2->next = t1;
                    l2 = t1;
                }
            }
            Head = Head->next;
        }
       if(prev==NULL)
       {
           return last;
       }
        if(last==NULL)
        {
            return prev;
        }
        l1->next = last;
        return prev;
    }
};
