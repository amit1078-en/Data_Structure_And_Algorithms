// { Driver Code Starts




// Finding Minimum element from stack in O(1) time and O(1)  space complexity
#include<bits/stdc++.h>
using namespace std;
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};


int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int q;
       cin>>q;
        _stack *a = new _stack();
       while(q--){

       int qt;
       cin>>qt;

       if(qt==1)
       {
           //push
           int att;
           cin>>att;
           a->push(att);
       }
       else if(qt==2)
       {
           //pop
           cout<<a->pop()<<" ";
       }
       else if(qt==3)
       {
           //getMin
           cout<<a->getMin()<<" ";
       }
       }
       cout<<endl;
   }

}


// } Driver Code Ends


/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

int  p;
int _stack :: getMin()
{
   if(s.empty()== true)
   {
       return -1;
   }
   else
   {
     return minEle;
   }
}

int _stack ::pop()
{
   if(s.empty()==true)
    return -1;
   else
   {
        if(minEle > s.top())
        {
            p = minEle;
            minEle = (2*minEle) - s.top();
             s.pop();
            return p;
        }
        else
        {
             p = s.top();
            s.pop();
            return p;
        }
   }
}

void _stack::push(int x)
{
    if(s.empty() == true)
    {
          s.push(x);
          minEle = x;
    }
    else
    {
        if(x < minEle)
        {
               s.push(2*x-minEle);
               minEle = x;
        }
        else
        {
             s.push(x);
        }
    }
}

