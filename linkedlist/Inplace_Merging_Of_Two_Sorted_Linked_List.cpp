
/*
Inplace Merging of two sorted LinkedList


Merge two sorted linked lists and return it as a new list. 

The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15
The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20

*/

ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) 
{
    if(A==NULL)
    {
        return B;
    }
    if(B==NULL)
    {
        return A;
    }
    
    if(A->val >=B->val)
    {
        ListNode* start = B;
        ListNode* prev = B;
        ListNode* start2 = A;
        while(B!=NULL && start2!=NULL)
        {
            if(B->val <=start2->val)
            {
                prev = B;
                B = B->next;
            }
            else
            {
               prev->next = start2;
               ListNode* temp = start2->next;
               start2->next = B;
               prev = start2;
               start2 = temp;
            }
        }
        if(B==NULL)
        {
            prev->next = start2;
        }
        return start;
    }
    
     ListNode* start = A;
        ListNode* prev = A;
        ListNode* start2 = B;
        while(A!=NULL && start2!=NULL)
        {
            if(A->val <=start2->val)
            {
                prev = A;
                A = A->next;
            }
            else
            {
               prev->next = start2;
               ListNode* temp = start2->next;
               start2->next = A;
               prev = start2;
               start2 = temp;
            }
        }
        if(A==NULL)
        {
            prev->next = start2;
        }
    return start;
}
