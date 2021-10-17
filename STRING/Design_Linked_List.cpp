/*
Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
 

Example 1:

Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

Explanation
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3
 

Constraints:

0 <= index, val <= 1000
Please do not use the built-in LinkedList library.
At most 2000 calls will be made to get, addAtHead, addAtTail, addAtIndex and deleteAtIndex.
*/
class Node
{
  public:
    int data;
    Node* next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
class MyLinkedList {
public:
    Node* root;
    Node* last;
    int size = 0;
    /** Initialize your data structure here. */
    MyLinkedList() {
        root = last =  NULL;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) 
    {
          if(size<index)return -1;
        
        Node* temp = root;
        int k = 0;
        while(temp!=NULL)
        {
            if(k==index)
            {
                return temp->data;
            }
            temp = temp->next;
            k+=1;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) 
    {
        size+=1;
        Node* temp = new Node(val);
        if(root==NULL)
        {
            root =last = temp;
        }
        else
        {
           temp->next = root;
           root= temp;
        }
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) 
    {
        
        size+=1;
        Node* temp = new Node(val);
        if(root==NULL)
        {
            root =last = temp;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) 
    {
       
        if(size<index)
        {
            return ;
        }
        
        Node* temp = new Node(val);
       
        if(root==NULL)
        {
            size = 1;
            root = last = temp;
            return ;
        }
        
         if(index==size)
        {
            last->next = temp;
            last = temp;
        }
        else if(index==0)
        {
             temp->next = root;
            root = temp;
        }
        else
        {
            Node* curr = root;
            int k = 1;
            while(k!=index)
            {
                curr = curr->next;
                k+=1;
            }
            Node* v = curr->next;
            curr->next = temp;
            temp->next = v;
        }
       size+=1; 
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) 
    {
          
        if(size>index)
        {
            if(index==0)
            {
                root =root->next;
                if(root==NULL)
                {
                    size = 0;
                    last=NULL;
                }
                size-=1;
                return ;
            }
            Node* temp = root;
            int k = 1;
            while(k!=index)
            {
                temp = temp->next;
                k+=1;
            }
            if(temp->next->next==NULL)
            {
                last = temp;
            }
            temp->next = temp->next->next;
            size-=1;
        }
      
    }
};

