/*
https://codeforces.com/contest/292/problem/D
Merging two dsu

Another Sol: https://codeforces.com/contest/292/submission/39515188

*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

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
const int N=505,Q=2e4+5;
int n,m;
vector<vector<int>> ldsu(Q),rdsu(Q),szl(Q);
int store[Q];
vector<int> par(N),sz(N);



vector<int> cmp[N];
int c;
void merge(int x,int y,vector<int> &sz1,vector<int> &par1)
{
  x=par1[x];
  y=par1[y];

  if(x==y)
    return;
  c--;
  if(sz1[x]<sz1[y])
  {
    swap(x,y);
  }

  sz1[x]+=sz1[y];
  par1[y]=x;
  for(auto i:cmp[y])
  {
    par1[i]=x;
    cmp[x].push_back(i);
  }
  cmp[y].clear();
}


int w;






int merge_dsu(vector<int> par1,vector<int> &par2,vector<int> sz1)
{
  int x,y;
  for(int i=1;i<=n;i++)
  {
    x=i;
    y=par2[i];

       while(x!=par1[x])
      {
        x=par1[par1[x]];
        x=par1[x];
      }

       while(y!=par1[y])
      {
        y=par1[par1[y]];
        y=par1[y];
      }


      if(x==y)
        continue;
      w--;
      if(sz1[x]<sz1[y])
      {
        swap(x,y);
      }
      par1[y]=x;
      sz1[x]+=sz1[y];
  }
  return w;
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 cin>>n>>m;
 int x,y;

 
 vector<array<int,2>> edge(m+1);
 c=n;

 for(int i=1;i<=n;i++)
 {
  par[i]=i;
  sz[i]=1;
  cmp[i].push_back(i);
 }
 store[0]=c;
 ldsu[0]=par;
 szl[0]=sz;
 for(int i=1;i<=m;i++)
 {
  cin>>x>>y; 
  edge[i][0]=x;
  edge[i][1]=y;
  merge(x,y,sz,par);
  ldsu[i]=par;
  szl[i]=sz;
  store[i]=c;
 }


 for(int i=1;i<=n;i++)
 {
  par[i]=i;
  sz[i]=1;
  cmp[i].clear();
  cmp[i].push_back(i);
 }
 c=n;

 rdsu[m+1]=par;
 for(int i=m;i>=1;i--)
 {
  x=edge[i][0];
  y=edge[i][1];
  merge(x,y,sz,par);
  rdsu[i]=par;
 }
 



 int q,l,r;
 cin>>q;
 while(q--)
 {
  cin>>l>>r;
  w=store[l-1];
  cout<<merge_dsu(ldsu[l-1],rdsu[r+1],szl[l-1])<<endl;

 }




}
