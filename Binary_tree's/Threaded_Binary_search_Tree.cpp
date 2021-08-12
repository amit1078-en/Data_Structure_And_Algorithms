#include<bits/stdc++.h>
using namespace std;

class node{
	//node class with value , and value
	public:
	int val;
	node *left;
	node *right;
	node *lth;
	node *rth;
	node()
	{
		lth = rth = NULL;
	}
	
};
node *Root = NULL;
node* ans =NULL;
//preorder traversal recursive
void preorder(node* root)
{
	if(root!=NULL)
	{
		preorder(root->left);
		cout<<root->val<<" ";
		preorder(root->right);
	}
}
//create funcion
node *create(node *root,int data)
{
	if(root==NULL)
	{
		//base case
		node *temp=new node();
		temp->val=data;
		temp->left=NULL;
		temp->right=NULL;
		return temp;  
	}
	else if(data>root->val)
		{
			root->right=create(root->right,data);
		}
	else if(data<root->val){
		root->left=create(root->left,data);
		}
	else if(data=root->val) {
		root->left=create(root->left,data);
	}	
		return root;	
}
//function to find the inorder precedecor
void inorder_pred(node* root,int data)
{
	if(root!=NULL)
	{
		inorder_pred(root->left,data);
		if(root->val<data)
		{
			ans = root;
		}
		inorder_pred(root->right,data);
	}
}
//function to find the inorder Successor
void inorder_succ(node* root,int data)
{
	if(root!=NULL)
	{
		inorder_succ(root->left,data);
		if(root->val > data && ans==NULL)
		{
			ans = root;
		}
		inorder_succ(root->right,data);
	}
}
//function to threaded the tree
void convert_to_thread(node* root,node* pw)
{
	if(root!=NULL)
	{
		convert_to_thread(root->left,pw);
		if(root->left!=NULL && root->right!=NULL)
		{
			cout<<"\n left thread of "<<root->val<<" -> NULL \n right thread of "<<root->val<<" -> NULL \n\n";
		}
		else
		{
				if(root->left==NULL)
				{
					ans =NULL; 
					inorder_pred(pw,root->val);
					root->lth = ans;
					if(ans!=NULL)
					{
					cout<<"The left thread of "<<root->val<<" is "<<ans->val<<endl;	
					}
					if(ans == NULL)
					{
						cout<<"The left thread of "<<root->val<<" is NULL \n";
					}
					if(root->right!=NULL)
					{
						cout<<"right thread of "<<root->val<<"-> NULL \n\n";
					}
				}
				if(root->right==NULL)
				{
					if(root->left!=NULL)
					{
						cout<<"left thread of "<<root->val<<" -> NULL \n";
					}
					ans =NULL; 
					inorder_succ(pw,root->val);
					root->rth = ans;
					if(ans!=NULL)
					{
							cout<<"The right thread of "<<root->val<<" is "<<ans->val<<endl<<endl;	
					}
					if(ans == NULL)
					{
						cout<<"The right thread of "<<root->val<<" is NULL \n\n";
					}		
				}
		}
		convert_to_thread(root->right,pw);
	}
}
//postorder Traversak
void postorder(node* root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->val<<" ";
	}
}
//postorder Traversak
void pre(node* root)
{
	if(root!=NULL)
	{
		cout<<root->val<<" ";
		pre(root->left);
		pre(root->right);
	}
}
//function to find the preorder precedesor
node* preNode(node* prev)
{
   if(prev->rth==NULL && prev->right==NULL && prev->left==NULL)
   {
   	return NULL;
   }
   else
   {
   		if(prev->left==NULL && prev->right!=NULL)
		{
			return prev->right;
		}
		
   		else if(prev->left!=NULL)
   		{
   			return prev->left;
		}
		else if(prev->left==NULL)
		{
			while(prev->rth!=NULL)
			{
				prev = prev->rth;
				if(prev->right!=NULL)
				{
					return prev->right;
					break; 
				}
				
			}
			
		}
   }
}
// Preorder Non recursive 
void PNR(node* root)
{
	node* ptr = root;
	while(ptr!=NULL)
	{ 
		if(ptr->left!=NULL)
		{
			cout<<ptr->val<<" ";
			ptr = ptr->left;
		}
		else
		{
			if(ptr->left==NULL)
			{
				cout<<ptr->val<<"  ";
	 		} 
			ptr = preNode(ptr);
		}
	}
	ans = NULL;
}
//inorder non  recursive
void INR(node* root)
{
	node* ptr = root;
	ans = NULL;
	while(ptr->left!=NULL)
	{
		ptr  = ptr->left;
	}
	cout<<ptr->val<<" ";
	while(ptr!=NULL)
	{
		int data = ptr->val;
		inorder_succ(root,data);
		ptr = ans;
		cout<<ans->val<<" ";
		ans = NULL;
	}
}
bool b  = false;
void find(node* root,int d)
{
	if(root!=NULL)
	{
		find(root->left,d);
		find(root->right,d);
		if(root->val==d)
		{
			b = true;
		}
	}
}
int main()
{
	int size;
	cout<<"Enter the size  ->";
	cin>>size;
	int temp;
	while(size--)
	{
		cout<<"enter value ";
		cin>>temp;
		Root = create(Root,temp);
	}
	cout<<endl;
	cout<<"thread linking of nodes are shown below"<<endl;
	convert_to_thread(Root,Root);
	cout<<endl<<endl<<"\nInorder traveral -> ";
	preorder(Root);
	cout<<endl<<endl<<"\n\nPostorder traveral -> ";
	postorder(Root);
	cout<<endl<<endl<<"\n\nPreorder traveral -> ";
	pre(Root);
	
	
	cout<<"\n\n";
	cout<<"\nPreorder_Non Recursive\n";
	PNR(Root);
	 while(1)
	 {
		 	cout<<"\n\n";
		 cout<<"\n\n Enter the value you want to find -> ";
		 int d;
		 cin>>d;
		 find(Root,d);
		 if(b == true)
		 {
		 	cout<<"Element Is Present"<<"\n";
		 }
		 else
		 {
		 	cout<<"Element Is Not Present"<<"\n";
		 }
		 b=false;
		 int l;
		 cout<<"Do you want to continue-> ";
		 cin>>l;
		 if(l==0)
		 {
		 	break;
		 }
	 }
	 
	 
	cout<<"\n\n";
	cout<<"\nInorder_Non Recursive\n";
	INR(Root);
	
	return 0;
}

