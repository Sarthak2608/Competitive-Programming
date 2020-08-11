/*
https://cses.fi/problemset/task/1701/
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
 
 
 
const int N=2e5+100;
vector<int> v[N],lvl[N];
int par[N],id[N];
int h[N],mxh;
 
void dfs(int node,int p=-1,int l=0)
{
    par[node]=p;
    h[node]=l;
    for(auto i:v[node])
    {
        if(i!=p)
        {
            dfs(i,node,l+1);
        }
    }
    mxh=max(mxh,h[node]);
    lvl[l].push_back(node);
}
 
bool isomorphism(int root,int a,int b,int n)
{
    //check subtree at a and b are same or not
    for(int i=0;i<=n;i++)
    {
        h[i]=0;
        lvl[i].clear();
        par[i]=0;
    }
    mxh=0;
 
    dfs(root,-1);
    if(h[a]!=h[b])
        return false;
    for(int l=mxh;l>0;l--)
    {
        int x=0,y=0;
        map<vector<int>,int> mp;
        for(auto i:lvl[l])
        {
            vector<int> cur;
            for(auto j:v[i])
            {
                if(j!=par[i])
                    cur.push_back(id[j]);
            }
            sort(cur.begin(),cur.end());
            auto it=mp.find(cur);
            if(it==mp.end())
            {
                mp[cur]=++x;
                id[i]=x;
            }
            else
            id[i]=it->second;
            y^=id[i];
        }
        if(y!=0) //in isomorphic all will have even parity
            return false;

    }
    //cout<<a<<" "<<b<<endl;
    return (id[a]==id[b]);
 
}
 
void solve()
{
    int n,x,y,a,b;
    cin>>n;
 
    for(int i=1;i<=2*n+1;i++)
    {
        lvl[i].clear();
        id[i]=0;
        v[i].clear();
    }
 
    int delta=0;
    
 
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        x+=delta;
        y+=delta;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int mx=0;
    vector<int> centroid1,centroid2;
    for(int i=1;i<=n;i++)
    {
        if(mx<v[i].size())
        {
            mx=v[i].size();
            centroid1.clear();
        }
        if(mx==v[i].size())
            centroid1.push_back(i);
    }
 
 
 
    delta+=n;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        x+=delta;
        y+=delta;
        v[x].push_back(y);
        v[y].push_back(x);
    }
 
 
    mx=0;
    for(int j=1,i=delta+j;j<=n;j++,i++)
    {
        if(mx<v[i].size())
        {
            mx=v[i].size();
            centroid2.clear();
        }
        if(mx==v[i].size())
            centroid2.push_back(i);
    }
 
 
    if(centroid1.size()!=centroid2.size())
    {
        cout<<"NO\n";
        return;
    }
 
    for(auto i:centroid1)
    {
        for(auto j:centroid2)
        {
            int root=2*n+1;
            v[root].push_back(i);
            v[i].push_back(root);
            v[root].push_back(j);
            v[j].push_back(root);
            if(isomorphism(root,i,j,2*n+1))
            {
                cout<<"YES\n";
                return;
            }
 
            v[root].pop_back();
            v[i].pop_back();
            v[root].pop_back();
            v[j].pop_back();
        }
        break;
    }
    cout<<"NO\n";
 
 
}
 
signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 srand(time(0));
 int t;
 cin>>t;
 for(int i=1;i<=t;i++)
 {
   solve();
 }
 
 
}
