/*
  https://codeforces.com/contest/915/problem/D
  
  https://codeforces.com/contest/937/problem/D
  https://codeforces.com/contest/937/submission/76423771
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

const int N=10005;

vector<vector<int>> v(N);
vector<int> vis(N);


int dfs(int node,int p)
{
  vis[node]=1;
  for(auto i:v[node])
  {
    
    if(vis[i]==1)
    {
      return 1;
    }
    else if(vis[i]==0)
    {
       int f1=dfs(i,node);
       if(f1)
       return 1;
    }
  }
  vis[node]=2;
  return 0;
}


int detectCycle(int n)
{
  vis=vector<int>(n+1);
  for(int i=1;i<=n;i++)
  {
    if(vis[i])
      continue;
    int chk=dfs(i,-1);
    if(chk)
      return 1;
  }
  return 0;
}

signed main() {
 int n,m,x,y,cycle;
 cin>>n>>m;

 for(int i=1;i<=m;i++)
 {
    cin>>x>>y;
    v[x].push_back(y);
 }
 cycle=detectCycle(n);
 if(cycle)
 {
  cout<<"YES";
 }
 else{
  cout<<"NO";
 }


}
