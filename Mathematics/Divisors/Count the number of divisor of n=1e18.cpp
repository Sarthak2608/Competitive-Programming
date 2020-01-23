#include <bits/stdc++.h> 
using namespace std; 
#define int unsigned long long int


int mul(int a,int b,int mod)
{
    int ans=0;
    while(b>0)
    {
        if(b&1)
        {
            ans=(ans+a)%mod;
        }
        a=(a*2)%mod;
        b/=2;
    }
    return ans;
}
int fp(int a,int b,int mod)
{
    if(b==0)
    return 1;
    int x=fp(a,b/2,mod);
    x=mul(x,x,mod);
    if(b&1)
    x=mul(x,a,mod);
    return x;
}

bool probablyPrimeFermat(int n, int iter=6) {
     //cout<<n<<endl;
    if (n < 4)
        return n == 2 || n == 3;

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (fp(a, n - 1, n) != 1)
            return false;
    }
    return true;
}
signed main()
{
    int mxn=1e6;
    bool vis[mxn+1]={0};
    vector<int> prime;
    for(int i=2;i<=mxn;i++)
    {
         if(!vis[i])
         {
              prime.push_back(i);
              for(int j=2;j*i<=mxn;j++)
              vis[j*i]=true;
         }
    }
    int n,ans=1;
    cin>>n;
    for(auto i:prime)
    {
         if(i*i*i>n)
         break;
         if(n%i==0)
         {
              int c=1;
              while(n%i==0)
              {
                   n/=i;
                   c++;
              }
              ans*=c;
         }
    }
    if(n>1)
    {
         int y=sqrtl(n);
         int z=probablyPrimeFermat(n);
         if(z)
         {
              ans*=2;
         }
         else if(y*y==n)
         {
              ans*=3;
         }
         else
         {
              ans*=4;
         }
    }
    cout<<ans;
    return 0;
}
