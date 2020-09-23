/*

https://codeforces.com/blog/entry/82953
https://codeforces.com/contest/622/problem/F
https://codeforces.com/contest/622/submission/93584356



f(x)=1^k+2^k+ .....+(x-1)^k+x^k


degree of f(x)= k+1



we need k+2 points to represent polynomial
-> (1,y1),(2,y2)..(k+2,yk+2)


then we can calculate f(Z) etc in O(k) time Z->integer
f(x)=  y1 * [ (x-x2)*(x-x3)*..]/ [ (x1-x2)*(x1-x3)*.] +.....

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define ar array<int,2>
#define inf 1000000000000000000 
#define deb(x) cerr << "\n" << (#x) << " is " << (x) << endl
int mod=1e9+7;
int min(int a,int b){return (a<b)?a:b;}
int max(int a,int b){return (a>b)?a:b;}
int fp(int a,int b){if(b==0) return 1;int x=fp(a,b/2);x=(x*x)%mod;if(b&1) x=(x*a)%mod;return x;}


const int N=1e6+5;
int yi[N],pre[N],iden[N],suf[N];

int fact(int n)
{
  int x=1;
  for(int i=1;i<=n;i++)
    x=(x*i)%mod;
  return x;
}
//calculating f(X)
int interpolate(int X,int k)
{
    if(k==0)
      return X;

    pre[0]=1;

    int z=fact(k+1);
    if((k+1)&1)
      z*=-1;
    if(z<0)
      z+=mod;
    z=fp(z,mod-2);
    //z=inverse of [ (-1)*(-2)*...* (-(k+1)) ]
    for(int i=1;i<=k+2;i++)
    {
      //deb(z);
      iden[i]=z;
      z=(z*(k-i+2))%mod;
      z*=-1;
      if(z<0)
      z+=mod;
      z=(z*fp(i,mod-2))%mod;
      
    }

    for(int i=1;i<=k+2;i++)
    {
      pre[i]=(pre[i-1]*(X-i))%mod;
      if(pre[i]<0)
        pre[i]+=mod;
     // deb(pre[i]);
    }

    suf[k+3]=1;
    for(int i=k+2;i>=1;i--)
    {
      suf[i]=(suf[i+1]*(X-i))%mod;
      if(suf[i]<0)
        suf[i]+=mod;
     // deb(suf[i]);
    }


    int ans=0;
    for(int i=1;i<=k+2;i++)
    {
      int num=(pre[i-1]*suf[i+1])%mod;
      num=(num*yi[i])%mod;
      ans+=(num*iden[i])%mod;
      if(ans>=mod)
        ans-=mod;
      //deb(num);
      //deb(iden[i]);

    }

    return ans;

}


signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 srand(time(0));

 int n,k;
 cin>>n>>k;

 yi[0]=0;
 for(int xi=1;xi<N;xi++)
 {
  yi[xi]=(yi[xi-1]+fp(xi,k))%mod;
 }
  

 cout<<interpolate(n,k)<<endl;
 



}
