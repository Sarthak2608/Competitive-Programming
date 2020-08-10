/*

dp[mask] represent the number of rides required to travel for the persons whose bit is set in mask
res[mask] remaining maximum capacity
Idea: iterate all possible order to put the items in box or elevator and maintain the maximum capactiy will left

https://cses.fi/problemset/task/1653/

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


void solve()
{
    int n,x;
    cin>>n>>x;
    vector<int> a(n+1);
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    } 

    int dp[1ll<<n],rem[1ll<<n];
    for(int i=0;i<(1ll<<n);i++)
    {
      dp[i]=INT_MAX;
      rem[i]=0;
    }

    dp[0]=1;
    rem[0]=x;

    for(int i=0;i<(1ll<<n);i++)
    {
      for(int j=0;j<n;j++)
      {
          if(!((i>>j)&1))
          {
              int p=dp[i];
              int r=rem[i];
              int w=a[j];
              if(w<=r)
              {
                r-=w;
              }      
              else
              {
                p++;
                r=x-w;
              }     

              int nmask=i|(1ll<<j);
              if(dp[nmask]>p||(dp[nmask]==p&&rem[nmask]<r))
              {
                dp[nmask]=p;
                rem[nmask]=r;
              }
          }
      }
    }

    cout<<dp[(1ll<<n)-1];
   



}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 srand(time(0));
 int t;
 t=1;
 for(int i=1;i<=t;i++)
 {
   solve();
 }


}
