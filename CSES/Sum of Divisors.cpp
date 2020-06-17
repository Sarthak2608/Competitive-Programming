/*
https://cses.fi/problemset/task/1082/
https://www.youtube.com/watch?v=y00EoaQjNaw
https://discuss.codechef.com/t/ppdiv-editorial/61204
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


int sum(int n)
{
  n%=mod;
  return ((n*(n+1))/2)%mod;
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 int n;
 cin>>n;
 int x=1;
 int ans=0,l=1;
 while(x<=n)
 {
   int l=x;
   int k=n/x;
   int r=n/k;
   k%=mod;
   ans+=((sum(r)-sum(l-1)+mod)*k)%mod;
   if(ans>=mod)
    ans%=mod;
   x=r+1;
   
 } 
 cout<<ans;




}
