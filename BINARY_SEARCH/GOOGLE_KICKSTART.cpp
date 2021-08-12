#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int j = 1;j<=t;j++)
    {
        
        int ans = 0;
        int size,score;
        cin>>size>>score;
        string temp;
        cin>>temp;
        
        for(int i = 0 ;i<size/2;i++)
        {
            if(temp[i]!=temp[size-1-i])
            {
                ans = ans+1;
            }
        }
        if(ans>=score)
        {
            score = 0;
        }
        else
        {
            score = score-ans;
        }
        cout<<"Case #"<<j<<": "<<score<<endl;
    }
}
