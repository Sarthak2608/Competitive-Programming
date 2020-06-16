/*
https://cses.fi/problemset/task/1736/
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
int bit[4*N]={0},a[N],bit2[4*N]={0},sz[4*N]={0};

int nthterm(int a,int d,int n)
{
    return (a+(n-1)*d);
}


int sum(int,int,int);
void propagate(int id,int l,int r)
{
    int mid=(l+r)/2;


    bit2[2*id]+=bit2[id];
    sz[2*id]+=sz[id];

    bit2[2*id+1]+=nthterm(bit2[id],sz[id],mid+2-l);
    sz[2*id+1]+=sz[id];
  

    bit[2*id]+=sum(bit2[id],sz[id],mid-l+1);
    bit[2*id+1]+=sum(nthterm(bit2[id],sz[id],mid+2-l),sz[id],r-mid);

    sz[id]=0;
    bit2[id]=0;
} 
 
void build(int id,int l,int r)
{
    if(l==r)
    {
        bit[id]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    bit[id]=bit[2*id]+bit[2*id+1];
}
 
int get(int id,int l,int r,int L,int R)
{
    if(R<l||r<L)
        return 0;
    if(L<=l&&r<=R)
        return bit[id];
    int mid=(l+r)/2;
    propagate(id,l,r);
    return get(2*id,l,mid,L,R)+get(2*id+1,mid+1,r,L,R);
}


// (n/2)*(2*a+(n-1)*d)

int sum(int a,int d,int n)
{
    return (n*(2*a+(n-1)*d))/2;
}

int update(int id,int l,int r,int L,int R,int x)
{
    if(R<l||r<L)
        return 0;
    if(L<=l&&r<=R){
        bit2[id]+=x;
        sz[id]++;
        bit[id]+=sum(x,1,r-l+1);
        return r-l+1;
    }
    propagate(id,l,r);
    int mid=(l+r)/2;
    int y=update(2*id,l,mid,L,R,x);
    int z=update(2*id+1,mid+1,r,L,R,x+y);
    bit[id]=bit[2*id]+bit[2*id+1];
    return y+z; 
}
 
 
signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int n,q,x,y,typ;
 cin>>n>>q;
 
 for(int i=1;i<=n;i++)
 {
    cin>>a[i];
 }
 build(1,1,n);
 for(int i=1;i<=q;i++)
 {
    cin>>typ>>x>>y;
    if(typ==1)
        update(1,1,n,x,y,1);
    else
    cout<<get(1,1,n,x,y)<<endl;
 }
 
 
 }

 /*

5 4
0 0 0 0 0 
1 1 5
2 1 5
1 3 5
2 1 5

 */
