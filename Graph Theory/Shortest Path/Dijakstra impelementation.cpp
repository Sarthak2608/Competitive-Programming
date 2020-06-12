/*
https://cses.fi/problemset/task/1195/
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

const int N=2e5+5;
vector<array<int,2>> v[N];
vector<array<int,3>> edges;
vector<int> dis,vis;
int n;
void dijakstra(int src)
{
    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> q;
    q.push({0,src});
    dis=vector<int>(n+1,1e18);
    vis=vector<int>(n+1);
    dis[src]=0;
    while(!q.empty())
    {
        int node=q.top()[1];
        q.pop();
        if(vis[node])
            continue;
        vis[node]=1;
        for(auto i:v[node])
        {
            if(dis[node]+i[1]<dis[i[0]])
            {
                dis[i[0]]=dis[node]+i[1];
                q.push({dis[i[0]],i[0]});
            }
        }
    }
}


signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 int m,x,y,w;
 cin>>n>>m;
 for(int i=1;i<=m;i++)
 {
    cin>>x>>y>>w;
    v[x].push_back({y,w});
}
dijakstra(1);
auto a=dis;


for(int i=1;i<=n;i++)
{
    cout<<dis[i]<<" ";
}

}
