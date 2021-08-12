// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void reorderList(struct Node* head);

/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }

        reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}
// } Driver Code Ends


/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

void reorderList(Node* head) {
    if(head!=NULL && head->next!=NULL && head->next->next!=NULL)
    {
        Node* array[10001];
        Node* temp = head;
        int r = 0;
        while(temp!=NULL)
        {
            Node* ok = temp->next;
        	temp->next=NULL;
            array[r] = temp;
            temp = ok;
            r++;
        }
        int size = r;
        int i = 0;
        r = r-1;
        bool tr = false;
        while(i<=r)
        {
        	//cout<<<array
            array[i]->next=array[r];
            array[r]->next = array[i+1];
            i++;
            r--;
        }
        	array[size/2]->next=NULL;

		
    }
}
