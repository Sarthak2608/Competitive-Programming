/*
 dp[i][j] ,where  i represents the node and j has two values 0 (for white) and 1(for black)
 dp[i][0] represents the number of ways to paint the subtree where the color of node i is 
 white.
 dp[i][1] represents the number of ways to paint the subtree where the color of node i is 
 black.
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,mod=1e9+7;
vector<vector<int>> v,dp;

void dfs(int node,int par)
{
     int f=1;
     int x=1,y=1;
     for(auto i:v[node])
     {
          if(i!=par){
          f=0;
          dfs(i,node);
          x=(x*(dp[i][0]+dp[i][1]))%mod;
          y=(y*(dp[node][1]+dp[i][0]))%mod;
          }
     }
     if(f==0){
     dp[node][0]=x;
     dp[node][1]=y;
     }
     if(f){              //If the node is leaf node
     dp[node][0]++;
     dp[node][1]++;
     }
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 cin>>n;
 int x,y;
 v=vector<vector<int>>(n+1);
 dp=vector<vector<int>>(n+1,vector<int>(2));
 for(int i=1;i<n;i++)
 {
      cin>>x>>y;
      v[x].push_back(y);
      v[y].push_back(x);
 }
 dfs(1,-1);
 cout<<(dp[1][0]+dp[1][1])%mod;

}
