/*************************************************************
    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode 
    {
      public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() 
        {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

bool validateBST(BinaryTreeNode<int>* root,int min = INT_MIN,int max = INT_MAX) 
{
    if(root==NULL)
    {
        return 1;
    }
    if(root->data>=max || root->data<min)
    {
        return 0;
    }
    return validateBST(root->left,min,root->data)&validateBST(root->right,root->data+1,max);
}
