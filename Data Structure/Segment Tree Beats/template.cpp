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


const int N=2e5+5;
int n;
int a[N];

struct node
{
  int sum,mx,mn,p;
  node(){
    sum=0;
    p=-1;
  }
};
vector<node> bit(4*N);

node merge(node a,node b)
{
  node c;
  c.mx=max(a.mx,b.mx);
  c.mn=min(a.mn,b.mn);
  c.sum=a.sum+b.sum;
  c.p=-1;
  return c;
}

void prop(int id,int l,int r)
{
  if(bit[id].p==-1)
    return ;

  bit[2*id].mx=bit[id].p;
  bit[2*id].mn=bit[id].p;
  bit[2*id].p=bit[id].p;


  bit[2*id+1].mx=bit[id].p;
  bit[2*id+1].mn=bit[id].p;
  bit[2*id+1].p=bit[id].p;


  int mid=(l+r)/2;

  bit[2*id].sum=(mid-l+1)*bit[id].p;
  bit[2*id+1].sum=(r-(mid+1)+1)*bit[id].p;

  bit[id].p=-1;
}
 
void build(int id,int l,int r)
{
  if(l==r)
  {
      bit[id].sum=a[l];
      bit[id].mx=a[l];
      bit[id].mn=a[l];
      return;
  }
  int mid=(l+r)/2;
  build(2*id,l,mid);
  build(2*id+1,mid+1,r);
  bit[id]=merge(bit[2*id],bit[2*id+1]);
}

 
//can use it to max,sum,min
int getmax(int id,int l,int r,int L,int R)
{
  if(R<l||r<L){
    return 0;
  }
  if(L<=l&&r<=R)
  {
    return bit[id].mx;
  }
  prop(id,l,r);
  int mid=(l+r)/2;
  return max(getmax(2*id,l,mid,L,R),getmax(2*id+1,mid+1,r,L,R));
}
 

 
void upd(int id,int l,int r,int L,int R,int v)
{
  if(R<l||r<L||bit[id].mn>=v)
    return;
  if(L<=l&&r<=R)
  {

    if(bit[id].mx<=v)
    {
      bit[id].mx=v;
      bit[id].mn=v;
      bit[id].p=v;
      bit[id].sum=v*(r-l+1);
      return ;
    }

  }
  int mid=(l+r)/2;
  prop(id,l,r);
  upd(2*id,l,mid,L,R,v);
  upd(2*id+1,mid+1,r,L,R,v);
  bit[id]=merge(bit[2*id],bit[2*id+1]);
}
 


 
void solve()
{
  int q;
  cin>>n>>q;
  for(int i=1;i<=n;i++)
  cin>>a[i];
  build(1,1,n); 

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
