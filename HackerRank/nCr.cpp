//mod=142857
#include <bits/stdc++.h>

using namespace std;

#define int long long int
int Legendre(int n,int p)
{
    int sum=0;
    while(n>0)
    {
        sum+=(n/p);
        n/=p;
    }
    return sum;
}
int fp(int a,int b,int mod)
{
    if(b==0)
    return 1;

    int x=fp(a,b/2,mod);
    x=(x*x)%mod;
    if(b&1)
    x=(x*a)%mod;
    return x;
}
int gcdExtended(int a, int b, int *x, int *y); 

int modInverse(int a, int m) 
{ 
    int x, y; 
    int g = gcdExtended(a, m, &x, &y); 
    int res = (x%m + m) % m; 
    return res;
} 
  
int gcdExtended(int a, int b, int *x, int *y) 
{ 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    int x1, y1; 
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 

int extractFact(int n,int p,int mod)
{
    int f[mod];
    f[0]=1;
    for(int i=1;i<mod;i++ )
    {   
        if(i%p==0)
        {
            f[i]=f[i-1];
        }
        else
        {
            f[i]=(f[i-1]*i)%mod;
        }
    }
    int ans=1;
    while(n>0)
    {
        if((n/mod)!=0)
       ans=( ans*fp(f[mod-1]%mod,n/mod,mod) )%mod ;
       ans=( ans*f[n%mod] )%mod;
       n/=p;
    }
    return ans;
}

int nCr(int n,int r,int base,int exponent)
{
   int x=Legendre(n,base)-Legendre(r,base)-Legendre(n-r,base);
   if(x>=exponent)
   {
       return 0;
   }
   int mod=1;
   for(int i=1;i<=exponent;i++)
   mod*=base;

   int num= extractFact(n,base,mod);
   int den= ( extractFact(n-r,base,mod) * extractFact(r,base,mod) )%mod;
   
   int ans=(num*modInverse(den,mod))%mod;
   ans=(ans*fp(base,x,mod) )%mod;

   return ans;
}

int CRT(int x0,int x1,int m,int n)
{
    int mod=m*n;
   int ans= ( (x0* (n*modInverse(n,m))%mod )%mod  + (x1*(m*modInverse(m,n))%mod )%mod )%mod;
   return (ans+mod)%mod;
}



signed main(){
     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int ans,p1,t,n,r,x,y;
     vector<pair<int,int>> v;
        v.push_back({3,3});
        v.push_back({11,1});
        v.push_back({13,1});
        v.push_back({37,1});
    cin>>t;
    while(t--)
    {
        cin>>n>>r;
         p1=1;
        for(int i=0;i<4;i++)
        {
              y=1;
              for(int j=1;j<=v[i].second;j++)
              {
                  y*=v[i].first;
              }
               x=nCr(n,r,v[i].first,v[i].second);
               if(i==0)
               {
                   ans=x;
               }
               else
               {
                   ans=CRT(ans,x,p1,y);
               }
               p1*=y;
        }
        cout<<ans<<'\n';
    }
}
