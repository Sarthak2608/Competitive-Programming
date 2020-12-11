/*
https://en.wikipedia.org/wiki/Fibonacci_number#Primes_and_divisibility
*/

class Solution{   
public:
    int fib(int n,vector<int> &dp,int &mod)
    {
        if(dp[n]!=-1)
        return dp[n];
        if(n<=1)
        return n;
        return dp[n]=(fib(n-1,dp,mod)+fib(n-2,dp,mod))%mod;
        
    }
    int fibGcd(int m, int n){
        //complete the function here
        int g=__gcd(m,n);
        vector<int> dp(g+1,-1);
        int mod=100;
        return fib(g,dp,mod);
        
    }
    
};
