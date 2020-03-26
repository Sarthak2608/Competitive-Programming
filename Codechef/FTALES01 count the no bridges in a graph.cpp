#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<array<int,2>>> v;
vector<int> dis,low,vis;
int ans=0;
void dfs(int node,int tm,int p)
{
   // cout<<node<<endl;
    dis[node]=tm;  //discovery time of the node
    low[node]=tm;   //stores the lowest disovered reachable node through the child
    for(auto i:v[node])
    {
       if(i[0]==p)
           continue;
       if(!dis[i[0]])
       {
           dfs(i[0],tm+1,node);
           low[node]=min(low[node],low[i[0]]);
           if(low[i[0]]>dis[node]){
             if(i[1])
             ans++;
           }
       }
       else{
           low[node]=min(low[node],dis[i[0]]);
       }
    }
}

int main() {
    cin>>n>>m;
    v=vector<vector<array<int,2>>>(n+1);
    vis=vector<int>(n+1);
    dis=vector<int>(n+1);
    low=vector<int>(n+1);
    vector<array<int,3>> q(m);
    for(int i=0;i<m;i++)
    {
        cin>>q[i][0]>>q[i][1];
        q[i][2]=0;
    }
    int x,y;
    cin>>x;
    for(int i=1;i<=x;i++)
    {
        cin>>y;
        q[y-1][2]=1;
    }
    for(auto i:q)
    {
        v[i[0]].push_back({i[1],i[2]});
        v[i[1]].push_back({i[0],i[2]});
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        dfs(i,1,i);
    }
    cout<<ans;
	return 0;
}
