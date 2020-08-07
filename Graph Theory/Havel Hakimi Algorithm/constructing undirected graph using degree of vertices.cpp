/*
http://szhorvat.net/pelican/hh-connected-graphs.html
https://cses.fi/problemset/task/1697/

pick the highest degree vertex then connect it with other hishest degree vertices

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




const int N=1005;


void solve()
{
    int n;
    cin>>n;
    vector<array<int,2>> edges;
    int deg[n+1]={0};
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
      cin>>a[i];
    }
    priority_queue<array<int,2>> q;
    
    for(int i=1;i<=n;i++)
    {
      if(a[i]>0)
      q.push({a[i],i});
    }

    while(q.size()>1)
    {
      auto node=q.top()[1];
      int d=q.top()[0];
      q.pop();
      vector<array<int,2>> tmp;
      while(d>0&&q.size()>0)
      {
        auto it=q.top();
        q.pop();
        deg[node]++;
        deg[it[1]]++;
        it[0]--;
        d--;
        edges.push_back({node,it[1]});
        if(it[0]>0)
          tmp.push_back(it);
      }
      for(auto i:tmp)
        q.push(i);
    }
    for(int i=1;i<=n;i++)
    {
      if(deg[i]!=a[i])
      {
        cout<<"IMPOSSIBLE";
        return ;
      }
    }
    cout<<edges.size()<<endl;

    for(auto i:edges){
      cout<<i[0]<<" "<<i[1]<<endl;
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
