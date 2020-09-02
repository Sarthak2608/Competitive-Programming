/*
https://codeforces.com/blog/entry/82208
https://cses.fi/problemset/task/1704/
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long 
const int N=1e5+5;
vector<int> v[N];
int n,tot=0;
int centroid,sz;
vector<int> l[N];


int dfs(int node,int p)
{
  int ct=0,mx=0;
  for(auto i:v[node])
  {
    if(i!=p)
    {
      int x=dfs(i,node);
      mx=max(mx,x);
      ct+=x;
    }
  }
  mx=max(mx,tot-ct);
  if(mx<sz)
  {
    sz=mx;
    centroid=node;
  }
  if(v[node].size()==1)
  {
    ct++;
  }
  return ct;
}

vector<int> tmp;
void dfs2(int node,int p)
{
  for(auto i:v[node])
    if(i!=p)
      dfs2(i,node);

  if(v[node].size()==1)
    tmp.push_back(node);
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 cin>>n;
 int x,y;
 for(int i=1;i<n;i++)
 {
  cin>>x>>y;
  v[x].push_back(y);
  v[y].push_back(x);
 } 
 centroid=1;
 sz=n+1;
 for(int i=1;i<=n;i++)
 {
  if(v[i].size()==1)
    tot++;
 }


 x=dfs(1,-1);


 priority_queue<array<int,2>> q;
 int j=0;
 for(auto i:v[centroid])
 {
  tmp.clear();
  dfs2(i,centroid);
  l[j]=tmp;
  q.push({tmp.size(),j});
  ++j;
 }

 vector<array<int,2>> ans;

 while(q.size()>1)
 {
  auto a=q.top();
  q.pop();
  auto b=q.top();
  q.pop();

  ans.push_back({l[a[1]].back(),l[b[1]].back()});
  l[a[1]].pop_back();
  l[b[1]].pop_back();
  if(a[0]>1)
    q.push({a[0]-1,a[1]});
  if(b[0]>1)
    q.push({b[0]-1,b[1]});
 }

 if(q.size()==1)
 {
    auto a=q.top();
    q.pop();
    ans.push_back({l[a[1]].back(),centroid});
 }

 cout<<ans.size()<<endl;
 for(auto i:ans)
 {
  cout<<i[0]<<" "<<i[1]<<endl;
 }


}
