#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
// Class for Binarynode for Binary search tree creation
class Binarynode
{   public :
    int val;
    Binarynode *left;
    Binarynode *right;
    Binarynode(int data)
    {
    	val = data;
    	left = right = NULL;
	}
};
//global varaibls
int minn;
int maxx;
//snode class is used for implementation of queue and stack withoout using STL
class snode
{
	public:
		Binarynode* val;
		snode* next;
};
//implementation of stack using Top pointer and singly linked list
class stk
{
	private:	
		snode* top;
	public:
	stk()
	{
		top=NULL;
	}
	//push operation for pushing into stack
	void push(Binarynode* node)
	{
		snode* newnode = new snode();
		newnode->next = top;
		newnode->val = node;
		top = newnode;
	}
	//pop operation for poping from stack
	void pop()
	{
		if(top->next!=NULL)
		{
			top = top->next;
		}
		else
	    	{top =NULL;}	
	}
	//top operation for getting top value of stack
	Binarynode* TOP()
	{
		if(top!=NULL)
		{
			return top->val;
		}
		else
		{
			return NULL;
		}
	}
	// isempty function if to check if tree is empty or not
	bool isempty()
	{
		if(top!=NULL)
		return false;
		else
		return true;
	}
};
//implementation of queue using left and right pointer and singly linked list
class que
{
	private:
		snode* left;
		snode* right;
	public:
		que()
		{
			left = right = NULL;
		}
		//push operation for pushing values in queue
		void push(Binarynode* temp)
		{
			snode* newnode = new snode();
				newnode->val = temp;
			if(left == NULL)
				left = right = newnode;
			else
			{
				snode* p=left;
				while(p->next!=NULL)
				{
					p=p->next;
				}
				p->next=newnode;
			}
		}
		//front opertion for getting left element in queue
	Binarynode* front()
	{
		if(left!=NULL)
		{
			return left->val;
		}
		else
		{
			return NULL;
		}
	}
	void pop()
	{
		if(left!=NULL)
		{
			snode* l = left;
			left = left->next;
			delete(l);
		}
	}
	bool empty()
	{
		if(left==NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}	
};
bool DS = false;
// binary tree class for implementing all functions taught in BST
class binarytree
{
public:
	//create function for creating bst 
	Binarynode* Create(Binarynode* root,int data)
	{
		if(root == NULL)
		{
			Binarynode* newnode = new Binarynode(data);
			return newnode;
		}
		else if(data > root->val)
		{
			root->right = Create(root->right,data);
		}
		else
		{
			root->left = Create(root->left,data);
		}
		return root;
	}
	//preorder traversal 
	void preorder(Binarynode* show)
	{
		if(show==NULL)
		{
			return ;
		}
		cout<<show->val<<" -> ";
		preorder(show->left);
		preorder(show->right);
	}
	//inorder traversal
	void Inordered(Binarynode* show)
	{
		if(show!=NULL)
		{
		Inordered(show->left);
		cout<<show->val<<" -> ";
		Inordered(show->right);	
		}
	}
	//postorder traversal
	void Postordered(Binarynode* Root)
	{
		if(Root!=NULL)
		{
			Postordered(Root->left);
			Postordered(Root->right);	
			cout<<Root->val<<" -> ";
		}
	}
	//minimum function for getting minimum value in bst
	void minimum(Binarynode* Root)
	{
		if(Root->left ==NULL)
		{
			minn=Root->val;
			return ;
		}
		minimum(Root->left);	
	}
	//maximum function for getting maximum value in bst
	void maximum(Binarynode* Root)
	{
		if(Root->right==NULL)
		{
			maxx=Root->val;
			return ;
		}
		maximum(Root->right);	
	}
	//search function for seaeching value in bst
	int  search(Binarynode* Root,int data)
	{
		if(Root!=NULL)
		{
					if(Root->val==data)
					{
						DS=true;
							return data;
					}
					else if(data <= Root->val)
					{
						search(Root->left,data);
					}
					else if(data > Root->val)
					{
						search(Root->right,data);
					}
		}
	}
	//maximum function for getting maximum value in bst
	int maxheight(Binarynode* Root)
	{
		if(Root == NULL)
		{
			return -1;
		}
		int leftdept = maxheight(Root->left);
		int rightdept  = maxheight(Root->right);
		
		return max(leftdept,rightdept)+1;
	}
	//Levelorder traversal
	void LevelorderTraversal(Binarynode* Root)
	{
		if(Root == NULL)
		{
			cout<<"\nEmpty Binary Search Tree \n";
		}
		Binarynode* curent = Root;
		que arr;
		arr.push(Root);
		while(arr.empty()==false)
		{
			curent = arr.front();
			if(curent->left!=NULL)
			{
				arr.push(curent->left);
			}
			if(curent->right!=NULL)
			{
				arr.push(curent->right);	
			}
			cout<<curent->val<<" -> ";
			arr.pop();	
		}	
		cout<<"NULL\n";
	}
	//delete function using recursion
	Binarynode* del(Binarynode* root,int data)
	{
		if(data < root->val)
		{
			root->left = del(root->left,data);
		}
		else if(data > root->val)
		{
		    root->right = del(root->right,data);
		}
		else
		{
			if(root->left==NULL && root->right==NULL)
			{
				Binarynode* cur = root;
				root = NULL;
				delete cur;	
			}
			else if(root->left == NULL)
			{
				Binarynode* cur = root;
				root = root->right;
				delete cur;	
			}
			else if(root->right == NULL)
			{
					Binarynode* cur = root;
					root = root->left;
					delete cur;	
			}
			else if(root->left!=NULL && root->right!=NULL)
			{
				Binarynode* cur = root;
				maximum(root);
				root->val = maxx;
				del(root->right,maxx);			
			}
			return root;	
		}
	}
	//maxnode function for getting maximum element in bst
	int maxnodes(Binarynode* Root)
	{
		if(Root == NULL)
		{
			return 0;
		}
		int ans=0;
		if(Root !=NULL)
		{
			ans++;
		}
		ans+=(maxnodes(Root->left)+maxnodes(Root->right));
		return ans;	
	}
	//inorder traversal using stack
	void  INorder(Binarynode* Root)
	{
		stk obj;
		Binarynode* track = Root;
		while(obj.isempty()==false  || track!=NULL)
		{
			while(track!=NULL)
			{
				obj.push(track);
				track = track->left;
			}
			track = obj.TOP();
			obj.pop();
			cout<<track->val<<" ";
			track = track->right;
		}
		cout<<endl;
	}
	//preorder traveral using stack
	void  PREorder(Binarynode* Root)
	{
		stk obj;
		Binarynode* track = Root;
		while(obj.isempty()==false  || track!=NULL)
		{
			while(track!=NULL)
			{
				cout<<track->val<<" ";
				obj.push(track);
				track = track->left;
			}
			track = obj.TOP();
			obj.pop();
			track = track->right;
		}
		cout<<endl;
	}
	//fundmax function for getting maximum value 
		Binarynode* findmax(Binarynode* head)
	{
		if(head->right==NULL)
		{
			return head;
		}
		findmax(head->right);
	}
	//delete function using iteration
	void  deletenode(Binarynode* root,int data)
	{
		Binarynode* current = root;
		Binarynode* past = NULL;
		while(1)
		{
			if(current == NULL)
			{
				break;
				
			}
			if(current->val == data)
			{
				if(current->left ==NULL && current->right == NULL)
				{
					if(past->left==current)
						past->left = NULL;
					else	
						past->right=NULL;
					delete(current);
				}
				else if(current->left==NULL)
				{
					if(past->left==current)
						past->left = current->right;
					else	
						past->right=current->right;
					delete(current);
				}
				else if(current->right==NULL)
				{
						if(past->left==current)
						past->left = current->left;
					else	
						past->right=current->left;
					delete(current);
				}
				else if(current->right!=NULL && current->left!=NULL)
				{
					Binarynode* sub = findmax(current->left);
					int data = sub->val;
					deletenode(current,data);
					current->val = data;
				}
				break;
			}
			if(current->val >data)
				past = current;
				current = current->left;
		 if(current->val<data)
			{
					past = current;
				current = current->right;
			}
		}
	}
	// postorder function using two stack method
	void nonrecursivepostorder(Binarynode* root)
	{
		stk o1,o2;
		Binarynode* curr;
		o1.push(root);
		while(o1.isempty() == false)
		{
			curr=o1.TOP();
			o2.push(o1.TOP());
			o1.pop();
			if(curr->left!=NULL)
				o1.push(curr->left);
			if(curr->right!=NULL)
			{
				o1.push(curr->right);
			}	
		}
		while(o2.isempty()==false)
		{
			curr=o2.TOP();
			cout<<curr->val<<" ";
			o2.pop();
		}
	}
};
int main()
{
	binarytree object;
    int ch,a=1,n;
    class Binarynode* Root;
    Root=NULL;
    while(a!=0)
   {
	    cout<<"\n 1.Create Binary Tree \n 2.PreOrdered Traversal \n3.Inordered Traversal \n4.Postorder Traversal \n5.Minimum Element in BST \n6.Maximum Element in BST \n7.Delte Node \n8.Insert Node \n9.Search A Particular Node \n10.Maximum Heigth Of Tree \n11.Total Number Of Nodes In Tree \n12.Levelorder Traversal(BFS) \n13.Inorder Traversal without Recursion \n14.Preorder Traversal without recursion \n15.Postorder Traversal without Recursion \n16.Iterative Delete \n17.EXIT\nchoice -> ";
	    cin>>ch;
	    switch(ch)
	    {
	    case 1:
	    	if(Root==NULL)
	    	{
	    			int size;
		    		cout<<"Enter The Size OF Binary Tree -> ";
		    		cin>>size;
		    		int i=1;
		    		int data;
		    		while(size--)
		    		{
		    			cout<<"Enter The "<<i<<" th Value in BST -> ";
						cin>>data;
						Root = 	object.Create(Root,data);
						i++;
					}
			}
	        else
			{
				cout<<"Cant Insert Value As Root Is Already Filled";
			}   
	          break;
	    case 2:
	    	cout<<endl;
	   		   object.preorder(Root);
	   		   cout<<"NULL"<<endl;
	           break;
		case 3:
			cout<<endl;
	   	
			object.Inordered(Root);
			   cout<<"NULL"<<endl;
			break;
		case 4:
			cout<<endl;
			object.Postordered(Root);
			   cout<<"NULL"<<endl;
			break;
		case 5:
			if(Root != NULL)	
			{
					object.minimum(Root);
					cout<<"The Minimum Element In binary Tree is > "<<minn<<endl;
			}
			else
			{
				cout<<"\nRoot IS NULL\n";
			}
			break;
		case 6:
			if(Root != NULL)
			{
				object.maximum(Root);
				cout<<"The Minimum Element In binary Tree is > "<<maxx<<endl;
			}
			else
			{
				cout<<"\nRoot IS NULL\n";
			}
			break;
		case 7:
			if(Root != NULL)
			{
				int d;
				cout<<"\nTell The Number You Want To Delete In BinarySearchTree -> ";	
				cin>>d;
				int data = object.search(Root,d);
				if(DS == true)
				{
					object.del(Root,d);
					cout<<"\nData Deleted Successfully\n";
				}
				else
				{
					cout<<"\nNo Data Is Not Present "<<endl;
				}
				DS=false;
			}
			else
			{
				cout<<"\nRoot Is Null \n";
			}
			break;
		case 8:
		    		int data;
		    		cout<<"Enter The Value in BST -> ";
					cin>>data;
					Root = 	object.Create(Root,data);
			break;
		case 9:
			if(Root == NULL)
			{
				cout<<"BST is empty\n";
			}
			else
			{
				int d;
				cout<<"Enter The Data You want to search -> ";
				cin>>d;
				int data = object.search(Root,d);
				if(DS==false)
				{
					cout<<"No "<<d<<" is not present in binary search tree";
				}
				else
				{
					cout<<"\nYes "<<data<<" Is  present in binary tree\n";
				}
					DS=false;
			}
			break;
		case 10:
			if(Root!=NULL)
			{
				cout<<"The maximum height of binary search tree is -> "<< object.maxheight(Root)<<endl;
			}
			else
			{
				cout<<"\nRoot Is Null Hence zero nodes  \n";
			}
			break;
		case 11:
			if(Root!=NULL)
			{
				 int maxnodes = object.maxnodes(Root);
				 cout<<"The Maximum number of nodes in Binary Search Tree is "<<maxnodes<<endl;
			}
			else
			{
				cout<<"\nRoot Is Null Hence zero nodes  \n";
			}
			break;
		case 12:
			object.LevelorderTraversal(Root);
			break;
		case 13:
			object.INorder(Root);
			break;
	    case 14:
	    	object.PREorder(Root);
	    	break;
	    case 15:
	  			cout<<endl;
			object.nonrecursivepostorder(Root);
			   cout<<"NULL"<<endl;
	    	break;
	    case 16:
	    		if(Root != NULL)
			{
				int d;
				cout<<"\nTell The Number You Want To Delete In BinarySearchTree -> ";	
				cin>>d;
				int data = object.search(Root,d);
				if(DS == true)
				{
					object.deletenode(Root,d);
					cout<<"\nData Deleted Successfully\n";
				}
				else
				{
					cout<<"\nNo Data Is Not Present "<<endl;
				}
				DS=false;
			}
			else
			{
				cout<<"\nRoot Is Null \n";
			}
	    	break;
	    case 17:
	    	a=1;
	    	break;
	    default:
	    	cout<<"Invalid choice\n";
	   }
    }
    return 0;
}

