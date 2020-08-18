/*
Time complexity: O(n*n*2^n)

but it if approx (n*2^n)
in this n is due to inner loop in recursion
For each pos there only be mask which has (n-pos+1) bit is on


*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define ar array<int,2>
#define inf 1000000000000000000 
int mod=1e9+7;
int min(int a,int b){return (a<b)?a:b;}
int max(int a,int b){return (a>b)?a:b;}
int fp(int a,int b){if(b==0) return 1;int x=fp(a,b/2);x=(x*x)%mod;if(b&1) x=(x*a)%mod;return x;}


const int N=2e5+5;
int n;
int v[22][22];
int dp[22][1ll<<22];
int solve(int pos,int mask)
{ 
    if(pos==n+1)
      return 1;
    if(dp[pos][mask]!=-1)
      return dp[pos][mask];
    int x=0;
    for(int i=0;i<n;i++)
    {
      if(mask&(1ll<<i))
      {
        if(!v[pos][i+1])
          continue;
        x+=solve(pos+1,mask^(1ll<<i));
        if(x>=mod)
          x-=mod;
      }
    }
    return dp[pos][mask]=x;
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 memset(dp,-1,sizeof(dp));
 cin>>n;

 for(int i=1;i<=n;i++)
 {
  for(int j=1;j<=n;j++)
  {
    cin>>v[i][j];
  }
 }

 int ans=solve(1,(1ll<<n)-1);
 cout<<ans;





}
