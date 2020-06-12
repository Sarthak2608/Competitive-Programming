/*
https://cp-algorithms.com/graph/finding-negative-cycle-in-graph.html#toc-tgt-2
https://cses.fi/problemset/task/1197/
https://www.youtube.com/watch?v=LwJdNfdLF9s
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
vector<int> dis,par;
int inf=1e18;
int n;

void cycle()
{
    int x;
    dis=vector<int>(n+1,inf);
    par=vector<int>(n+1,-1);
    int src=1;
    dis[src]=0;

    for(int i=1;i<=n;i++)
    {
        x=-1;  //last updated node
        for(auto j:edges)
        {
            int to=j[1];
            int from=j[0];
            int w=j[2];

            if(dis[from]+w<dis[to])
            {
                dis[to]=dis[from]+w;
                x=to;
                par[to]=from;
            }
        }
    }
    if(x==-1)
    {
       cout<<"NO";
       return;
    }

    cout<<"YES\n";
    //graph contains -ve cycle then if we trace the path of last node then it goes
    // to negative cycle 

    for(int i=1;i<=n;i++)
    x=par[x];

    //now last is the node which is present in -ve cycle   
    vector<int> cycle;
    for(int i=x;;i=par[i])
    {
        cycle.push_back(i);
        if(i==x&&cycle.size()>1)
            break;
    }
    reverse(cycle.begin(),cycle.end());
    for(auto i:cycle)
        cout<<i<<" ";
    return;

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
    v[y].push_back({x,w});
 }
cycle();


}
