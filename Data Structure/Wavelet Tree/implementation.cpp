/*
zero based indexing

GK
https://www.youtube.com/watch?v=CybAgVF-MMc
Errichto
https://www.youtube.com/watch?v=4aSv9PcecDw
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long


class waveletTree
{
public:
  static const int N=2e5+5;
  vector<vector<int>> bit,left;
  int n;
  waveletTree()
  {
     bit=vector<vector<int>>(4*N);
     left=vector<vector<int>>(4*N);
  }
  void init(int n1)
  { 
      n=n1;
      for(int i=0;i<=n;i++)
      {
          bit[i].clear();
          left[i].clear();
      } 
  }

  void build(int id,int l,int r,vector<int> &v)
  {
      if(v.size()==0)
        return;
      bit[id]=v;
      if(l==r)
      {
         return;
      }
      int mid=(l+r)/2;
      vector<int> v1,v2;
      
      left[id]=vector<int>(v.size()+1);
      for(int i=0;i<v.size();i++)
      {
         left[id][i]=v1.size();
         if(v[i]<=mid)
         {  
            v1.push_back(v[i]);
         }
         else
         {
            v2.push_back(v[i]);
         }
      }
      left[id][v.size()]=v1.size();

      build(2*id,l,mid,v1);
      build(2*id+1,mid+1,r,v2);
  }

  int countElementEqualX(int id,int l,int r,int L,int R,int x)
  {

      if(L>R||L>=bit[id].size())
      return 0;
      
      if(l==r)
      {
        return R-L+1;
      }
      
      int mid=(l+r)/2;
      if(x<=mid)
      {
        int nl=left[id][L];
        int nr=left[id][R+1]-1;
        return countElementEqualX(2*id,l,mid,nl,nr,x);
      }
      else
      {
        int nl=L-left[id][L];
        int nr=R+1-left[id][R+1]-1;
        return countElementEqualX(2*id+1,mid+1,r,nl,nr,x);
      }

  }

  int countElementLessThanX(int id,int l,int r,int L,int R,int x)
  {
      if(L>R||L>=bit[id].size())
      return 0;
      
      if(l==r)
      {
        if(l<=x)
        return R-L+1;
        return 0;
      }
      
      int mid=(l+r)/2;
      if(x<=mid)
      {
        int nl=left[id][L];
        int nr=left[id][R+1]-1;
        return countElementLessThanX(2*id,l,mid,nl,nr,x);
      }
      else
      {
        int nl=L-left[id][L];
        int nr=R+1-left[id][R+1]-1;
        return left[id][R+1]-left[id][L]+countElementLessThanX(2*id+1,mid+1,r,nl,nr,x);
      }

  }


  int KthElement(int id,int l,int r,int L,int R,int k)
  {
      if(L>R||L>=bit[id].size())
      return -1;
      
      if(l==r)
      {
        return l;
      }
      
      int mid=(l+r)/2;
      if(left[id][R+1]-left[id][L]>=k)
      {
        int nl=left[id][L];
        int nr=left[id][R+1]-1;
        return KthElement(2*id,l,mid,nl,nr,k);
      }
      else
      {
        k-=(left[id][R+1]-left[id][L]);
        int nl=L-left[id][L];
        int nr=R+1-left[id][R+1]-1;
        return KthElement(2*id+1,mid+1,r,nl,nr,k);
      }

  }


};

signed main() {
    ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
 waveletTree w;
 const int mxval=100005;
 w.init(mxval);

 int n;
 cin>>n;
 vector<int> v(n);
 for(int i=0;i<n;i++)
 {
  cin>>v[i];
 }
 
 w.build(1,1,mxval,v);
 
 int l=0;
 int r=n-1;
 int k=2;
 int x=5;
   cout<<w.countElementLessThanX(1,1,mxval,l,r,x)<<endl;
   cout<<w.countElementEqualX(1,1,mxval,l,r,x)<<endl;
   cout<<w.countElementEqualX(1,1,mxval,l,r,k)<<endl;
}

/*

*/
