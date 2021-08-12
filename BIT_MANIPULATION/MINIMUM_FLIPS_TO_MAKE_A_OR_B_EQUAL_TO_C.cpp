class Solution {
public:
    int minFlips(int a, int b, int c) {
        int steps = 0;
        
        while(a>0 && b>0 )
        {
            int z = a&1;
                int x = b&1;
                    int v = c&1;
            if((z|x)  !=v)
            {
                
                if(z==1 && x==1 && v==0)
                {
                    steps+=2;
                }
                else
                {
                    steps++;
                }
            }
            a = a>>1;
            b = b>>1;
            c = c>>1;
        }
        
        while(a>0)
        {
            if((a&1)!=(c&1))
            {
                steps++;
            }
            a=a>>1;
            c=c>>1;
        }
        while(b>0)
        {
            if((b&1)!=(c&1))
            {
                steps++;
            }
            b=b>>1;
            c=c>>1;
        }
        while(c>0 )
        {
            if(c&1)
            {
                steps++;
            }
            c=c>>1;
            }
        return steps;
    }
};
