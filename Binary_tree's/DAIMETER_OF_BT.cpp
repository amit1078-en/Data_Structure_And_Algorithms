/*

506


person
My Profile
exit_to_app
Logout
restore
My Transactions
Problems
Courses
Get Hired
Events
Problem of the Day


 Back To Explore Page
Sort a String
Multiply two polynomials
Geek and Function |V
Front-Back Transformation - copy
Shortest Prime Path
Subtraction and two numbers
Sort The Array
Lower case to upper case
Magical String[Duplicate Problem]
C++ 2-D Arrays | Set-1
Java Collection | Set 3 (HashMap) Part-1
Akku and Binary Numbers
Earthquake and the Paint Shop
C++ Strings
Prefix match with other strings
Find the N-th character
Efficiently sorting numbers in range from 0 to n^2 - 1
Count divisors of product of array elements
Postorder Traversal (Iterative)
Square Divisors
Mean of range in array
Break Numbers[Duplicate problem]
Card Rotation
Sum of large numbers
Last index of a character in the string
Clone a stack without usinig extra space
Queries for counts of multiples in an array
Product is even or odd?
Inorder Traversal (Iterative)
Largest value in each level
Count of camel case characters
Sum of product of x and y with floor(n/x) = y
Java 1-d and 2-d Array
Sum of two numbers without using arithmetic operators
Delete alternate characters
Java Collections | Set 7 (LinkedList)
Java Basic Data Types
Kronecker Product
Swap two numbers
Flatten binary tree to linked list

Leaderboard
Showing:
Overall Ranking
 Handle	 Score
@agkumar112rt	506
@Ibrahim Nash	6420
@blackshadows	6380
@mb1973	5704
@Quandray	5245
@akhayrutdinov	5111
@saiujwal13083	5046
@sanjay05	3762
@kirtidee18	3673
@mantu_singh	3526
@marius_valentin_dragoi	3523
@sushant_a	3459
Complete Leaderboard
Problem
 Editorial
 Submissions
Doubt Support
Diameter of Binary Tree 
Easy Accuracy: 50.01% Submissions: 100k+ Points: 2
Given a Binary Tree, find diameter of it.
The diameter of a tree is the number of nodes on the longest path between two end nodes in the tree. The diagram below shows two trees each with diameter nine, the leaves that form the ends of a longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).



Example 1:

Input:
       1
     /  \
    2    3
Output: 3
Example 2:

Input:
         10
        /   \
      20    30
    /   \ 
   40   60
Output: 4
Your Task:
You need to complete the function diameter() that takes root as parameter and returns the diameter.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= Number of nodes <= 10000
1 <= Data of a node <= 1000

 

Company Tags
Topic Tags
Related Courses
Related Interview Experiences

If you are facing any issue on this page. Please let us know.



Test against custom input
  
// Utility function to create a new Tree Node


alarm Average Time: 20m
Your Time: 114m
  
*/
// { Driver Code Starts
// Initial Template for C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// A structure to represent a queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    struct Node** array;
};

// function to create a queue of given capacity.
// It initializes size of queue as 0
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;

    // This is important, see the enqueue
    queue->rear = capacity - 1;
    queue->array =
        (struct Node**)malloc(queue->capacity * sizeof(struct Node**));
    return queue;
}

// Queue is full when size becomes
// equal to the capacity
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to add an item to the queue.
void enqueue(struct Queue* queue, struct Node* item) {
    if (isFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Function to remove an item from queue.
void dequeue(struct Queue* queue) {
    if (isEmpty(queue)) return;
    struct Node* item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
}

// Function to get front of queue
struct Node* front(struct Queue* queue) {
    if (isEmpty(queue)) return NULL;
    return queue->array[queue->front];
}

// Function to get size of queue
int size(struct Queue* queue) {
    return queue->size;
}

// Utility function to create a new Tree Node
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    ;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Function to Build Tree
struct Node* buildTree(char str[]) {
    // Corner Case
    if (strlen(str) == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    char* token = strtok(str, " ");
    int cnt = 0;
    char* ip[100000];

    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL) {
        ip[cnt++] = token;
        token = strtok(NULL, " ");
    }

    // Create the root of the tree
    struct Node* root = newNode(atoi(ip[0]));

    // Push the root to the queue
    struct Queue* queue = createQueue(cnt);
    enqueue(queue, root);

    // Starting from the second element
    int i = 1;
    while (!isEmpty(queue) && i < cnt) {

        // Get and remove the front of the queue
        struct Node* currNode = front(queue);
        dequeue(queue);
        // Get the current node's value from the string
        char* currVal = ip[i];

        // If the left child is not null
        if (strcmp(currVal, "N") != 0) {

            // Create the left child for the current node
            currNode->left = newNode(atoi(currVal));

            // Push it to the queue
            enqueue(queue, currNode->left);
        }

        // For the right child
        i++;
        if (i >= cnt) break;
        currVal = ip[i];

        // If the right child is not null
        if (strcmp(currVal, "N") != 0) {

            // Create the right child for the current node
            currNode->right = newNode(atoi(currVal));

            // Push it to the queue
            enqueue(queue, currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
// User function Template for C

/*
// Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

// A structure to represent a queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    struct Node** array;
};

// function to create a queue of given capacity
struct Queue* createQueue(unsigned capacity);

// Queue is full when size becomes equal to the capacity
int isFull(struct Queue* queue);

// Queue is empty when size is 0
int isEmpty(struct Queue* queue);

// Function to add an item to the queue.
void enqueue(struct Queue* queue,struct Node* item);

// Function to remove an item from queue.
void dequeue(struct Queue* queue);

// Function to get front of queue
struct Node* front(struct Queue* queue);

// Function to get size of queue
int size(struct Queue* queue);

// Utility function to create a new Tree Node
struct Node* newNode(int val)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
*/
int ans = 0;
int postorder(struct Node* root){
    if(root==NULL)
    {
        return 0;
    }
    int l = postorder(root->left);
    int r = postorder(root->right);
    ans = max(ans,l+r+1);
    return max(l,r)+1;
}
// Function to return the diameter of a Binary Tree.
int diameter(struct Node* root) {
    ans = 0;
    postorder(root);
    return ans;
}


// { Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        char str[500000];
        scanf("%[^\n]%*c", str);
        struct Node* root = buildTree(str);
        printf("%d\n", diameter(root));
    }
    return 0;
}  // } Driver Code Ends

