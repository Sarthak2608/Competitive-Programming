#include <bits/stdc++.h>
using namespace std;
#define int long long
int max(int a,int b)
{
    return (a>b)?a:b;
}
struct SegmentTree
{
  int N;
  vector<int> bit,bit2,bit3;
  SegmentTree(int n)
  {
      N=n/4;
      bit=vector<int>(n+1);
      bit2=vector<int>(n+1);
      bit3=vector<int>(n+1);
  }
  
  void update(int id,int l,int r,int point,int val)
  {
      if(l==r&&l==point)
      {
          bit[id]=val;
          bit2[id]=val;
          bit3[id]=val;
          return;
      }
      int mid=(l+r)/2;
      if(point<=mid)
      update(2*id,l,mid,point,val);
      else
      update(2*id+1,mid+1,r,point,val);
      bit[id]=bit[2*id]+bit[2*id+1];
      bit2[id]=max(bit2[2*id],bit[2*id]+bit2[2*id+1]);
      bit3[id]=max(bit3[2*id]+bit[2*id+1],bit3[2*id+1]);
  }
  
  array<int,2> maxSuffixsum(int id,int l,int r,int R)
  {
      if(r<R)
      return {0,0};
      
      if(l>=R)
      {
          //cout<<l<<" "<<r<<endl;
          return {bit2[id],bit[id]};
      }
      int mid=(l+r)/2;
      auto x=maxSuffixsum(2*id,l,mid,R);
      array<int,2> y={0,0};
      y=maxSuffixsum(2*id+1,mid+1,r,R);
      if(R<=mid)
      y[0]+=x[1];
      return {max(x[0],y[0]),x[1]+y[1]};
  }
  
  array<int,2> maxPrefixsum(int id,int l,int r,int L)
  {
      if(L<l)
      return {0,0};
      
      if(L>=r)
      {
          //cout<<l<<" "<<r<<endl;
          return {bit3[id],bit[id]};
      }
      int mid=(l+r)/2;
      auto x=maxPrefixsum(2*id,l,mid,L);
      array<int,2> y={0,0};
      y=maxPrefixsum(2*id+1,mid+1,r,L);
      if(mid+1<=L)
      x[0]+=y[1];
      return {max(x[0],y[0]),x[1]+y[1]};
  }
  

  
  int rangeSum(int id,int l,int r,int L,int R)
  {
      if(l>R||r<L)
      {
          return 0;
      } 
      if(L<=l&&r<=R)
      {
          return bit[id];
      }
      int mid=(l+r)/2;
      return rangeSum(2*id,l,mid,L,R)+rangeSum(2*id+1,mid+1,r,L,R);
      
  }
  
};


signed main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,q,x,y;
        char typ;
        cin>>n>>q;
        SegmentTree obj(4*n);
        int a[n+1];
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            obj.update(1,1,n,i,a[i]);
        }
        while(q--)
        {
            cin>>typ>>x>>y;
            if(typ=='Q')
            {
                int p=obj.maxPrefixsum(1,1,n,x-1)[0];
                int q=obj.maxSuffixsum(1,1,n,y+1)[0];
                cout<<max(p,0)+obj.rangeSum(1,1,n,x,y)+max(q,0)<<endl;
            }
            else
            {
                obj.update(1,1,n,x,y);
            }
        }
    }
	return 0;
}
