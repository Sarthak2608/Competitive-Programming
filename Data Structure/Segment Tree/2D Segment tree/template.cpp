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


const int N=1e5+5;
struct node
{
  int x;
}; 
node merge(node a,node b)
{
  node c;
  return c;
}
 
vector<node> bit(4*N);
void build(int id,int l,int r)
{
  if(l==r)
  {
      return;
  }
  int mid=(l+r)/2;
  build(2*id,l,mid);
  build(2*id+1,mid+1,r);
  bit[id]=merge(bit[2*id],bit[2*id+1]);
}

 
node get(int id,int l,int r,int L,int R)
{
  if(R<l||r<L){
    node c;
    return c;
  }
  if(L<=l&&r<=R)
  {
    return bit[id];
  }
  int mid=(l+r)/2;
  return merge(get(2*id,l,mid,L,R),get(2*id+1,mid+1,r,L,R));
}
 
void upd(int id,int l,int r,int L,int R,int v)
{
  if(R<l||r<L)
    return;
  if(L<=l&&r<=R)
  {

    return;
  }
  int mid=(l+r)/2;
  upd(2*id,l,mid,L,R,v);
  upd(2*id+1,mid+1,r,L,R,v);
  bit[id]=merge(bit[2*id],bit[2*id+1]);
}
 
 
void solve()
{
 build(1,1,10);
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
