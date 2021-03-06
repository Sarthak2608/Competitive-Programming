/*
https://cses.fi/problemset/task/1684/
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
 
vector<vector<int>> v(N),v2(N);
vector<int> ord,col(N),indeg(N),vis(N);
int n,cnt;
 
  
 
void init(int n1)
{
  n=n1;
  cnt=0;
}
 
void init2()
{
  ord.clear();
  for(int i=0;i<n;i++)
  {
    v[i].clear();
    v2[i].clear();
    indeg[i]=0;
    col[i]=0;
    vis[i]=0;
  }
}
 
void add_edge(int x,int y)
{
  v[x].push_back(y);
  v2[y].push_back(x);
}
 
 
void dfs(int node)
{
  vis[node]=1;
  for(auto i:v[node])
  {
    if(!vis[i])
      dfs(i);
  }
  ord.push_back(node);
}
 
void dfs1(int node)
{
  vis[node]=1;
  col[node]=cnt;
  for(auto i:v2[node])
  {
    if(!vis[i])
    {
      dfs1(i);
    }
  }
}
 
void solve()
{
     for(int i=0;i<n;i++)
     {
      if(!vis[i])
      {
        dfs(i);
      }
     }

     for(int i=0;i<n;i++) vis[i]=0;
    
     reverse(ord.begin(),ord.end());
     for(auto i:ord)
     {
     
      if(!vis[i])
      {
        cnt++;
        dfs1(i);
      }
     }
}
 
void add_or(int x,int y)
{
  add_edge(x^1,y);
  add_edge(y^1,x);
}
 
void add_xor(int x,int y)
{
    add_or(x,y);
    add_or(x^1,y^1);
}
 
void add_force(int x)
{
  add_edge(x^1,x);
}
 
int deg[N],ans[N];
 
 
signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
int t;
t=1;
int tt=1;
while(t--)
{
 
 int n1,m,x,y;
 cin>>m>>n1;

 for(int i=1;i<=n1;i++)
 {
  deg[i]=0;
 }
 
 init(2*n1);
 init2();
 char ch1,ch2;
 for(int i=1;i<=m;i++)
 {
  cin>>ch1>>x>>ch2>>y;
  x--;
  y--;
  deg[x]++;
  deg[y]++;

  x=2*x;
  y=2*y;

  if(ch1=='-')
    x^=1;
  if(ch2=='-')
    y^=1;
  add_or(x,y);

 }
 for(int i=0;i<n1;i++)
 {
    if(deg[i]==0)
    {
        add_force(2*i);
    }
 }
 
 

 solve();
 int f=1;
 
  
 for(int i=0;i<n1;i++)
 {
  int node=2*i;
  if(col[node]==col[node^1])
  {
    f=0;
    break;
  }
  else if(col[node]>col[node^1])
  {
      ans[i]=1;
  }
  else 
  {
      ans[i]=0;
  }
 }
 
if(!f)
{
  cout<<"IMPOSSIBLE\n";
  continue;
}



//print color of each node
if(f){ 
 for(int i=0;i<n1;i++)
 {
  char ch='+';
  if(ans[i]==0)
  {
    ch='-';
  }
    cout<<ch<<" ";
  
 }
 cout<<endl;
}

 
 
 }
 
 
}
 
/*
 
 
*/  
