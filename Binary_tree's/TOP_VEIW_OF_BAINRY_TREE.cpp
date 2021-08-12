/*
Given below is a binary tree. 
The task is to print the top view of binary tree. 
Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Print from leftmost node to rightmost node.

Example 1:

Input:
      1
   /    \
  2      3
Output: 2 1 3
Example 2:

Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100
Your Task:
Since this is a function problem. You don't have to take input. Just complete the function printTopView() that takes root node as parameter and prints the top view. Print endline after end of printing the top view.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 105
1 <= Node Data <= 105
 

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.*/

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

vector<int> topView(struct Node *root);


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n;
        i=n;

        Node* root=NULL;
        queue <Node*> q;
        while(i>0)
        {
            int a,b;
            char c;
            cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();

            if(c == 'L'){
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R'){
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
//        inorder(root);
//        cout<<endl;
        vector<int> res = topView(root);
        
        for(int i=0; i<res.size(); i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}




// } Driver Code Ends


//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree
int po = 0;
int Preorder(Node* root,map<int,int> &arr)
{
    
    if(root!=NULL)
    {
        if(arr.count(po)==0)
        {
            arr.insert({po,root->data});
        }
        if(root->left!=NULL)
        {
            po--;
        }
        Preorder(root->left,arr);
            po++;
        Preorder(root->right,arr);
       // return po--;
    }
}
vector<int> topView(struct Node *root)
{
    //ALGORITHM IS STORE LEFT AND RIGHT VIEW IN VECTOR 
    // THEN TAKE ANOTHER VECTOR WHICH WILL PRINT TAKE INPUT FROM LEFT SUBTREE IN REVERSE ORDER AND IN RIGHT SUBTREE ALSO IN REVERSE ORDR EXCEPTION IS ROOT NODE
    vector<int> ans(0);
    map<int,int> arr;
    queue<pair<Node*,int>> final;
    final.push({root,0});
    while(final.empty()==false)
    {
           int h  = final.front().second;
           Node* tem = final.front().first;
           
           if(arr.count(h)==0)
           {
               arr.insert({h,tem->data});
           }
           if(tem->left!=NULL)
           {
               final.push({tem->left,h-1});
           }
           if(tem->right!=NULL)
           {
               final.push({tem->right,h+1});
           }
           final.pop();
    }
    for(auto i = arr.begin() ;i!=arr.end() ;i++)
    {
        cout<<i->second<<" ";
    }
    return ans;
}



