#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
int getsquare(int n)
{
	if(n==0)
	{
		return 0;
	}
	
	int x = n>>1;
	if(n&1)
	{
		return ((getsquare(x)<<2) + (x<<2) + 1);
	}
	else
	{
		return (getsquare(x)<<2); 
	}
}
int main() {
   
    int t;
    cin >> t;
    while (t--) 
	{
       cout<<"Enter the number whose square you want to find-> ";
       int data;
       cin>>data;
       cout<<getsquare(data)<<endl;;
       
    }
    return 0;
}
/*
int balance = getBalance(root);  
  
    // If this node becomes unbalanced,  
    // then there are 4 cases  
  
    // Left Left Case  
    if (balance > 1 &&  
        getBalance(root->left) >= 0)  
        return rightRotate(root);  
  
    // Left Right Case  
    if (balance > 1 &&  
        getBalance(root->left) < 0)  
    {  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  
  
    // Right Right Case  
    if (balance < -1 &&  
        getBalance(root->right) <= 0)  
        return leftRotate(root);  
  
    // Right Left Case  
    if (balance < -1 &&  
        getBalance(root->right) > 0)  
    {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  
  
*/
