/*
https://cses.fi/problemset/task/1690/
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int mod=1e9+7;
int min(int a,int b){
  return (a<b)?a:b;
}
int max(int a,int b){
  return (a>b)?a:b;
}


const int N=1e6+5;
vector<int> v[N];
int n,m;
int ans[N][21];

int dfs(int node,int mask)
{
  if(node==n)
  {
    if(mask==(1ll<<(n))-1)
      return 1;
    return 0;
  }
  if(ans[mask][node]!=-1)
    return ans[mask][node];
  int x=0;
  for(auto i:v[node])
  {
    int nmask=(1ll<<(i-1))^mask;
    if(nmask>mask)
    {
        x+=dfs(i,nmask);
        if(x>=mod)
          x-=mod;
    }
  }
  return ans[mask][node]=x;
}


signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int x,y;
 memset(ans,-1,sizeof(ans));
 cin>>n>>m;
 for(int i=1;i<=m;i++)
 {
  cin>>x>>y;
  v[x].push_back(y);
 } 
 cout<<dfs(1,1);
 


}
