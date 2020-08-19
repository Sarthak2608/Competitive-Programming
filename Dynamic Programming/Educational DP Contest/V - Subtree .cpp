/*
https://atcoder.jp/contests/dp/tasks/dp_v


a[node] stores the ways which satisfy the condition if node is black 
and it connect through only child

for calculating the req. ans ,re rooting the root of the tree


may be Mod is not a prime so fermat will not work

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define ar array<int,2>
#define inf 1000000000000000000 
int mod=1e9+7;
int min(int a,int b){return (a<b)?a:b;}
int max(int a,int b){return (a>b)?a:b;}
int fp(int a,int b){if(b==0) return 1;int x=fp(a,b/2);x=(x*x)%mod;if(b&1) x=(x*a)%mod;return x;}


const int N=2e5+5;
int n;
vector<int> v[N],a(N),ans(N);

void dfs(int node,int p)
{
    a[node]=1;
    for(auto i:v[node])
    {
        if(i!=p)
        {
            dfs(i,node);
            a[node]*=(a[i]+1);
            if(a[node]>=mod)
            a[node]%=mod;
        }
    }
}

void dfs2(int node,int p,int ways)
{
    ans[node]=((ways+1)*a[node])%mod;
    int n1=v[node].size();
    int pre[n1+1],suf[n1+1];
    for(int i=0;i<n1;i++)
    {
        if(v[node][i]==p)
            pre[i]=1;
        else
            pre[i]=a[v[node][i]]+1;
        if(i>0)
        pre[i]=(pre[i-1]*pre[i])%mod;
    }

    for(int i=n1-1;i>=0;i--)
    {
        if(v[node][i]==p)
            suf[i]=1;
        else
            suf[i]=a[v[node][i]]+1;
        if(i<(n1-1))
            suf[i]=(suf[i+1]*suf[i])%mod;
    }
    int j=0;
    for(auto i:v[node])
    {
        int y=1;
        if(j>0)
            y=pre[j-1];
        if(j+1<n1)
            y=(y*suf[j+1])%mod;
        int nways=y;
        nways=((ways+1)*nways)%mod;
        if(i!=p)
        dfs2(i,node,nways);
        j++;
    }
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 int x,y;
 cin>>n>>mod;
 for(int i=1;i<n;i++)
 {
    cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
 }

 dfs(1,-1);
 dfs2(1,-1,0);
 for(int i=1;i<=n;i++)
    cout<<ans[i]<<endl;


}
