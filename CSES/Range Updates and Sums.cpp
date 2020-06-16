/*
https://cses.fi/problemset/task/1735
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
int bit1[4*N]={0},a[N],bit2[4*N]={0},sm[4*N];
 
void build(int id,int l,int r)
{
    if(l==r)
    {
        sm[id]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    sm[id]=sm[2*id]+sm[2*id+1];
}
 
void propagete1(int id,int l,int r)
{
    bit1[2*id]+=bit1[id];
    bit1[2*id+1]+=bit1[id];
  
    int mid=(l+r)/2;
    sm[2*id]+=(mid-l+1)*bit1[id];
    sm[2*id+1]+=(r-mid)*bit1[id];
      bit1[id]=0;

}

void propagete2(int id,int l,int r)
{
    int mid=(l+r)/2;
    if(bit2[id]>0)
    {
        sm[2*id]=(mid-l+1)*bit2[id];
        sm[2*id+1]=(r-mid)*bit2[id];
        
        bit1[2*id]=0;
        bit2[2*id]=bit2[id];
        bit1[2*id+1]=0;
        bit2[2*id+1]=bit2[id];

        bit2[id]=0;
    }
}
 


int get(int id,int l,int r,int L,int R)
{
    if(R<l||r<L)
        return 0;
    if(L<=l&&r<=R){
        return sm[id];
    }
    propagete2(id,l,r);
    propagete1(id,l,r);
    int mid=(l+r)/2;
    return get(2*id,l,mid,L,R)+get(2*id+1,mid+1,r,L,R);
}



void update1(int id,int l,int r,int L,int R,int val)
{
    if(R<l||r<L)
        return;
    if(L<=l&&r<=R){
        bit1[id]+=val;
        sm[id]+=(r-l+1)*val;
        return;
    }
    propagete2(id,l,r);
    propagete1(id,l,r);
    int mid=(l+r)/2;
    update1(2*id,l,mid,L,R,val);
    update1(2*id+1,mid+1,r,L,R,val);
    sm[id]=sm[2*id]+sm[2*id+1];
}


void update2(int id,int l,int r,int L,int R,int val)
{
    if(R<l||r<L)
        return;
    if(L<=l&&r<=R){
        bit2[id]=val;
        bit1[id]=0;
        sm[id]=val*(r-l+1);
        return;
    }
    propagete2(id,l,r);
    propagete1(id,l,r);
    int mid=(l+r)/2;
    update2(2*id,l,mid,L,R,val);
    update2(2*id+1,mid+1,r,L,R,val);
    sm[id]=sm[2*id]+sm[2*id+1];
}
 

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int n,q,x,y,typ,v;
 cin>>n>>q;
 
 for(int i=1;i<=n;i++)
 {
    cin>>a[i];
 }
 build(1,1,n);
 for(int i=1;i<=q;i++)
 {
    cin>>typ;
    if(typ==1){
        cin>>x>>y>>v;
        update1(1,1,n,x,y,v);
    }
    else if(typ==2)
    {
        cin>>x>>y>>v;
        update2(1,1,n,x,y,v);
    }
    else{
        cin>>x>>y;
    cout<<get(1,1,n,x,y)<<endl;
    }
 }
 
 
 }

 /*

5 7
2 3 1 4 5
3 1 5
2 1 5 1
3 1 5
1 1 3 2
3 1 5 
2 4 5 10
3 1 5

 */
