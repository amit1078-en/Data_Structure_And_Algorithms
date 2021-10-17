class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* h1 = list1;
        ListNode* firstpointer = list1;
        ListNode* secondpointer = list1;
        int index = 1;
        bool vis = true;
        while(h1!=NULL)
        {
            if(index==a && vis==true)
            {
                vis = false;
                firstpointer = h1;
                vis = false;
                index-=2;
            }
            if(index==b)
            {
                secondpointer = h1;
            }
            index+=1;
            h1 = h1->next;
        }
        ListNode* lastoflist2 = list2;
        while(lastoflist2->next!=NULL)
        {
            lastoflist2 = lastoflist2->next;
        }
        
        firstpointer->next = list2;
        lastoflist2->next = secondpointer;
        return list1;
    }
};
