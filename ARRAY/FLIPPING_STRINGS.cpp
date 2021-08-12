/*
Problem you were asked in interview on Saturday, July 24th, at 05:35 PM
Flipping String
Problem Description

You are given an numeric string A which only contains 0's and 1's. You have to find a range, such that if we flip all the elements within the range, we will get largest substring of contiguous 1's.

Return the length of largest substring of contiguous 1's after flipping exactly one substring.

NOTE:

Given string always contains atleast one zero.


Problem Constraints
1 <= |A| <= 105



Input Format
First and only argument is an string A.



Output Format
Return an integer denoting the length of largest substring of contiguous 1's after flipping exactly one substring.



Example Input
Input 1:

 A = "000"
Input 2:

 A = "10010"


Example Output
Output 1:

 3
Output 2:

 4


Example Explanation
Explanation 1:

 Flip the substring [0:2] then A = "111" so answer will be 3
Explanation 2:

 Flip the substring [1:2] then A = "11110" so answer will be 4
*/
int Solution::solve(string A) {
    
    vector<pair<int,int>> temp;
    int len = A.length();
    if(len==1)
    {
        if(A[0]=='0')return 1;
        
        return 0;
    }
    for(int i = 0;  i<len;i++)
    {
        if(A[i]=='1')
        {
            int k  = i;
            while(k<len && A[k]=='1')
            {
                k++;
            }
            
            temp.push_back({k-i,1});
            i = k-1;
            if(k==len)
            {
                break;
            }
        }
        else
        {
            int k = i;
             while(k<len && A[k]=='0')
            {
                k++;
            }
            temp.push_back({k-i,0});
            i = k-1;
            
            if(k==len)
            {
                break;
            }
        }
    }
    // R V college of Engineering
    int ans = 0;
    
    if(temp.size()==0)
    {
        if(temp[0].second==1)
        {
            return A.length()-1;
        }
        return A.length();
    }
    for(int i = 0; i<temp.size();i++)
    {
        int count = temp[i].first;
        int type = temp[i].second;
        
        if(type==0)
        {
            int prev = 0;
            int next = 0;
            if(i-1>=0)
            {
                prev+=temp[i-1].first;
            }
            if(i+1<temp.size())
            {
                next+=temp[i+1].first;
            }
            ans = max(ans,prev+next+count);
        }
    }
    // 000000001111111110000000
    return ans;
}

/*
Runtime Error. Your submission stopped because of a runtime error. ex: division by zero, array index out of bounds, uncaught exception You can try testing your code with custom input and try putting debug statements in your code.
Your submission encountered runtime error for the following input:
A : "1100100000111111101010010010011010101110110110111010011111100100000000010100011011000000100101100011111000101011000111100010111010001000111111111110100000100101010101110010000101001011000011010111011010110110010001101111110100000001101100000101011001000100001110001001111001100011101111010100110010110100110110100111101111011110010010010101111100011010001000111010010110001101000011010110000001101101101001001101111010111011110000001010001110011000101100001001100010010001010110010011101110100010111100000011111000010101010011100110101011100010101010001100010111110010101111111001100000110111111010100111111000110011101001010010111100110001010110001001110010110110100011010111100110111110101111100101001010001101110101100011100001111001001011100010111010100011000101111101110110111111000010000011000101101011001110010011111001001100000011010011100100000001110111100000110000101010001110000001101011011001000111010111110011010010100111111100101111010000100001111100101001101011000011011111010100110001"
The expected output for this testcase is:
15

*/

// Problem Constraints
// 1 <= |A| <= 105



// Input Format
// First and only argument is an string A.



// Output Format
// Return an integer denoting the length of largest substring of contiguous 1's after flipping exactly one substring.



// Example Input
// Input 1:

//  A = "000"
// Input 2:

//  A = "10010"


// Example Output
// Output 1:

//  3
// Output 2:

//  4


// Example Explanation
// Explanation 1:

//  Flip the substring [0:2] then A = "111" so answer will be 3
// Explanation 2:

//  Flip the substring [1:2] then A = "11110" so answer will be 4



