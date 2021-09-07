/*
23. Merge k Sorted Lists
Hard

8473

382

Add to List

Share
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length won't exceed 10^4.
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> answer;
        ListNode* h = NULL;
        ListNode* last  =NULL;
        for(ListNode* head:lists)
        {
          if(head!=NULL)
          {
            if(h==NULL)
            {
              h = head;
            }
            if(last!=NULL)
            {
              last->next = head;
            }
            ListNode* l1 = head;
            while(head!=NULL)
            {
              answer.push_back(head->val);
              last = head;
              head = head->next;
            }
          }
        }
        sort(answer.begin(),answer.end());
        ListNode* temp = h; 
        for(int i :answer)
        {
          temp->val = i;
          temp = temp->next;
        }
        return h;
    }
};
