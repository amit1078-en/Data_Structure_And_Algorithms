#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long int
ll extended_eucledean_algorithm(ll a,ll b,ll *c,ll *d)
{
    if(b==0)
    {
        *c=1;
        *d=0;
        return a;
    }
    ll c1,d1;
    ll q = extended_eucledean_algorithm(b,a%b,&c1,&d1);
    *c = d1;
    *d = c1-d1*(a/b); 
	return q; 
}
int main() {
   ll a,b;
    cin>>a>>b;
   ll c,d;
   ll res = extended_eucledean_algorithm(a,b,&c,&d);
    cout<<c<<" "<<d<<endl;
}

