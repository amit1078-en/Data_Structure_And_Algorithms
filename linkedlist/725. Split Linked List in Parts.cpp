/*
Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return an array of the k parts.

 

Example 1:


Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].
Example 2:


Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
 

Constraints:

The number of nodes in the list is in the range [0, 1000].
0 <= Node.val <= 1000
1 <= k <= 50
*/

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = 0;
         vector<ListNode*> answer;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            size+=1;
            temp = temp->next;
        }
        if(size<=k)
        {
            ListNode* t1 = head;
           
            while(t1!=NULL)
            {
                ListNode* l = t1->next;
                t1->next = NULL;
                answer.push_back(t1);
                t1 = l;
            }
            while(k-size>0)
            {
                answer.push_back(NULL);                
                k-=1;
            }
            return answer;
        }
        if(k==1)
        {
            answer.push_back(head);
            return answer;
        }
        int tot = size/k;
        int p = size%k;
        int s = 0;
        temp=head;
        while(p>0)
        {
            int m = tot+1;
            
            int i= 1;
            ListNode* curr = temp;
            while(i<m)
            {
                temp = temp->next;
                i+=1;
            }
            ListNode* n = temp->next;
            temp->next = NULL;
            temp= n;
            answer.push_back(curr);
            p-=1;
        }
         p =k;
        k-=(size%p);
        
        while(k>0)
        {
              int m = tot;
            int i= 1;
            ListNode* curr = temp;
            while(i<m)
            {
                temp = temp->next;
                i+=1;
            }
            ListNode* n = temp->next;
            temp->next = NULL;
            temp = n;
            answer.push_back(curr);
            k--;
        }
        return answer;
    }
};


