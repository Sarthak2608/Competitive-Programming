/*
https://www.geeksforgeeks.org/hierholzers-algorithm-directed-graph/
https://cses.fi/problemset/task/1691/
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ar array<int,2>
#define inf 1000000000000000000 
int mod=1e9+7;
int min(int a,int b){return (a<b)?a:b;}
int max(int a,int b){return (a>b)?a:b;}
int fp(int a,int b){if(b==0) return 1;int x=fp(a,b/2);x=(x*x)%mod;if(b&1) x=(x*a)%mod;return x;}


const int N=2e5+5;
vector<array<int,2>> v[N];

vector<int> ans,vis(N);
int ct=0;

void dfs(int node,int p=-1)
{
//    cout<<node<<endl;
    while(v[node].size()>0)
    {
        if(vis[v[node].back()[1]]){
            v[node].pop_back();
            continue;
        }
        int i=v[node].back()[0];
        int eid=v[node].back()[1];
        vis[eid]=1;
        ct++;
        dfs(i,node);
    }
    ans.push_back(node);
}


void solve()
{
    ct=0;
    int n,m,x,y;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        v[x].push_back({y,i});
        v[y].push_back({x,i});
    }   
    for(int i=1;i<=n;i++)
    {
        if(v[i].size()%2)
        {
            cout<<"IMPOSSIBLE";
            return ;
        }
    }
    dfs(1);
    if(ct!=m)
    {
        cout<<"IMPOSSIBLE";
        return;
    }
    for(auto i:ans)
        cout<<i<<" ";
    
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 srand(time(0));
 int t;
 t=1;
 for(int i=1;i<=t;i++)
 {
   solve();
 }


}
