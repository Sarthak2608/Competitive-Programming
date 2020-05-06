/*
  https://codeforces.com/favourite/blogEntries
  https://www.hackerrank.com/contests/hourrank-15/challenges/kittys-calculations-on-a-tree/problem
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int mod=1e9+7;

int fp(int a,int b){
  if(b==0) return 1;
  int x=fp(a,b/2);
  x=(x*x)%mod;
  if(b&1) x=(x*a)%mod;
  return x;
}


const int N=2e5+5;
vector<int> v[N],tmp,adj[N];
int dp[N][20],subtree[N];
int lvl[N],kk,p,tot;
vector<bool> important(N);


int st[N],en[N];
int n,q,tm1;

void dfs(int node,int p)
{
  st[node]=++tm1;
  dp[node][0]=p;
  for(auto i:v[node])
  {
    if(i==p)
      continue;
    lvl[i]=lvl[node]+1;
    dfs(i,node);
  }
  en[node]=tm1;
}

void precompute()
{
   for(int i=1;i<=18;i++)
   {
      for(int j=1;j<=n;j++)
      {
        dp[j][i]=dp[dp[j][i-1]][i-1];
      }
   }
}

int lca(int x,int y)
{
   if(lvl[x]>lvl[y])
   {
    swap(x,y);
   }
   int d=lvl[y]-lvl[x];
   while(d>0)
   {
      int jump=log2(d);
      y=dp[y][jump];
      d-=(1ll<<jump);
   }

   while(x!=y)
   {
       d=log2(lvl[x]);
       while(d>0&&dp[x][d]==dp[y][d])
       {
            d--;
       }
       x=dp[x][d];
       y=dp[y][d];
   }
   
   return x;
}
int ans;
int dfs2(int node)
{
  int y=0,x=0;
  for(auto i:adj[node])
  {
    y=dfs2(i);
    x=(x+y)%mod;
    int z=((p-y+mod)*y)%mod;
    z=((lvl[i]-lvl[node])*z)%mod;
    ans=(ans+z)%mod;
    subtree[node]+=subtree[i];
  }
  
  subtree[node]+=important[node];
  
  if(important[node])
    x=(x+node)%mod;

  return x;
}

void virtual_tree()
{
   sort(tmp.begin(),tmp.end(),[](int a,int b){
      return st[a]<st[b];
   });

   int k=tmp.size();
   for(int i=0;i<k-1;i++)
   {
      tmp.push_back(lca(tmp[i],tmp[i+1]));
   }

   sort(tmp.begin(),tmp.end(),[](int a,int b){
      return st[a]<st[b];
   });
  
   tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());

   vector<int> vir;
   vir.push_back(tmp[0]);
   for(int i=1;i<tmp.size();i++)
   {
      if(st[vir.back()]<=st[tmp[i]]&&en[tmp[i]]<=en[vir.back()])
      {
          vir.push_back(tmp[i]);
      }
      else
      {
        while(!(st[vir.back()]<=st[tmp[i]]&&en[tmp[i]]<=en[vir.back()]))
        {
          adj[vir[vir.size()-2]].push_back(vir.back());
          vir.pop_back();
        }
        vir.push_back(tmp[i]);
      }
   }

     while(vir.size()>1)
     {
          adj[vir[vir.size()-2]].push_back(vir.back());
          vir.pop_back();
     }

   int y=dfs2(tmp[0]);
   
   for(auto i:tmp)
    adj[i].clear();

}


signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int x,y;
 cin>>n>>q;

 for(int i=1;i<n;i++)
 {
  cin>>x>>y;
  v[x].push_back(y);
  v[y].push_back(x);
 }
 tm1=0;
 lvl[1]=0;
 dfs(1,0);
 precompute();
 tot=0;

 while(q--)
 {
  p=0;
  int k;
  cin>>k;
  tot=k;
  tmp.clear();
  for(int i=1;i<=k;i++)
  {
    cin>>x;
    tmp.push_back(x);
    important[x]=true;
    p=(p+x)%mod;
  }
  ans=0;
  virtual_tree();  
  cout<<ans<<endl;
  for(auto i:tmp)
    important[i]=false;
 }
 


 



}
