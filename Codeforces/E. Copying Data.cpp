/*
https://codeforces.com/contest/292/problem/E
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int mod=1e9+7;

const int N=4e5+5;
vector<int> bit(N);

int update(int id,int l,int r,int x,int L,int R,int st)
{
  if(l>R||r<L)
  {
    if(st!=-1)
    {
      bit[id]=st;
    }
    return 0;
  }
  if(L<=l&&r<=R)
  {
    //cout<<l<<" "<<r<<" "<<x<<" "<<L<<" "<<R<<endl;
    bit[id]=x;
    return r-l+1;
  }
  
  if(bit[id]!=0)
  {
    if(st==-1)
    st=bit[id];
    bit[id]=0;
  }

  int mid=(l+r)/2;
  auto y=update(2*id,l,mid,x,L,R,st);
  if(st!=-1)
  {
    st+=mid-l+1;
  }
  auto z=update(2*id+1,mid+1,r,x+y,L,R,st);
  return y+z;
}

int get(int id,int l,int r,int point)
{
   
   if(l<=point&&point<=r)
   {
    if(bit[id]!=0){
      return bit[id]+point-l;
    }
   }
   if(l==point&&r==point)
   {
    return -1;
   }
   int mid=(l+r)/2;
   if(point<=mid)
   {
    return get(2*id,l,mid,point);
   }
   return get(2*id+1,mid+1,r,point);
}


signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 int n,q;
 cin>>n>>q;
 int a[n+1],b[n+1];
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  //a[i]=rand()%n;
 }
 for(int i=1;i<=n;i++)
 {
  cin>>b[i];

 }
 
 int typ,x,y,k;
 while(q--)
 {
    cin>>typ;
    if(typ==1)
    {
      cin>>x>>y>>k;
      auto it=update(1,1,n,x,y,y+k-1,-1);
    }
    else{
      cin>>x;
      y=get(1,1,n,x);
      if(y==-1)
      {
        cout<<b[x]<<endl;
      }
      else
      {
        cout<<a[y]<<endl;
      }
    }
 }



}
