/*
https://codeforces.com/blog/entry/79979
https://cses.fi/problemset/task/1110/
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

const int N=2e6+5;
int hsh[N],pw[N],inv[N];
int prime=29;


signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 pw[0]=1;
 int ip=fp(prime,mod-2);
 inv[0]=1;
 for(int i=1;i<N;i++)
 {
  pw[i]=(pw[i-1]*prime)%mod;
  inv[i]=(inv[i-1]*ip)%mod;
 }



 
 string s;
 cin>>s;
 int n=s.size();
 s+=s;
 

 for(int i=0;i<2*n;i++)
 {
    if(i>0)
      hsh[i]=hsh[i-1];
    hsh[i]=(hsh[i]+pw[i]*s[i])%mod;
 }

 int k=0;
 for(int i=1;i<n;i++)
 {
  int lw=1;
  int hg=n;
  int l=0;
  while(lw<=hg)
  {
     int mid=(lw+hg)/2;
     int x=((hsh[i+mid-1]-hsh[i-1]+mod)*inv[i])%mod;
     int y=hsh[k+mid-1];
     if(k>0)
      y=(y-hsh[k-1]+mod);
    y=(y*inv[k])%mod;

    if(x==y)
    {
      l=mid;
      lw=mid+1;
    }
    else
    {
      hg=mid-1;
    }
  }
  if(s[i+l]<s[k+l])
  {
    k=i;
  }
 }
 
 cout<<s.substr(k,n);

 






}
