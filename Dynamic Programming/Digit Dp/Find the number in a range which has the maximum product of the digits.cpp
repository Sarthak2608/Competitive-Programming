/*
 f1=1 when the num>a & f2=1 when num<b
 first represent the first non zero digit in a
 dp[npos][nf1][nf2][0] represent the required number
 dp[npos][nf1][nf2][1] represent the product

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
  x=(x*x);
  if(b&1) x=(x*a);
  return x;
}
int first=0;  
string a,b;
int dp[20][2][2][2];  


void digitdp(int pos,int f1,int f2)
{
  if(pos==b.size())
  {
    dp[pos][f1][f2][1]=1;
    dp[pos][f1][f2][0]=1;
    return;
  }
  if(dp[pos][f1][f2][1]!=-1)
     return ;
  int lmt=9;
  if(f1==0)
  {
     lmt=b[pos]-'0';
  }
  int st=0;
  if(f2==0)
  {
    st=a[pos]-'0';
  }
  int cnum=-1,nval=0;
  for(int i=st;i<=lmt;i++)
  {
    int npos=pos+1;
    int nf1=f1;
    int nf2=f2;
    if(i>st)
    {
       nf2=1;
    }
    if(i<lmt)
    {
      nf1=1;
    }
    digitdp(npos,nf1,nf2);
    
    int num=dp[npos][nf1][nf2][0];
    int pval=dp[npos][nf1][nf2][1];
   
    if(pos+1==b.size())
    {
      cnum=i;
      nval=i;
      continue;
    }
    if(num==-1)
      continue;
    if(nf2==0&&pos<first)
    {
      if(nval<pval)
      {
        nval=pval;
        cnum=num+i*fp(10,b.size()-pos-1);    
      }
      continue;
    }
    if(nval<=(pval*i))
    {
      nval=pval*i;
      cnum=num+i*fp(10,b.size()-pos-1);
    }
  }
  dp[pos][f1][f2][0]=cnum;
  dp[pos][f1][f2][1]=nval;


}


signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 memset(dp,-1,sizeof(dp));
  
 cin>>a>>b;
 while(a.size()!=b.size()){
  a='0'+a;
  first++;
 }
 digitdp(0,0,0);
 cout<<max(dp[0][0][0][0],0ll)<<endl;
}
