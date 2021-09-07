/*
Count the number of prime numbers less than a non-negative number, n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0
 

Constraints:

0 <= n <= 5 * 106
*/
int s = 0;
class Solution {
public:
    int array[5000001];
    bool track[5000001];
    
    Solution(){
        if(s==0)
        {
            for(int i =0 ;  i<5000001;i++)
            {
                track[i] = false;
                array[i]==0;
            }
            track[0] = track[1] = true;
            for(int i = 2 ; i*i<=5000000;i++)
            {
                if(track[i]==false){
                    for(int j = i*i;j<5000001;j+=i){
                        track[j] = true;
                        array[j]=1;
                    }
                }
            }
            for(int i =  2;i<5000001;i++)
            {
                if(array[i]==0)
                {
                    array[i] = 1;
                }
                else
                {
                    array[i] = 0;
                }
            }
            for(int i =  2;i<5000001;i++)
            {
                array[i]+=array[i-1];
            }
            s++;
        }
    }
    int countPrimes(int n) 
    {
        if(track[n]==false)
        {
         return array[n]-1;   
        }
        return array[n];
    }
};
