/*
752. Open the Lock
Medium

1825

63

Add to List

Share
You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

 

Example 1:

Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation:
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".
Example 2:

Input: deadends = ["8888"], target = "0009"
Output: 1
Explanation:
We can turn the last wheel in reverse to move from "0000" -> "0009".
Example 3:

Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
Output: -1
Explanation:
We can't reach the target without getting stuck.
Example 4:

Input: deadends = ["0000"], target = "8888"
Output: -1
 

Constraints:

1 <= deadends.length <= 500
deadends[i].length == 4
target.length == 4
target will not be in the list deadends.
target and deadends[i] consist of digits only.
*/

vector<string> solution[10001];
int flag =1;
unordered_map<string,int>  MAP;
class Solution {
public:
    Solution()
    {
        if(flag==1)
        {
            flag = 0;
            for(int i = 0 ; i<10000;i++)
            {
                string form = to_string(i);
                int req = 4-form.length();
                if(req!=0)
                {
                    string temp;
                    while(req--){
                        temp.push_back('0');
                    }
                    temp+=form;
                    form = temp;
                }
                for(int j = 0 ; j<4;j++){
                    
                    if(form[j]=='0')
                    {
                        form[j] = '1';
                        solution[i].push_back(form);
                        form[j] = '9';
                        solution[i].push_back(form);
                        form[j]='0';
                    }
                    else if(form[j]=='9')
                    {
                        form[j] = '0';
                        solution[i].push_back(form);
                        form[j] = '8';
                        solution[i].push_back(form);
                        form[j]='9';
                    }
                    else
                    {
                        char ac  =form[j];
                         char get = char(form[j]+1);
                        char get1 = char(form[j]-1);
                        form[j] = get;
                         solution[i].push_back(form);
                        form[j] = get1;
                        solution[i].push_back(form);
                        form[j] = ac;
                    }
                }
                MAP.insert({form,i});
            }
        }
    }
    int openLock(vector<string>& deadends, string target) {
           int ans = INT_MAX;
        if(target=="0000")
        {
            ans =0;
             return 0;
        }
        
      
        bool check[10000];
        bool track[10000];
        int destination = MAP[target];
        for(int i = 0 ; i<10000;i++)
        {
            check[i] = track[i] = false;
        }
        for(string i:deadends)
        {
            check[MAP[i]] = true;
        }
        
         if( check[0]==true)
            return -1;
        
        queue<pair<string,int>> Q;
        Q.push({"0000",0});
        track[0] = true;
        while(!Q.empty())
        {
            bool fin = true;
            string front = Q.front().first;
            int step = Q.front().second;
            step+=1;
                   int v = MAP[front];
               for(string j:solution[v])
               {
                   int e = MAP[j];
                   if(e==destination)
                   {
                       ans = min(step,ans);
                   }
                   else
                   {
                       fin = false;
                       if(!check[e] && !track[e]){
                           track[e] = true;
                           Q.push({j,step});
                       }
                       
                   }
               }
            Q.pop();
        }
        if(ans==INT_MAX || check[0]==true)
        ans = -1;
        
       
        
    return ans;
        
    }
};
