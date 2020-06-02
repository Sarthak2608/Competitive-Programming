/*
Bottom Up Approach
https://www.codechef.com/viewsolution/33567913

https://www.youtube.com/watch?v=5a7EYVulN-w

Top down implementation

*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int min(int a,int b){
  return (a<b)?a:b;
}
int max(int a,int b){
  return (a>b)?a:b;
}

class query
{
public:
  static const int N=2e5+5;
  vector<vector<int>> bit,lf,rg;

  int n,mx;
  vector<array<int,2>> a;
  query()
  {
    bit=vector<vector<int>>(4*N);
    lf=vector<vector<int>>(4*N);
    rg=vector<vector<int>>(4*N);
  }
  void init(vector<array<int,2>> &a1)
  {
    //maximum x value
    mx=2e5;
    a=a1;

    //total points
    n=a.size();

    //sort by y
    sort(a.begin(),a.end(),[&](array<int,2> p,array<int,2> q){
       return p[1]<q[1];
    });  

    build(1,1,mx,a);
  }

  void build(int id,int l,int r,vector<array<int,2>> &v)
  {
      for(auto i:v)
        bit[id].push_back(i[1]);

      if(l==r)
      {
        return;
      }

      vector<array<int,2>> v1,v2;
      int mid=(l+r)/2;
      for(int i=0;i<v.size();i++)
      {

         if(v[i][0]<=mid)
         {
          v1.push_back(v[i]);
         }
         else
         {
          v2.push_back(v[i]);
         }
         lf[id].push_back(v1.size());  //total points whose y coordinate less than or equal point[i].y
         rg[id].push_back(v2.size());
      }

      build(2*id,l,mid,v1);
      build(2*id+1,mid+1,r,v2);
  }
  
  //returns total point(p,q)-> (l<=p<=r) (p<=y)
  int get(int id,int l,int r,int L,int R,int y,int p)  
  {
      if(id==1)
      {
          p=upper_bound(bit[id].begin(),bit[id].end(),y)-bit[id].begin();
          if(p==0)
            return 0;
      }
      if(p==0)
        return 0;

      if(r<L||l>R)
        return 0;

      if(L<=l&&r<=R)
      {
          return p;
      }

      int mid=(l+r)/2;
      return get(2*id,l,mid,L,R,y,lf[id][p-1])+get(2*id+1,mid+1,r,L,R,y,rg[id][p-1]);
  }

};



signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 srand(time(0));
 vector<array<int,2>> v;
 v.push_back({1,2});
 v.push_back({5,2});

 query q;
 q.init(v);
 int mx=2e5;

 int x1=1;
 int x2=10;
 int y=10;
 cout<<q.get(1,1,mx,x1,x2,y,-1);


}
