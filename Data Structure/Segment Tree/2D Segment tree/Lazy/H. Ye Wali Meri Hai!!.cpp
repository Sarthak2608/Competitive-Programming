/*
 Sarthak Jain
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
int n,a[N],tm1;
vector<int> val(N),st(N),en(N),v[N],bit(4*N),block(4*N);



void dfs(int node,int p)
{
    st[node]=++tm1;
    val[tm1]=a[node];
    for(auto i:v[node])
    {
        if(i==p)
            continue;
        dfs(i,node);
    }
    en[node]=tm1;
}

void build(int id,int l,int r)
{
    if(l==r)
    {
        bit[id]=val[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    bit[id]=max(bit[2*id],bit[2*id+1]);

}


void update(int id,int l,int r,int L,int R,int delta)
{
    if(R<l||r<L){
        return;
    }
    if(L<=l&&r<=R)
    {
        block[id]+=delta;
        if(block[id]>0)
        {
            bit[id]=-1;
        }
        else
        {
            if(l==r)
            {
                bit[id]=val[l];
            }
            else
            {
                bit[id]=max(bit[2*id],bit[2*id+1]);
            }
        }
        return;
    }
    int mid=(l+r)/2;
    update(2*id,l,mid,L,R,delta);
    update(2*id+1,mid+1,r,L,R,delta);
    if(block[id]==0)
    bit[id]=max(bit[2*id],bit[2*id+1]);
}


int get(int id,int l,int r,int L,int R)
{
    if(L>R||R<l||r<L||bit[id]==-1){
        return -1;
    }

    if(L<=l&&r<=R)
    {
        return bit[id];
    }
    int mid=(l+r)/2;
    int ans=max(get(2*id,l,mid,L,R),get(2*id+1,mid+1,r,L,R));
    return ans;
}


signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int q,x,y;
 cin>>n>>q;

 for(int i=1;i<=n;i++)
 {
    cin>>a[i];
 }
 
 for(int i=1;i<n;i++)
 {
    cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
 }
 tm1=0;
 dfs(1,-1);
 build(1,1,tm1);

 while(q--)
 {
    int k;
    cin>>k;
    int ar[k+1];
    for(int i=1;i<=k;i++)
    {
        cin>>ar[i];
    }
    for(int i=2;i<=k;i++)
    {
        update(1,1,tm1,st[ar[i]],en[ar[i]],1);
    }
    int ans=get(1,1,tm1,st[ar[1]]+1,en[ar[1]]);
    
    cout<<ans<<endl;
    for(int i=2;i<=k;i++)
    {
        update(1,1,tm1,st[ar[i]],en[ar[i]],-1);
    }
 }




}


/*
8 4
2 20 4 5 4 10 4 8
1 2
1 3
3 4
4 7
4 8
2 5
2 6
1 4
3 4 1 8
3 4 2 6
2 1 2

*/
