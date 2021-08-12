/*
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

code
*/

class Solution {
public:
    public:
    unordered_map<string,bool> str;
    bool ans = true;
    bool check(int i,int j,int k,string s1,string s2,string s3,int l1,int l2,int l3){
        
            if( k==l3)
            {
                string abc = to_string(i)+'*'+to_string(j)+'*'+to_string(k);
                str.insert({abc,true});
            }
        
            if(str.find(to_string(i)+'*'+to_string(j)+'*'+to_string(k))!=str.end()){
                 string abc = to_string(i)+'*'+to_string(j)+'*'+to_string(k);
                return str[abc];
            }
            bool track1= false;
        bool track2= false;
           if(i<s1.length())
            {
                if(s1[i]==s3[k])
                {
                    string abc = to_string(i)+'*'+to_string(j)+'*'+to_string(k);
                    track1 = check(i+1,j,k+1,s1,s2,s3,l1,l2,l3);
                    str[abc] = track1;
                }
            }
             if(j<s2.length())
            {
                if(s2[j]==s3[k])
                {
                    string abc = to_string(i)+'*'+to_string(j)+'*'+to_string(k);
                 track2 =  check(i,j+1,k+1,s1,s2,s3,l1,l2,l3);
                     str[abc] = track2;
                }
            }
        if(track1==false && track2==false){
             string abc = to_string(i)+'*'+to_string(j)+'*'+to_string(k);
                str.insert({abc,false});
        }
        return track1|track2;
    }
    bool isInterleave(string s1, string s2, string s3) {
         ans = false;
        int l1,l2,l3;
        l1 = s1.length(),l2=s2.length(),l3 = s3.length();
        if(l1+l2==l3)
        {
            if(l1==0 && l2==0 && l3==0)
            {
                ans = true;
            }
            else
            {
                string t;
                ans = check(0,0,0,s1,s2,s3,l1,l2,l3);
            }
        }
        return ans;
    }
};
