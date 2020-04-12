/*

 https://codeforces.com/contest/1000/problem/E
 Firstly find all bridge in graph then remove the bridges in a graph then color each disconnected component with unique color. then 
 assume each connected component as a new vertex then reconnect the graph with the bridge ,this new graph will be the tree

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

const int N=3e5+5;
vector<vector<array<int,2>>> v(N);
vector<vector<int>> G(N);
vector<int> vis(N),dis(N),low(N),bridge(N);

void dfs(int node,int p)
{
  static int tm=0;
  vis[node]=1;
  dis[node]=++tm;
  low[node]=dis[node];
  for(auto i:v[node])
  {
    if(i[0]==p)
    {
      continue;
    }
    if(vis[i[0]])
    {
      low[node]=min(low[node],dis[i[0]]);
      low[node]=min(low[node],low[i[0]]);
      continue;
    }
    dfs(i[0],node);
    low[node]=min(low[node],low[i[0]]);
    if(dis[node]<low[i[0]])
    {
      bridge[i[1]]=1;
    }
  }
}


void dfs2(int node,int p,int comp)
{
  static int cmp=1;
  vis[node]=1;
  for(auto i:v[node])
  {
    if(!vis[i[0]])
    {
        if(bridge[i[1]])
        {
          cmp++;
          G[comp].push_back(cmp);
          G[cmp].push_back(comp);
          dfs2(i[0],node,cmp);
          
        }
        else
        {
          dfs2(i[0],node,comp);
        }
    }
  }

}
int nd=-1,mx=-1;

void dfs3(int node,int p,int level)
{
  if(level>mx)
  {
    mx=level;
    nd=node;
  }
  for(auto i:G[node])
  {
     if(i!=p)
     {
      dfs3(i,node,level+1);
     }
  }
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

 int n,m,x,y;
 cin>>n>>m;
 for(int i=1;i<=m;i++)
 {
  cin>>x>>y;
  v[x].push_back({y,i});
  v[y].push_back({x,i});
 }
 dfs(1,1);

 vis=vector<int>(N);
 dfs2(1,1,1);
 dfs3(1,1,0);
 dfs3(nd,-1,0);
 cout<<mx;

}
