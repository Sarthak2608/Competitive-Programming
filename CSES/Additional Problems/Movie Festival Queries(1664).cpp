/*
idea: if we start at time t then same path will follow for any r
https://cses.fi/problemset/task/1664/
*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ar array<int,2>
#define inf INT_MAX
int mod=1e9+7;
int min(int a,int b){return (a<b)?a:b;}
int max(int a,int b){return (a>b)?a:b;}
int fp(int a,int b){if(b==0) return 1;int x=fp(a,b/2);x=(x*x)%mod;if(b&1) x=(x*a)%mod;return x;}


const int N=1e6+5;
vector<int> v1[N];
vector<int> v[N];
int nxt[N][2];
int child[N],tot[N],dp[21][N];

int dfs1(int node,int b,int x)
{
    if(nxt[node][0]>x)
        return 0;
    for(;b>=0;b--)
    {
        if(dp[b][node]&&nxt[dp[b][node]][1]<=x)
        {
            return (1ll<<b)+dfs1(dp[b][node],b,x);
        }
    }
    return 1;
}


void dfs(int node,int p=-1)
{
    if(child[node])
        return;
    tot[node]=1;
    //cout<<p<<"->"<<node<<endl;
    for(auto i:v[node]){
        child[node]=i;
        dfs(i,node);
        tot[node]+=tot[i];
    }
}


void solve()
{
    memset(tot,0,sizeof(tot));
    memset(child,0,sizeof(child));
    int n,q,x,y;
    cin>>n>>q;

    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        v1[x].push_back(y);
    }
    array<int,2> a={inf,inf};
    for(int i=N-1;i>=1;i--)
    {
        for(auto j:v1[i])
        {
            array<int,2> b={j,i};
            a=min(a,b);
        }
        nxt[i][0]=a[0];
        nxt[i][1]=a[1];
    }

    for(int i=1;i<N;i++)
    {
        if(nxt[i][1]==i){
            int x=nxt[nxt[i][0]][1];
            if(x!=inf)
            v[i].push_back(x);
        }
    } 

    for(int i=1;i<=n;i++)
        dfs(i,-1);

    for(int i=0;i<=20;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(tot[j]>(1ll<<i))
            {
                dp[i][j]=(i==0?child[j]:dp[i-1][dp[i-1][j]]);
            }
        }
    }
    int j=0;
    while(q--)
    {
      
            
        int l,r;
        cin>>l>>r;
        l=nxt[l][1];
        if(l==inf)
        {
            cout<<0<<endl;
            continue;
        }
        int b=log(tot[l])+1;
        int ans=dfs1(l,b,r);
        cout<<ans<<endl;
    }

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
