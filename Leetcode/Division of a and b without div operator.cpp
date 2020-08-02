/*
https://leetcode.com/problems/divide-two-integers/
*/
class Solution {
public:
    array<long long,2> mydiv(long long a,long long b)
    {
        if(a<b)
        {
            return {a,0};
        }
        if(a==b)
        {
            return {0,1};
        }
        long long int x=a/2;
        auto y=mydiv(x,b);
        long long int rem=2*y[0]+(a&1);
        long long int quo=2*y[1];
        //cout<<rem<<":"<<quo<<" "<<2*y[0]<<" "<<y[1]<<endl;
        if(rem>=b)
        {
            rem-=b;
            quo++;
        }
        return {rem,quo};
    }
    int divide(int a1, int b1) {
        if(a1==-2147483648&&b1==-1)
            return 2147483647;
        int x=1;
        if(a1<0)
            x*=-1;
        if(b1<0)
            x*=-1;
        return x*mydiv(abs(a1),abs(b1))[1];
            
    }
};
