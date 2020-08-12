/*
https://cses.fi/problemset/task/1740/
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


const int N=2e6+5;

vector<array<int,2>> qr[N],v[N];
const int d=1e6;
int bit[N]={0};
void add(int node,int x)
{
    node++;
    for(;node<N;node+=node&(-node))
        bit[node]+=x;
}
int get(int node){
    node++;
    int x=0;
    for(;node>0;node-=node&(-node)){
        x+=bit[node];
    }
    return x;
}

void solve()
{
    int n,x1,x2,y1,y2;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        if(x1==x2){
            if(y1>y2)
                swap(y1,y2);
            qr[x1+d].push_back({y1+d,y2+d});
        }
        else{
            v[x1+d].push_back({y1+d,1});
            v[x2+d].push_back({y2+d,-1});
        }
    }    
    int ans=0;
    for(int i=0;i<=2*d;i++)
    {
        for(auto j:v[i]){
            if(j[1]==1)
           add(j[0],1);
        }
        for(auto j:qr[i]){
            int x=get(j[1])-get(j[0]-1);
            ans+=x;
        }
        for(auto j:v[i]){
            if(j[1]==-1)
           add(j[0],-1);
        }
    }
    cout<<ans<<endl;
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
