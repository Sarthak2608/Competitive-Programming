/*
https://cses.fi/problemset/task/1748/
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
int bit[N]={0};
void add(int node,int x)
{
  x=(x+mod)%mod;
  for(;node<N;node+=(node&-node)){
    bit[node]+=x;
    if(bit[node]>=mod)
    bit[node]-=mod;
  }
}
int get(int node)
{
  if(node<1)
    return 0;
  int x=0;
  for(;node>0;node-=(node&-node)){
    x+=bit[node];
    if(x>=mod)
    x-=mod;
  }
  return x;
}

void solve()
{
  int n;
  cin>>n;
  int a[n+1];
  map<int,int> mp;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
    mp[a[i]];
  }
  int ct=0;
  for(auto &i:mp)
    i.second=++ct;
  int ans=0;
  for(int i=n;i>=1;i--)
  {
    a[i]=mp[a[i]];
    int x=(get(n)-get(a[i])+mod)%mod;
    add(a[i],1+x);
    ans+=1+x;
    if(ans>=mod)
      ans%=mod;
  }
  cout<<ans;
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 srand(time(0));
 int t=1;
 //cin>>t;
 for(int i=1;i<=t;i++)
 {
   solve();
 }


}
