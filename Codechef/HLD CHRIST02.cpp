#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,c=1;
vector<vector<int>> v,dp;
vector<int> sz,dis,par,depth,chain;
vector<array<int,2>> val;
vector<int> bit[101000];
int mxn=(int)1e5+5;
void update(int i,int val)
{
    for(;i<mxn;i+=(i&(-i)))
    {
        bit[i].push_back(val);
    }
}

int get(int node,int l,int r)
{
    int x=0;
    for(;node>0;node-=(node&(-node)))
    {
         auto it=lower_bound(bit[node].begin(),bit[node].end(),r+1)-lower_bound(bit[node].begin(),bit[node].end(),l);
         x+=it;
    }
    return x;
}

void dfs(int node,int p,int tm,int d)
{
    par[node]=p;
    depth[node]=d;
    sz[node]=1;
    for(auto i:v[node])
    {
        if(i!=p)
        {
            dfs(i,node,tm+1,d+1);
            sz[node]+=sz[i];
        }
    }
}
void precompute()
{
    for(int i=1;i<=n;i++)
    dp[i][0]=par[i];
    for(int h=1;h<=18;h++)
    {
        for(int i=1;i<=n;i++)
        {
          dp[i][h]=dp[dp[i][h-1]][h-1]; 
        }
    }
}

int LCA(int a,int b)
{
    if(depth[a]<depth[b])
    swap(a,b);
    while(depth[a]!=depth[b])
    {
        int d=depth[a]-depth[b];
        int step=log2(d);
        a=dp[a][step];
    }
    while(a!=b)
    {
        int x=log(depth[a]);
        while(x>0&&dp[a][x]==dp[b][x])
        {
            x--;
        }
        a=dp[a][x];
        b=dp[b][x];
    }
    //cout<<a<<" "<<b<<endl;
    return a;
}
int ct=0;
void dfs2(int node,int p,int id)
{
   ct++;
   chain[node]=id;
   dis[node]=ct;
   int x=0,y=-1;
   for(auto i:v[node])
   {
       if(i==p)
       continue;
       if(x<sz[i])
       {
           x=sz[i];
           y=i;
       }
   }
   if(y!=-1)
   {
       dfs2(y,node,id);
   }
   
   for(auto i:v[node])
   {
       if(i==p||i==y)
       continue;
       dfs2(i,node,i);
   }
}
int range(int x,int y,int l,int r)
{
    return get(y,l,r)-get(x-1,l,r);
}
int query(int u,int v,int l,int r)
{
    int x=0,lca=LCA(u,v);
    while(chain[lca]!=chain[u])
    {
        x+=range(dis[chain[u]],dis[u],l,r);
        u=par[chain[u]];
    }
    x+=range(dis[lca],dis[u],l,r);
    
    while(chain[lca]!=chain[v])
    {
        x+=range(dis[chain[v]],dis[v],l,r);
        v=par[chain[v]];
    }
    x+=range(dis[lca],dis[v],l,r);
    x-=range(dis[lca],dis[lca],l,r);
    return x;
}

signed main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int q,x,y;
	cin>>n>>q;
	dp=vector<vector<int>>(n+1,vector<int>(20));
	depth=vector<int>(n+1);
	par=vector<int>(n+1);
	dis=vector<int>(n+1);
	chain=vector<int>(n+1);
	sz=vector<int>(n+1);
	val=vector<array<int,2>>(n+1);
	v=vector<vector<int>>(n+1);
	for(int i=1;i<=n;i++){
	cin>>val[i][0];
	val[i][1]=i;
	}
	
	for(int i=1;i<n;i++)
	{
	    cin>>x>>y;
	    v[x].push_back(y);
	    v[y].push_back(x);
	}
	dfs(1,0,1,1);
	dfs2(1,0,1);
	precompute();
    sort(val.begin()+1,val.end());
    for(int i=1;i<=n;i++)
    {
        update(dis[val[i][1]],val[i][0]);
    }
    int last=0;
    int u,v,l,r,ans;
    while(q--)
    {
        cin>>x>>y>>l>>r;
         u=(x^last)%n+1;
         v=(y^last)%n+1;
        ans=query(u,v,l,r);
        last=ans;
        cout<<ans<<endl;
    }
   
	return 0;
}
