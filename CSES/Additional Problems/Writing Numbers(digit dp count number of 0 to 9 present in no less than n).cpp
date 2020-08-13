/*
https://cses.fi/problemset/task/1086/
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
int dp[20][2][2][11];


void count(string &n,int pos,int lim,int ok)
{
  if(pos==n.size()){
    return;
  }
  if(dp[pos][lim][ok][0]!=-1)
    return;
  for(int i=0;i<=10;i++)
    dp[pos][lim][ok][i]=0;

  int l=0,r=9;
  if(lim)
    r=n[pos]-'0';

  for(;l<=r;l++)
  {
    int nlim=0;
    if(lim&&l==r)
      nlim=1;
    int nok=ok;
    if(l!=0)
      nok=1;

    count(n,pos+1,nlim,nok);

    int tot=0;
    for(int j=0;j<10;j++){
      if(pos+1<n.size())
      {
        dp[pos][lim][ok][j]+=dp[pos+1][nlim][nok][j];
      }
    }
    if(pos+1==n.size()){
      if(nok){
      dp[pos][lim][ok][l]=1;
      dp[pos][lim][ok][10]++;
      }
    }
    else{
    dp[pos][lim][ok][10]+=dp[pos+1][nlim][nok][10];
    if(nok)
    dp[pos][lim][ok][l]+=dp[pos+1][nlim][nok][10];
    }
  }
}

void solve()
{
  int n;
  cin>>n;   
  int ans=0;


  int l=1,r=LLONG_MAX;
  while(l<=r)
  {
    int mid=(l+r)/2;

    string ms=to_string(mid);
    
    memset(dp,-1,sizeof(dp));
   count(ms,0,1,0);
    int f=1;
    for(int i=0;i<10;i++)
    {
      if(dp[0][1][0][i]>n)
      {
        f=0;
        break;
      }
    }
    if(f)
    {
      ans=mid;
      l=mid+1;
    }
    else
    {
      r=mid-1;
    }
  }
  cout<<ans<<endl;
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
