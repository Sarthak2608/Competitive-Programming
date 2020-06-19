/*
https://cses.fi/problemset/task/1196
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
int fp(int a,int b){
    if(b==0) return 1;
    int x=fp(a,b/2);
    x=(x*x)%mod;
    if(b&1) x=(x*a)%mod;
    return x;
}
const int N=2e5+5;
vector<array<int,2>> v[N];
vector<int> vis(N),par(N),tmp(N),mark(N);
 
signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int n,m,x,y,k,w;
 cin>>n>>m>>k;
 
 for(int i=1;i<=m;i++)
 {
    cin>>x>>y>>w;
    v[x].push_back({y,w});
}
 
priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> q;
q.push({0,1});
vis[1]=0;
 
vector<int> ans;
 
while(1)
{
    int node=q.top()[1];
    int d=q.top()[0];
    q.pop();
    vis[node]++;
 
    if(node==n)
    {
        ans.push_back(d);
        if(ans.size()==k)
        {
            break;
        }
    }
 
    if(vis[node]>k)
      continue;

 
    
    for(auto i:v[node])
    {
        if(vis[i[0]]<k){
        q.push({i[1]+d,i[0]});
        }
    }
}
 
 for(auto i:ans)
    cout<<i<<" ";
 
 
 
}
