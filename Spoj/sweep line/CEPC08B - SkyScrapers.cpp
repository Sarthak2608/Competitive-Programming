
/*

*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

struct event
{
  int x;
  int y;
  int z;
  int typ;
  int id;
  event()
  {
    x=-1;
    z=-1;
  }
};

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 int t;
 cin>>t;
 while(t--)
 {
   int n,q,x;
   cin>>n>>q;
   int res[q+1];
   vector<event> qr;

   int a[n+1];
   vector<int> v;
   for(int i=1;i<=n;i++)
   {
     cin>>a[i];
   }
   for(int i=1;i<=n;i++)
   {
     if(i+1<=n&&a[i]==a[i+1])
      continue;
     v.push_back(a[i]);
   }

   for(int i=0;i<v.size();i++)
   {
     event e;
    
     e.typ=1;
     e.y=v[i];
     if(i>0)
      e.x=v[i-1];
     if(i+1<v.size())
      e.z=v[i+1];
     qr.push_back(e);
   }



   for(int i=0;i<q;i++)
   {
     cin>>x;
     event e;
     e.id=i;
     e.typ=2;
     e.y=x;
     qr.push_back(e);
   }

   sort(qr.begin(),qr.end(),[&](event e1,event e2){
      if(e1.y==e2.y)
        return e1.typ<e2.typ;
      return e1.y<e2.y;
   });
   int ans=1;
   for(auto i:qr)
   {
      if(i.typ==1)
      {
          if(i.y<i.x&&i.y<i.z)
          {
            ans++;
          }
          else if(i.y>i.x&&i.y>i.z)
          {
            ans--;
          }
      }
      else
      {
        res[i.id]=ans;
      }
   }
   for(int i=0;i<q;i++)
    cout<<res[i]<<" ";
  cout<<endl;

   
 }


}
