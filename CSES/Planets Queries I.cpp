/*
https://cses.fi/problemset/task/1750/
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
const int N=2e5+5;
vector<int> v[N],v2[N],indeg(N),vis(N),par(N),pos(N),mark(N),child(N);
vector<array<int,2>> limit(N);


vector<vector<int>> cycles,dp(N,vector<int>(21));
int c=0,n;

void dfs(int node,int p=-1)
{
  vis[node]=1;
  par[node]=p;
  
  for(auto i:v[node])
  {
      if(vis[i]==1)
      {    
          int prev=node;   
          vector<int> path;
          int ct=1;
          while(node!=-1&&node!=i)
          {
            path.push_back(node);
            node=par[node];
          }
          path.push_back(node);
          reverse(path.begin(),path.end());
          ++c;
          cycles.push_back(path);
          for(int j=0;j<path.size();j++)
          {
            mark[path[j]]=c;
            pos[path[j]]=j;
          }
          node=prev;
      }
      else if(vis[i]==0)
      {
        dfs(i,node);
      }
  }
  if(mark[node])
  {
    limit[node]={node,0};
  }
  else
  {
    assert(v[node].size()>0);
    limit[node]=limit[v[node][0]];
    limit[node][1]++;
  }
  vis[node]=2;
}


void precompute()
{
  for(int i=1;i<=n;i++)
  {
    dp[i][0]=child[i];
  }
  for(int j=1;j<20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      dp[i][j]=dp[dp[i][j-1]][j-1];
    }
  }
}

int binarylifting(int node,int d)
{
  while(d>0)
  {
    int jump=log2(d);
    node=dp[node][jump];
    d-=(1ll<<jump);
  }
  return node;
}

int cyclequery(int node,int k)
{
  int n=cycles[mark[node]-1].size();
  assert(n>0);
  return cycles[mark[node]-1][(pos[node]+k)%n];
}

int solve(int node,int k)
{
  if(mark[node])
  {
    return cyclequery(node,k);
  }
  if(k>=limit[node][1])
  {
    return cyclequery(limit[node][0],k-limit[node][1]);
  }
  return binarylifting(node,k);
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 int q,x,k;
 cin>>n>>q;
 for(int i=1;i<=n;i++)
 {
  cin>>x;
  child[i]=x;
  v[i].push_back(x);
  indeg[x]++;
 }

 for(int i=1;i<=n;i++)
 {
  if(!indeg[i]&&!vis[i])
  {
    dfs(i);
  }
 }

 for(int i=1;i<=n;i++)
 {
  if(!vis[i])
  {
    dfs(i);
  }
 }
 precompute();

 while(q--)
 {
  cin>>x>>k;
  cout<<solve(x,k)<<endl;
 }


}

/*
*/
