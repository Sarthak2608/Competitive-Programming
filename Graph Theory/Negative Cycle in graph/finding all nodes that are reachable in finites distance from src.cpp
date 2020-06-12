/*
https://cses.fi/problemset/task/1673/
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


const int N=5005;
vector<array<int,2>> v[N];
vector<array<int,3>> edges;
vector<int> dis,par,mark,vis;
int inf=1e18;
int n;

void dfs(int node,int p)
{
    vis[node]=1;
    mark[node]=1;
    for(auto i:v[node])
    {
        if(i[0]!=p&&!vis[i[0]])
        dfs(i[0],node);
    }
}

void cycle()
{
    int x;
    vis=vector<int>(n+1);
    mark=vector<int>(n+1);
    dis=vector<int>(n+1,inf);
    par=vector<int>(n+1,-1);
    int src=1;
    dis[src]=0;
    for(int i=1;i<n;i++)
    {
        for(auto j:edges)
        {
            int to=j[1];
            int from=j[0];
            int w=j[2];

            if(dis[from]!=inf&&(dis[from]+w>dis[to]||dis[to]==inf))
            {
                dis[to]=dis[from]+w;
                par[to]=from;
            }
        }
    }


    
    for(int i=1;i<n;i++)
    {
        for(auto j:edges)
        {
            int to=j[1];
            int from=j[0];
            int w=j[2];

            if(dis[from]!=inf&&(dis[from]+w>dis[to]||dis[to]==inf))
            {
                mark[to]=1;  //bad nodes
                dis[to]=dis[from]+w;
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(mark[i]&&!vis[i])
        {
            dfs(i,-1);
        }
    }

    if(mark[n])
    {
        cout<<-1;
        return;
    }


       cout<<dis[n];
  
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 int m,x,y,w;
 cin>>n>>m;
 for(int i=1;i<=m;i++)
 {
    cin>>x>>y>>w;
    edges.push_back({x,y,w});
   
    v[x].push_back({y,w});
}
cycle();


}
