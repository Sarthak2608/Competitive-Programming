#include <bits/stdc++.h>

using namespace std;

int phi(int n)
{
    long ans=n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n/=i;
            }
            ans=ans-ans/i;
        }
    }
    if(n>1)
    {
        ans=ans-ans/n;
    }
    return ans;
}
long long fp(long long a,long long b,long long mod)
{
    if(b==0)
    return 1;
    long long x=fp(a,b/2,mod);
    x=(x*x)%mod;
    if(b&1)
    x=(x*a)%mod;
    return x;
}
long long solve(long long a,long long b,long long mod)
{
    long long ans=fp(a%mod,phi(mod)+b%phi(mod),mod);
    return ans;
}
int main()
{
    int a,b;
    cin>>a>>b;
    long long p=solve(2,a,phi(b));
    long long ans=solve(2,p,b);
    cout<<ans;
}
