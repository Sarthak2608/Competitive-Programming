/*
disconnect the bridge then in color the each component ,then
make new graph (it will be tree)

Danger: not tested
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
int fp(int a,int b){
  if(b==0) return 1;
  int x=fp(a,b/2);
  x=(x*x)%mod;
  if(b&1) x=(x*a)%mod;
  return x;
}
int n,m,a,b;
const int N=2e5+5;
vector<array<int,2>> v[N];
vector<int> ng[N];
vector<int> vis(N),lw(N),dis(N),bridge(N),cmp(N),sz(N),par(N);
int tm1,ct;

void dfs(int node,int p=-1)
{
  vis[node]=1;
  dis[node]=++tm1;
  lw[node]=dis[node];
  for(auto i:v[node])
  {
    if(i[0]==p)
      continue;
    if(!vis[i[0]]){
      dfs(i[0],node);
      
    }
    if(dis[node]>=lw[i[0]])
    {
      bridge[i[1]]=0;
    }
    lw[node]=min(lw[node],lw[i[0]]);
  }
}

void dfs2(int node)
{
  sz[ct]++;
  cmp[node]=ct;
  for(auto i:v[node])
  {
    if(cmp[i[0]]==0&&!bridge[i[1]])
      dfs2(i[0]);
  }
}

void dfs3(int node,int p=-1)
{

  cout<<node<<" "<<sz[node]<<" "<<p<<"\n";
  par[node]=p;
  vis[node]=1;
  for(auto i:ng[node])
  {
    if(!vis[i])
    {
      dfs3(i,node);
    }
  }
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 int t,x,y;
 cin>>t;
 while(t--)
 {
    tm1=0;
    cin>>n>>m;
    vis=vector<int>(n+1);
    for(int i=1;i<=n;i++)
    {
      sz[i]=0;
      cmp[i]=0;
      vis[i]=0;
      v[i].clear();
      ng[i].clear();
    }
    for(int i=1;i<=m;i++)
    {
      bridge[i]=1;
      cin>>x>>y;
      v[x].push_back({y,i});
      v[y].push_back({x,i});
    }
    dfs(1);

    for(int i=1;i<=m;i++)
    {
      cout<<i<<":"<<bridge[i]<<endl;
    }
    vis=vector<int>(n+1);
    ct=0;
    for(int i=1;i<=n;i++)
    {
      if(cmp[i]==0)
      {
        ct++;
        dfs2(i);
      }
    }
    //compressed graph as a tree
    for(int i=1;i<=n;i++)
    {
        for(auto j:v[i])
        {
          if(cmp[i]!=cmp[j[0]])
          {
            ng[cmp[i]].push_back(cmp[j[0]]);
            ng[cmp[j[0]]].push_back(cmp[i]);
          }
        }
    }

    dfs3(1);
 }

}

/*
1
7 7 
1 2
2 3
3 4
4 5
5 6
6 7
7 5
*/
