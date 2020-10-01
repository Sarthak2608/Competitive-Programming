/*
https://codeforces.com/contest/1416/problem/D

convert the graph into tree using dsu

*/

#include <bits/stdc++.h>

using namespace std;
const int N=5e5+5;
int n,m;
int p[N]={0};
int edge[N][2],del[N]={0},par[N],st[N],en[N],inv[N];
vector<int> v[N];
array<int,2> bit[4*N];


int find(int x)
{
  return (x==par[x])?x:par[x]=find(par[x]);
}

void merge(int x,int y)
{
  x=find(x);
  y=find(y);
  if(x==y)
    return ;

  n++;
  p[n]=-1;
  par[n]=n;
  par[x]=n;
  par[y]=n;
  v[n].push_back(x);
  v[n].push_back(y);
}

int timer=0;

void dfs(int node,int p=-1)
{
  st[node]=++timer;
  inv[timer]=node;
  for(auto i:v[node])
  {
    if(i!=p)
      dfs(i,node);
  }
  en[node]=timer;
}

void build(int id,int l,int r)
{
  if(l==r)
  {
    int node=inv[l];
    bit[id]={p[node],l};
    return;
  }
  int mid=(l+r)/2;
  build(2*id,l,mid);
  build(2*id+1,mid+1,r);
  bit[id]=max(bit[2*id],bit[2*id+1]);
}

array<int,2> get(int id,int l,int r,int L,int R)
{
  if(R<l||r<L)
    return {-1,-1};

  if(L<=l&&r<=R)
  {
    return bit[id];
  }
  int mid=(l+r)/2;
  return max(get(2*id,l,mid,L,R),get(2*id+1,mid+1,r,L,R));
}

void upd(int id,int l,int r,int pos)
{
  if(l==r&&l==pos)
  {
    bit[id][0]=0;
    return;
  }
  int mid=(l+r)/2;
  if(pos<=mid)
    upd(2*id,l,mid,pos);
  else
    upd(2*id+1,mid+1,r,pos);
  bit[id]=max(bit[2*id],bit[2*id+1]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<array<int,2>> qr;
  int q,x,y;
  cin>>n>>m>>q;

  for(int i=1;i<=n;i++)
  {
    cin>>p[i];
  }

  for(int i=1;i<=m;i++)
  {
    cin>>x>>y;
    edge[i][0]=x;
    edge[i][1]=y;
  }


  for(int i=1;i<=q;i++)
  {
    cin>>x>>y;
    qr.push_back({x,y});
    if(x==2)
    {
      del[y]=1;
    }
  }

  for(int i=1;i<=m;i++)
  {
    if(!del[i])
      qr.push_back({2,i});
  }


  for(int i=1;i<=n;i++)
  {
    par[i]=i;
  }

  for(int i=qr.size()-1;i>=0;i--)
  {
    x=qr[i][0];
    y=qr[i][1];
    if(x==2)
    {
      merge(edge[y][0],edge[y][1]);
    }
    else
    {
      qr[i][1]=find(qr[i][1]);
     // cout<<i<<":"<<qr[i][1]<<endl;
    }
  }

  for(int i=1;i<=n;i++)
    if(i==find(i)){
      dfs(i);
    }

  build(1,1,timer);
  for(auto i:qr)
  {
    if(i[0]==1)
    {
     // cout<<st[i[1]]<<':'<<en[i[1]]<<" "<<i[1]<<endl;
      auto mx=get(1,1,timer,st[i[1]],en[i[1]]);
      cout<<mx[0]<<endl;
      //cout<<mx[0]<<" "<<mx[1]<<endl;
      upd(1,1,timer,mx[1]);
    }
  }

}
