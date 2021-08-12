#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    int ans = -1;
    int c1 = 0;
    int c2 = 0;
    Node* temp = head1;
    while(temp!=NULL)
    {
        c1++;
        temp = temp->next;
    }
     temp = head2;
     while(temp!=NULL)
     {
         c2++;
         temp = temp->next;
     }
     if(c1>=c2)
     {
         int d = c1-c2;
          temp = head1;
          int i  =0;
          while(i<d)
          {
              temp = temp->next;
              i++;
          }
          
          Node* temp2  =head2;
          while(temp!=NULL && temp2!=NULL)
          {
              if(temp2==temp)
              {
                  ans = temp->data;
                  break;
              }
              temp = temp->next;
              temp2 = temp2->next;
          }
     }
     else
     {
          int d = c2-c1;
          temp = head2;
          int i  =0;
          while(i<d)
          {
              temp = temp->next;
              i++;
          }
          
          Node* temp2  =head1;
          while(temp!=NULL && temp2!=NULL)
          {
              if(temp2==temp)
              {
                  ans = temp->data;
                  break;
              }
              temp = temp->next;
              temp2 = temp2->next;
          }
     }
    return ans;
}
