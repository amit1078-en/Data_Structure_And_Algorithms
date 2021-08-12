/*
809. Expressive Words
Medium

498

1206

Add to List

Share
Sometimes people repeat letters to represent extra feeling. For example:

"hello" -> "heeellooo"
"hi" -> "hiiii"
In these strings like "heeellooo", we have groups of adjacent letters that are all the same: "h", "eee", "ll", "ooo".

You are given a string s and an array of query strings words. A query word is stretchy if it can be made to be equal to s by any number of applications of the following extension operation: choose a group consisting of characters c, and add some number of characters c to the group so that the size of the group is three or more.

For example, starting with "hello", we could do an extension on the group "o" to get "hellooo", but we cannot get "helloo" since the group "oo" has a size less than three. Also, we could do another extension like "ll" -> "lllll" to get "helllllooo". If s = "helllllooo", then the query word "hello" would be stretchy because of these two extension operations: query = "hello" -> "hellooo" -> "helllllooo" = s.
Return the number of query strings that are stretchy.

 

Example 1:

Input: s = "heeellooo", words = ["hello", "hi", "helo"]
Output: 1
Explanation: 
We can extend "e" and "o" in the word "hello" to get "heeellooo".
We can't extend "helo" to get "heeellooo" because the group "ll" is not size 3 or more.
Example 2:

Input: s = "zzzzzyyyyy", words = ["zzyy","zy","zyy"]
Output: 3
 

Constraints:

1 <= s.length, words.length <= 100
1 <= words[i].length <= 100
s and words[i] consist of lowercase letters.
*/

     int len = s.length(); 
        vector<int> quan;
        for(int i = 0; i<len;i++)
        {
            given.push_back(s[i]);    
            int j = i+1;
            quan.push_back(1);
            while(j<len && s[i]==s[j])
            {
                quan[quan.size()-1]+=1;
                j++;
            }
            i = j-1;
        }
        len = words.size();
        int ans = 0;
        
        for(int k = 0 ; k<len;k++)
        {
            s = words[k];
            string temp;
            int lenn = s.length(); 
            vector<int> quann;
            for(int i = 0; i<lenn;i++)
            {
                temp.push_back(s[i]);    
                int j = i+1;
                quann.push_back(1);
                while(j<lenn && s[i]==s[j])
                {
                    quann[quann.size()-1]+=1;
                    j++;
                }
                i = j-1;
            }
            if(temp.length()==given.length())
            {
                bool append = true;
                for(int i = 0 ; i<given.length();i++)
                {
                    if(given[i]!=temp[i] || quann[i]>quan[i] || (quan[i]<3 && quann[i]<quan[i]))
                    {
                        append =false;
                        break;
                    }
                }
                if(append)
                {
                    ans+=1;
                }
            }
        }
        return ans;
    }
};
