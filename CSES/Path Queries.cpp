/*
https://cses.fi/problemset/task/1138
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

 
const int N=2e5+5;
vector<int> v[N],lvl(N),cpy(N),par(N),st(N),en(N),val(N),inv(N);
int n,q,tm1;
int bit[4*N]={0};
 
void dfs(int node,int l=0,int p=0)
{
    lvl[node]=l;
    par[node]=p;
    st[node]=++tm1;
    inv[tm1]=node;
    for(auto i:v[node])
    {
        if(i!=p){
        val[i]+=val[node];
        dfs(i,l+1,node);
        }
    }
    en[node]=tm1;
}
 
void propagate(int id)
{
    bit[2*id]+=bit[id];
    bit[2*id+1]+=bit[id];
    bit[id]=0;
}

void update(int id,int l,int r,int L,int R,int x)
{
    if(r<L||R<l)
        return;

    if(L<=l&&r<=R)
    {
        bit[id]+=x;
        return;
    }
    int mid=(l+r)/2;
    propagate(id);
    update(2*id,l,mid,L,R,x);
    update(2*id+1,mid+1,r,L,R,x);
}
 
int get(int id,int l,int r,int pos)
{
    if(l==r)
    {
        return bit[id]+val[inv[l]];
    }
    
    int mid=(l+r)/2;
    propagate(id);
    if(pos<=mid)
    return get(2*id,l,mid,pos);
    else
    return get(2*id+1,mid+1,r,pos);
}
 
signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int x,y;
 cin>>n>>q;
 for(int i=1;i<=n;i++)
 {
    cin>>val[i];
    cpy[i]=val[i];
 }
 for(int i=2;i<=n;i++)
 {
    cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
 }
 tm1=0;
 dfs(1);

 while(q--)
{
    int typ,s;
    cin>>typ;
    if(typ==1)
    {
        cin>>s>>x;
        update(1,1,tm1,st[s],en[s],x-cpy[s]);
        cpy[s]=x;
    }
    else
    {
        cin>>s;
        cout<<get(1,1,tm1,st[s])<<endl;
    }
}
 
}
