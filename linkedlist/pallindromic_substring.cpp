/*

Q1
+
Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:

Expected solution is linear in time and constant in space.
For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.


*/
int Solution::lPalin(ListNode* A) {
    int size = 0;
    ListNode* temp = A;
    while(temp!=NULL)
    {
        size++;
        temp = temp->next;
    }
    if(size==0)return 0;
    if(size==1)
    {
        return 1;
    }
    if(size==2)
    {
        if(A->val==A->next->val)return 1;
        
        return 0;
    }
    if(size==3)
    {
        if(A->val==A->next->next->val)return 1;
        
        return 0;
    }
    int h = size/2;
    int i = 0;
    ListNode* track = A;
    while(i<h)
    {
        track = track->next;
        i+=1;
    }
    ListNode* prev = NULL;
    while(track!=NULL)
    {
        ListNode* curr = track->next;
        track->next = prev;
        prev = track;
        track = curr;
    }
    i = 0;
    
    while(i<h)
    {
        if(A->val!=prev->val)return 0;
        
        i++;
        A = A->next;
        prev = prev->next;
    }
    return 1;
}


