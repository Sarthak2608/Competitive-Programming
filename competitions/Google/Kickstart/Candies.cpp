/*
Caution:Not submitted yet

https://www.youtube.com/watch?v=jlWA73MDrC4

  a1*a-a2*(a+d)+a3*(a+2d)-a4(a+3d)+a5(a+4d)....
  a1  -a2      +a3       -a4      +a5      .....

  for any odd l
  suppose from l=3 upto r we want 
                a3*(a)-a4(a+d)+a5*(a+2d)..
  then we:
                a3(a+(3-1)*d)-a4(a+(4-1)*d)+..
                -
                (3-1)d*(a3-a4+a5...)
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


const int N=1e5+5;

class Fenwick
{
public:
  vector<int> bit;
  int a,d;
  Fenwick()
  {
     bit=vector<int>(N);
  }

  void add(int node,int v)
  {
     for(;node<N;node+=(node&(-node)))
      bit[node]+=v;
  }
  int get(int node)
  {
    int x=0;
    for(;node>0;node-=(node&(-node)))
      x+=bit[node];
    return x;
  }
  void init(int n,int A,int D)
  {
    a=A;
    d=D;
    for(int i=0;i<=n;i++)
      bit[i]=0;
  }

};

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int a=1; //a=first term d=difference
 int d=1;
 char typ;
 Fenwick f1[2]; 
 int ans,t,l,r,x,y;
 int tt=0;
 cin>>t;
 while(t--)
 {
   int n,q;
   cin>>n>>q;
   f1[0].init(n,a,d);
   f1[1].init(n,a,d);
   int ar[n+1];
   int s1=1;
   for(int i=1;i<=n;i++)
   {
    cin>>ar[i];

    f1[0].add(i,s1*ar[i]*(a+(i-1)*d));
    f1[1].add(i,s1*ar[i]);

    s1*=-1;

   }
   int res=0;
   while(q--)
   {
      cin>>typ>>l>>r;
      if(typ=='Q')
      {
         x=f1[0].get(r)-f1[0].get(l-1);
         y=f1[1].get(r)-f1[1].get(l-1);
         ans=x-(l-1)*y;
         if(!(l&1))
          ans*=-1;
         res+=ans;
         //cout<<ans<<endl;
      }
      else
      {
          if(l&1)
            s1=1;
          else
            s1=-1;

          f1[0].add(l,-s1*ar[l]*(a+(l-1)*d));
          f1[1].add(l,-s1*ar[l]);

          //cout<<-s1*ar[l]*(a+(l-1)*d)<<" "<<-s1*ar[l]<<endl;

          ar[l]=r;
          
  
          f1[0].add(l,s1*ar[l]*(a+(l-1)*d));
          f1[1].add(l,s1*ar[l]);

          //cout<<s1*ar[l]*(a+(l-1)*d)<<" "<<s1*ar[l]<<endl;

      }
   }
   tt++;
   cout<<"Case #"<<tt<<": "<<res<<endl;

 }
 

}
/*
1
5 4
1 3 9 8 2
Q 5 5
Q 3 5
Q 1 5
Q 2 4
*/
