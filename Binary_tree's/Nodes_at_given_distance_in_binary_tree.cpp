/*

Given a binary tree, a target node in the binary tree, and an integer value k, find all the nodes that are at distance k from the given target node. No parent pointers are available.

Example 1:

Input:      
          20
        /    \
      8       22 
    /   \
   4    12 
       /   \
      10    14
Target Node = 8
K = 2
Output: 10 14 22
Explanation: The three nodes at distance 2
from node 8 are 10, 14, 22.

Example 2:

Input:      
         20
       /    \
      7      24
    /   \
   4     3
        /  
       1    
Target Node = 7
K = 2
Output: 1 24
Your Task:  
You don't need to read input or print anything. Complete the function KDistanceNodes() which takes the root of the tree, target, and K as input parameters and returns a list of nodes at k distance from target in a sorted order.


Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(Height of tree)


Constraints:
1 = N = 103
1 = data of node = 104
1 = target = 104
1 = k = 20



*/


#include<bits/stdc++.h>
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


 // } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:
    Node* head = NULL;
    unordered_map<Node*,int> maap; 
    void sec(Node* root,int k,int h,vector<int> &ans)
    {
        if(root==NULL || root==head)
        {
            return ;
        }
        if(maap.find(root)==maap.end())
        {
            if(h==k)
            {
                ans.push_back(root->data);
            }
            sec(root->left,k,h+1,ans);
            sec(root->right,k,h+1,ans);
            return ;
        }
       
            int height = maap[root];
            if(height==k)
            {
                ans.push_back(root->data);
            }
            if(root->left!=NULL && maap.find(root->left)==maap.end())
            {
                    sec(root->left,k,height+1,ans);
            }
            else
            {
                sec(root->left,k,0,ans);
            }
            if(root->right!=NULL && maap.find(root->right)==maap.end())
            {
                     sec(root->right,k,height+1,ans);
            }
            else
            {
                 sec(root->right,k,0,ans);
            }
        }
    
    int rec(Node* root,int k)
    {
        if(root==NULL)
        {
            return INT_MAX;
        }
        if(root->data==k)
        {
            maap[root] = 0;
            head = root;
            return 0;
        }
        int h1 = rec(root->left,k);
        int h2 = rec(root->right,k);
        if(h1!=INT_MAX)
        {
            maap[root] = h1+1; 
            return h1+1;
        }
        if(h2!=INT_MAX)
        {
            maap[root] = h2+1; 
            return h2+1;
        }
        return INT_MAX;
    }
    void post(Node* root,int k,int num,vector<int> &answer)
    {
         if(root==NULL)
        {
            return ;
        }
        if(num==k)
        {
            answer.push_back(root->data);
            
        }
        post(root->left,k,num+1,answer);
        post(root->right,k,num+1,answer);
    }
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        head=NULL;
        maap.clear();
        vector<int> answer;
        rec(root,target);
        post(head,k,0,answer);
        sec(root,k,0,answer);
        sort(answer.begin(),answer.end());
        return answer;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
       
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
     return 0;
}
  // } Driver Code Ends
