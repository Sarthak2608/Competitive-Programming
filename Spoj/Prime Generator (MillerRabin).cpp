#include <bits/stdc++.h>
#define int long long int
using namespace std;
vector<int> prime;
int mod=1e9+7;
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
int test(int a,int s,int d,int n)
{
    int b=fp(a,d,n);
    if(b==1||b==n-1)
    {
        return 1;
    }
  
    for(int i=1;i<s;i++)
    {
        b=mul(b,b,n);
        if(b==n-1)
        return 1;
    }
    return 0;
    
}
int myran(int mod){
     int a=rand()%mod;
     int b=rand()%mod;
     return (mul(a,(RAND_MAX+1),mod)+b)%mod;
}
int MillerRabin(int n)
{
    if(n==1)
    return 0;
    for(auto p:prime)
    {
        if(p*p>n)
        {
            return 1;
        }
        if(n%p==0)
        return 0;
    }
    
    int s=0;
    int d=n-1;
    while(d%2==0)
    {
        d/=2;
        s++;
    }
   
    
    for(int i=1;i<=5;i++)
    {
         int a=2+myran(n-3)%(n-3);
        if(test(a,s,d,n)==0)
        return 0;
    }
    return 1;
}

signed main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int mxn=100,visit[105]={0};
for(int i=2;i<=mxn;i++)
{
    if(visit[i]==0)
    {
        prime.push_back(i);
        for(int j=2;j*i<=mxn;j++)
        visit[j*i]=1;
    }
}
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(;n<=m;n++)
        {
            if(MillerRabin(n))
            {
                cout<<n<<'\n';
            }
        }
        cout<<endl;
    }
	return 0;
}
