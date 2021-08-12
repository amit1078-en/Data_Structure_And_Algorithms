/*Vertical Traversal of Binary Tree 
Medium Accuracy: 32.45% Submissions: 85223 Points: 4
Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Example 1:

Input:
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9           
Output: 
4 2 1 5 6 3 8 7 9 
Explanation:


Example 2:

Input:
       1
    /    \
   2       3
 /    \      \
4      5      6
Output: 4 2 1 5 3 6
Your Task:
You don't need to read input or print anything. Your task is to complete the function verticalOrder() 
which takes the root node as input parameter and returns an array containing the vertical order traversal 
of the tree from the leftmost to the rightmost level. If 2 nodes lie in the same vertical level, they should 
be printed in the order they appear in the level order traversal of the tree.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/

//code is given below

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
          
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
         vector<int> answer;
       if(root!=nullptr)
       {
           
        vector<int> pos[50011];
        vector<int> neg[50011];
        int po = -50011;
        int ne = 50011;
        queue<pair<Node*,int>> Q;
        Q.push({root,0});
        while(!Q.empty()){
            Node* front = Q.front().first;
            int level = Q.front().second;
            po = max(po,level);
            ne = min(ne,level);
            if(front->left!=nullptr)
            {
                Q.push({front->left,level-1});
                
            }
            if(front->right!=nullptr)
            {
                Q.push({front->right,level+1});
            }
            Q.pop();
            if(level>=0)
            {
                pos[level].push_back(front->data);
            }
            else
            {
                int p = level*-1;
                neg[p].push_back(front->data);
            }
        }
         if(ne<0)
        {
            ne = ne*-1;
        }
        for(int i =ne; i>0;i--)
        {
            if(!neg[i].empty())
            {
                for(int x:neg[i])
            {
                answer.push_back(x);
            }
            }
        }
        if(po<0)
        {
            po = po*-1;
        }
        for(int i =0; i<=po;i++)
        {
           if(!pos[i].empty())
           {
                for(int x:pos[i])
            {
                answer.push_back(x);
            }
           }
        }
       }
        return answer;
    }
};



// { Driver Code Starts.
int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
        Solution obj;
    	Node* root = buildTree(s);
    	
    	vector <int> res = obj.verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}


