/*
Reverse Nodes in k-Group

Solution
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
Example 3:

Input: head = [1,2,3,4,5], k = 1
Output: [1,2,3,4,5]
Example 4:

Input: head = [1], k = 1
Output: [1]
 

Constraints:

The number of nodes in the list is in the range sz.
1 <= sz <= 5000
0 <= Node.val <= 1000
1 <= k <= sz
 

Follow-up: Can you solve the problem in O(1) extra memory space?
*/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = 0;
        ListNode* front = head;
        
        while(front!=NULL)front = front->next,size+=1;
        
        if(head!=NULL && size>=k && k!=1)
        {
          int o =0;
          int stop = (size/k)*k;
          stop++;
            ListNode* temp = head;
            front = head;
            int i = 0;
            ListNode* last;
            ListNode* d = NULL;
            while(front!=NULL)
            {
              
              i++;
              o++;
              if(o==stop){
                d=front;
              }
              if(i==k)
              {
                    ListNode* next = front->next;
                    if(temp==head)
                    {
                          ListNode* rec = head;
                          ListNode* prev = NULL;
                          while(rec!=NULL && rec!=next)
                          {
                              ListNode* t = rec->next;
                              rec->next = prev;
                              prev = rec;
                              rec = t;
                          }
                          last = head;
                          head = front;
                          temp = next;
                    }
                else
                {
                          ListNode* rec = temp;
                          ListNode* prev = NULL;
                          while(rec!=NULL && rec!=next)
                          {
                              ListNode* t = rec->next;
                              rec->next = prev;
                              prev = rec;
                              rec = t;
                          }
                  
                  
                  last->next = front;
                  last = temp;
                  temp = next;
                
                }
                
                front = next;
                i = 0;
              }
              else
              {
                front = front->next;
              }
            }
          last->next=d;
        }
        return head;
    }
};
