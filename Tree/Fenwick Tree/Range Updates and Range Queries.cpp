/*
https://cp-algorithms.com/data_structures/fenwick.html#toc-tgt-10

https://www.codechef.com/LRNDSA04/problems/STRSUB/
https://www.codechef.com/viewsolution/33382466

we want
 range update and range sum query from 0 to i
:
 f=   {
      0           i<l
      x*(i-l+1)   l<=i<=r
      x*(r-l+1)   i>r
      }

lets split into :
 range update and point query from 0 to i
f1=
    {
      0           i<l
      x           l<=i<=r
      0           i>r
    }

let represent f as:
    f=i*f1+f2 
    {
     0   +0          i<l
     x*i +x*(-l+1)   l<=i<=r
     0   +x*(r-l+1)  i>r
    } 
*/
#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long


class Fenwick
{
public:
  int mxn;
  vector<int> bit;
  Fenwick()
  {
    bit=vector<int>(1e5+10);
    mxn=1e5+5;
  }
  void init(int n)
  {
     for(int i=0;i<=n;i++)
      bit[i]=0;
  }
  int get(int node)
  {
    int x=0;
    for(;node>0;node-=(node&(-node)))
      x+=bit[node];
    return x;
  }
  void add(int node,int x)
  {
     for(;node<mxn;node+=(node&(-node)))
      bit[node]+=x;
  }
};



class modifiedFenwick
{
public:
  Fenwick f1,f2;
  modifiedFenwick()
  {
  }
  void init(int n)
  {
      f1.init(n);
      f2.init(n);
  }
  void rangeupdate(int l,int r,int val)
  {
      f1.add(l,val);
      f1.add(r+1,-val);

      f2.add(l,val*(-l+1));
      f2.add(r+1,val*r);
  }
  int get(int r)
  {
     return r*f1.get(r)+f2.get(r);
  }
  int rangeSum(int l,int r)
  {
     return get(r)-get(l-1);
  }
   
};


int32_t main()
{
  IOS;
  modifiedFenwick f;
  f.rangeupdate(1,4,1);
  f.rangeupdate(2,4,1);
  f.rangeupdate(5,8,1);
  cout<<f.rangeSum(1,3);  
} 
