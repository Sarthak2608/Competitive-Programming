/*
https://codeforces.com/contest/1076/problem/E
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
const int N=3e5+5;
vector<vector<int>> v(N);
vector<vector<array<int,2>>> qr(N);
int n,m;
int pref[N]={0},ans[N]={0};

void dfs(int node,int p,int sum,int l)
{

  for(auto i:qr[node])
  {
      pref[l]+=i[0];
      if(i[1]+l+1<N)
      {
         pref[i[1]+l+1]-=i[0];
      }
  }
  sum+=pref[l];
  ans[node]=sum;

  for(auto i:v[node])
  {
    if(i==p)
      continue;
    dfs(i,node,sum,l+1);
  }

  for(auto i:qr[node])
  {
      pref[l]-=i[0];
      if(i[1]+l+1<N)
      {
         pref[i[1]+l+1]+=i[0];
      }
  }

}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

 int x,y,v1,x1,d1;
 cin>>n;
 for(int i=1;i<n;i++)
 {
    cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
 }
 cin>>m;
 for(int i=1;i<=m;i++)
 {
  cin>>v1>>d1>>x1;
  qr[v1].push_back({x1,d1});
 }
 dfs(1,-1,0,0);
 for(int i=1;i<=n;i++)
 {
  cout<<ans[i]<<" ";
 }
return 0;
}
