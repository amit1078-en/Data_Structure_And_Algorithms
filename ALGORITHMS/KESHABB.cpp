#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class node {
	public:
    node *left;
    int data;
    int height;
    node *right;
};

class AVL
{

public:
     node * root;
    AVL(){
        root = NULL;

    }
    

    int calheight(node *p){

            if(p->left && p->right){
            if (p->left->height < p->right->height)
                return p->right->height + 1;
            else return  p->left->height + 1;
            }
            else if(p->left && p->right == NULL){
               return p->left->height + 1;
            }
            else if(p->left ==NULL && p->right){
               return p->right->height + 1;
            }
            return 0;

    }

    int bf(node *n){
            if(n->left && n->right){
                return n->left->height - n->right->height; 
            }
            else if(n->left && n->right == NULL){
                return n->left->height; 
            }
            else if(n->left== NULL && n->right ){
                return -n->right->height;
            }
    }

    node * llrotation( node *n){
        node *p;
        node *tp;
        p = n;
        tp = p->left;

        p->left = tp->right;
        tp->right = p;

        return tp; 
    }


     node * rrrotation( node *n){
         node *p;
        node *tp;
        p = n;
        tp = p->right;

        p->right = tp->left;
        tp->left = p;

        return tp; 
    }


    node * rlrotation( node *n){
         node *p;
         node *tp;
        node *tp2;
        p = n;
        tp = p->right;
        tp2 =p->right->left;

        p -> right = tp2->left;
        tp ->left = tp2->right;
        tp2 ->left = p;
        tp2->right = tp; 
        
        return tp2; 
    }

   node * lrrotation( node *n){
        node *p;
         node *tp;
         node *tp2;
        p = n;
        tp = p->left;
        tp2 =p->left->right;

        p -> left = tp2->right;
        tp ->right = tp2->left;
        tp2 ->right = p;
        tp2->left = tp; 
        
        return tp2; 
    }

     node* insert( node *r,int data){
        
        if(r==NULL){
             node *n;
            n = new  node;
            n->data = data;
            r = n;
            r->left = r->right = NULL;
            r->height = 1; 
            return r;             
        }
        else{
            if(data < r->data)
            r->left = insert(r->left,data);
            else
            r->right = insert(r->right,data);
        }

        r->height = calheight(r);

        if(bf(r)==2 && bf(r->left)==1){
            r = llrotation(r);
        }
        else if(bf(r)==-2 && bf(r->right)==-1){
            r = rrrotation(r);
        }
        else if(bf(r)==-2 && bf(r->right)==1){
            r = rlrotation(r);
        }
        else if(bf(r)==2 && bf(r->left)==-1){
            r = lrrotation(r);
        }        

        return r;

        }

    void levelorder_newline(){
        if (this->root == NULL){
            cout<<"\n"<<"Empty tree"<<"\n";
            return;            
        }
        levelorder_newline(this->root);
    }

    void levelorder_newline( node *v){
        if(v!=NULL)
        {
        	cout<<v->data<<" ";
        	levelorder_newline(v->left);
        	levelorder_newline(v->right);
		}
    }
 

    int getheight()
    {
    	return root->height;
	}
};


int main(){

    AVL b;
    int c,x;

    do{
        cout<<"\n1.Display levelorder on newline";
        cout<<"\n2.Insert";
        cout<<"\n3.Height";
        cout<<"\n4.Exit\n";
        cout<<"\n\nChoice: ";

        cin>>c;

        switch (c)
        {
        case 1:
            b.levelorder_newline();
            // to print the tree in level order
            break;
                  
                  case 2:
                  	int data;
            cout<<"\nElement you want to insert->  ";
            cin>>data;
            b.root =  b.insert(b.root,data);
            
            break;
            
        case 3:
            cout<<"\nHeight of tree is -> "<< b.getheight()<<endl;
            break;
        
        
            
        case 4:
            break;
        }

     } while(c!=0);
  
}
