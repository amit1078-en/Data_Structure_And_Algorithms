#include<bits/stdc++.h>
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;
class Bnode
{
	public:
		int data;
		int height;
		Bnode* left;
		Bnode* right;
	Bnode(int d)
	{
		data = d;
		height = 0;
		left = right = NULL;
	}
};
class AVL_Trees
{
	public:
		int getHeight(Bnode* root)
		{
			if(root==NULL)
			{
				return -1;
			}
			else
			{
				return root->height;
			}
		}
		int getbalancefactor(Bnode* root)
		{
			int l = getHeight(root->left);
			int r = getHeight(root->right);
			if(l==-1)
			{
				l=0;
			}
			if(r==-1)
			{
				r=0;
			}
			return (l-r);
		}
		Bnode* leftrotation(Bnode* root)
		{
			Bnode* temp1  = root->right->left;
			Bnode* temp2 = root->right;
			temp2->left = root;
			root->right = temp1;
			root->height = max(getHeight(root->left),getHeight(root->right))+1;
			temp2->height = max(getHeight(temp2->left),getHeight(temp2->right))+1;
			return temp2;
		}
		Bnode* rightrotation(Bnode* root)
		{
			Bnode* temp1  = root->left->right;
			Bnode* temp2 = root->left;
			temp2->right = root;
			root->left = temp1;
			root->height = max(getHeight(root->left),getHeight(root->right))+1;
				temp2->height = max(getHeight(temp2->left),getHeight(temp2->right))+1;
			return temp2;
		}
		Bnode* insert(Bnode* root,int data)
		{
			if(root == NULL)
			{
				Bnode* temp = new Bnode(data);
				root =  temp;
			}
			if(root->data>data)
			{
				root->left = insert(root->left,data);
				int h = getHeight(root->left) - getHeight(root->right);
				if(h==2 || h==-2)
				{
					//left left rotation
					if(data<root->left->data)
					{
							cout<<"\nLeft left rotation of "<<root->data<<" With "<<root->left->data<<endl;
						root = rightrotation(root);				
					}
					//left right rotation
					else
					{
						cout<<"Left right rotation of "<<root->data<<" With "<<root->left->right->data<<endl;
						Bnode* temp  = root->left->right;
						Bnode* p = root->left;
						root->left->right = temp->left;
						root->left = temp;
						temp->left = p;
						
						temp->height     = max( getHeight(temp->left),getHeight(temp->right))+1;
						p->height  = max( getHeight(p->left),getHeight(p->right))+1;
						
						root = rightrotation(root);				
					}
				}
			}
			else if(root->data<data)
			{
				root->right = insert(root->right,data);
				int h = getHeight(root->left) - getHeight(root->right);
				if(h==2 || h==-2)
				{
					//right right rotation
					if(data > root->right->data)
					{
						cout<<"Right Right rotation of "<<root->data<<" With "<<root->right->data<<endl;
						root = leftrotation(root);				
					}
					//right left rotation
					else
					{
							cout<<"right rotation of "<<root->data<<" With "<<root->right->left->data<<endl;
						Bnode* temp  = root->right->left;
						Bnode* p = root->right;
						root->right->left = temp->right;
						root->right = temp;
						temp->right = p;
						
						temp->height     = max( getHeight(temp->left),getHeight(temp->right))+1;
						p->height  = max( getHeight(p->left),getHeight(p->right))+1;
						
						
						root = leftrotation(root);		
					}
				}
				
			}
			root->height  = max(getHeight(root->left),getHeight(root->right))+1;
			return root;
		}
		Bnode* findmax(Bnode* root)
		{
			if(root->right==NULL)
			{
				return root;
			}
			else
			{
				root->right = findmax(root->right);
			}
		}
		void inorder(Bnode* root)
		{
			if(root!=NULL)
			{
				inorder(root->left);
				cout<<root->data<<" ";
				inorder(root->right);
			}
		}
		Bnode* deleteNode(Bnode* root,int l)
		{
			//firstly simply perform BST Deletion Algorithm then
			if(root==NULL)
			{
				return root;
			}
			if(root->data == l)
			{
				if(root->left==NULL && root->right==NULL)
				{
					root=NULL;
				}
				else if(root->right==NULL)
				{
					root = root->left;
				}
				else if(root->left==NULL)
				{
					root = root->right;
				}
				else if(root->left!=NULL && root->right!=NULL)
				{
					Bnode* r1 = findmax(root->left);
					int r = r1->data;
					deleteNode(root,r);
					root->data = r;
				}
			}
			else if(root->data>l)
			{
				root->left = deleteNode(root->left,l);
			}
			else if(root->data<l)
			{
				root->right = deleteNode(root->right,l);
			}
			if(root==NULL)
			{
				return root;
			}
			root->height  = max(getHeight(root->left),getHeight(root->right))+1;
			//we have 4 cases here LR LL RR RL
			
			int b = getbalancefactor(root);
			// CASE 1 LL WHEN  
			if(b>1 && getbalancefactor(root->left)>=0)
			{
				return rightrotation(root);
			}
			
			// CASE 2 LR WHEN 
			if(b>1 && getbalancefactor(root->left)>0)
			{
				root->left = leftrotation(root->left);
				return rightrotation(root);
			}
			// CASE 3 RR WHEN 
			if(b<-1 && getbalancefactor(root->right)<=0)
			{
				return leftrotation(root);
			}
			// CASE 4 RL WHEN 
			if(b<-1 && getbalancefactor(root->right)<0)
			{
				root->right = rightrotation(root->right);
				return leftrotation(root);
			}
			return root;
		}
};
int  main()
{
	AVL_Trees o;
	Bnode* root = NULL;
	cout<<"AVL TREES \n";
	int l  =1;
	while(l)
	{
		cout<<"\n1.Insertion  To  AVL Tree \n2.Inorder Traversal \n3.Deletion From Avl Tree \n4.Height of Avl Tree \n5.Balance factor \n6.Quit \n\n enter choice-> ";
		int choice;
		cin>>choice;
		switch(choice)
		{
			case 1:
				int data;
				cout<<"Enter data you want to insert-> ";
				cin>>data;
				root  =  o.insert(root,data);
				break;
			
			case 2:
				if(root==NULL)
					cout<<"\nTree Is Null \n";
				
				else
					o.inorder(root);
				break;
				
			case 3:
				int l;
				cout<<"Enter the Node Value You want to delete -> ";
				cin>>l;
				root = o.deleteNode(root,l);
				break;
			case 4:
				if(root==NULL)
					cout<<"\nTree Is Null \n";
				
				else
					cout<<"\nThe Height of Avl Tree is -> "<<o.getHeight(root)<<endl;
					
				break;
				
				
			case 5:
				if(root==NULL)
					cout<<"\nTree Is Null \n";
				else
					cout<<"\nThe Height of Avl Tree is -> "<<(o.getHeight(root->left)- o.getHeight(root->right))<<endl;
				break;
				
				
				
			case 6:
				l = 0;
				break;
			default:cout<<"\nInvalid choice\n";
			
			
			break;				
		}
	}
	return 0;
}


