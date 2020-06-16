/*
https://cses.fi/problemset/task/1190/
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
int a[N];

struct node
{
    int l,m,r,t;
    node()
    {
        l=0;
        r=0;
        m=0;
        t=0;
    }
};
vector<node> bit(4*N);

void merge(int id)
{
    bit[id].m=max({bit[2*id].m,bit[2*id+1].m,bit[2*id].r+bit[2*id+1].l,bit[2*id].r,bit[2*id+1].l});
    bit[id].l=max(bit[2*id].l,bit[2*id].t+bit[2*id+1].l);
    bit[id].r=max(bit[2*id+1].r,bit[2*id+1].t+bit[2*id].r);
    bit[id].t=bit[2*id].t+bit[2*id+1].t;
} 

void build(int id,int l,int r)
{
    if(l==r)
    {
        bit[id].m=a[l];
        bit[id].l=a[l];
        bit[id].r=a[l];
        bit[id].t=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    merge(id);
}
 



void update(int id,int l,int r,int point,int x)
{
    if(point<l||point>r)
        return;
    if(l==r){
        bit[id].m=x;
        bit[id].l=x;
        bit[id].r=x;
        bit[id].t=x;
        return;
    }
    int mid=(l+r)/2;
    update(2*id,l,mid,point,x);
    update(2*id+1,mid+1,r,point,x);
    merge(id);
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
   cin>>x>>y;
   update(1,1,n,x,y);
   cout<<bit[1].m<<endl;
 }
 
 
 }

 /*


 */
