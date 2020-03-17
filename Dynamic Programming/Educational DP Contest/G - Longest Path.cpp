/*
Finding longest path in a directed acyclic graph
Here dp[i] stores the longest directed path from node i
*/

#include <bits/stdc++.h>
using namespace std;
#define int long
vector<vector<int>> v;
vector<int> vis,dp;
int ans=0;
int dfs(int node)
{
     int x;
     vis[node]=1;
     int mx=0;
     for(auto i:v[node])
     {
          if(!vis[i])
             x=dfs(i);
          mx=max(mx,dp[i]+1);
     }
     ans=max(ans,mx);
     dp[node]=mx;
     return mx;
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int n,m,x,y;
 cin>>n>>m;
 dp=vector<int>(n+1);
 v=vector<vector<int>>(n+1);
 vis=vector<int>(n+1);
 
 for(int i=1;i<=m;i++)
 {
      cin>>x>>y;
      v[x].push_back(y);
 }
 for(int i=1;i<=n;i++){
   if(!vis[i])
   dfs(i);
 }
 cout<<ans;
}
