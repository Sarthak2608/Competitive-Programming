#include <bits/stdc++.h>
using namespace std;
int n,u,x,v,n1;
vector<vector<int>> adj,dp;  //dp[log2(n)][n]
vector<int> vis,level,parent;
void dfs(int node,int l,int p)
{
    vis[node]=1;
    level[node]=l;
    parent[node]=p;
    for(auto child:adj[node])
    {
        if(!vis[child])
        {
            dfs(child,l+1,node);
        }
    }
}

void findAncestors()
{
    for(int i=1;i<=n;i++)
    dp[0][i]=parent[i];

    for(int i=1;i<n1;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=dp[i-1][dp[i-1][j]];
        }
    }
}

void findCommonAncestor(int u,int v)
{
    int jump;
    if(level[u]<level[v])
    {
        swap(u,v);
    }
    int d=level[u]-level[v];
    while(d>0)
    {
        jump=log2(d);
        u=dp[jump][u];
        d-=(1ll<<jump);
    }

    
    while(u!=v)
    {
        int temp=log2(level[u]);
        while(temp>0&&dp[temp][u]==dp[temp][v])
        {
            temp--;
        }
        u=dp[temp][u];
        v=dp[temp][v];
    }
    cout<<u<<endl;
    
}

int main() {
  int t,tt=1;
  cin>>t;
  while(t--)
  {
      cout<<"Case "<<tt<<":"<<endl;
      tt++;
      cin>>n;
      n1=log2(n)+2;
      dp=vector<vector<int>>(n1+1,vector<int>(n+1));
      adj=vector<vector<int>>(n+1);
      vis=vector<int>(n+1);
      level=vector<int>(n+1);
      parent=vector<int>(n+1);
      for(int i=1;i<=n;i++)
      {
          cin>>x;
          for(int j=1;j<=x;j++)
          {
              cin>>v;
              adj[i].push_back(v);
              adj[v].push_back(i);
          }
      }
      
      dfs(1,0,0);
      findAncestors();
      int q;
      cin>>q;
      while(q--)
      {
          cin>>u>>v;
          findCommonAncestor(u,v);
      }
  }
  return 0;
}
