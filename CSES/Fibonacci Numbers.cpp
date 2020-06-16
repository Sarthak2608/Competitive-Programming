/*
https://cses.fi/problemset/task/1722/
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
#define ar array<int,2> 

array<ar,2> mul(array<ar,2> a,array<ar,2> b)
{
  array<ar,2> res={ar{0,0},ar{0,0}};
  for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
      for(int k=0;k<2;k++)
        res[i][j]+=a[i][k]*b[k][j];
  for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
      if(res[i][j]>=mod)
        res[i][j]%=mod;
      return res;
}


array<ar,2> fp(array<ar,2> a,int b){
  if(b==0) return {ar{1,0},ar{0,1}};

  auto x=fp(a,b/2);
  x=mul(x,x);
  if(b&1) x=mul(x,a);
  return x;
}



signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int n;
 cin>>n;
 if(n==0)
 {
  cout<<0;
  return 0;
 }
 array<ar,2> a={ar{1,1},ar{1,0}};
 auto b=fp(a,n);
 cout<<b[1][0];
 

}
