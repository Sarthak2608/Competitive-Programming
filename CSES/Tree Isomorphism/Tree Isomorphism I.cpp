/*
https://cses.fi/problemset/task/1700/
https://github.com/thcy/CSES-Solutions/blob/master/Additional%20Problems/Tree%20Isomorphism%20I%20(1700)/catkl.cpp
https://www.imsc.res.in/~vikram/DiscreteMaths/2011/tree.pdf


traverse level wise and at each level for (subtree at each node) calculate which are similar 

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
vector<int> v[N],lvl[N],id(N),par(N);
int h;

void dfs(int node,int p=-1,int l=0)
{
    par[node]=p;
  //  cout<<node<<" "<<p<<endl;
    for(auto i:v[node])
    {
        if(i!=p)
        {
            dfs(i,node,l+1);
        }
    }
    h=max(h,l);
    lvl[l].push_back(node);
}

bool isomorphism(int root,int a,int b,int n)
{
    //check subtree at a and b are same or not
    for(int i=0;i<=n;i++)
    {
        lvl[i].clear();
        par[i]=0;
    }

    h=0;
    dfs(root,-1);
    for(int l=h;l>=0;l--)
    {
        int x=0;
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
            if(!mp.count(cur))
            {
                mp[cur]=++x;
            }
            id[i]=mp[cur];
        }
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

    int delta=1;
    
    v[1].push_back(2);
    v[2].push_back(1);
    a=2;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        x+=delta;
        y+=delta;
        v[x].push_back(y);
        v[y].push_back(x);
    }


    delta+=n;

    v[1].push_back(delta+1);
    v[delta+1].push_back(1);
    b=delta+1;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        x+=delta;
        y+=delta;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    if(isomorphism(1,a,b,2*n+1))
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }


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
