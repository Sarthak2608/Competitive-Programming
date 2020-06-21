/*
https://cses.fi/problemset/task/1724/
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int mod=1e9+7;
#define inf 1000000000000000001
int min(int a,int b){
  return (a<b)?a:b;
}
int max(int a,int b){
  return (a>b)?a:b;
}


#define ar array<array<int,101>,101>  //change the dimension 
int n;

ar mul(ar a,ar b)
{
  ar res;
  for(int i=1;i<=n;i++)
  {
          for(int j=1;j<=n;j++)
          {
            res[i][j]=inf;
          }
  }

  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      for(int k=1;k<=n;k++)
        res[i][j]=min(res[i][j],a[i][k]+b[k][j]);
  return res;
}
 
 
ar fp(ar a,int b){

  if(b==0)
  {
       ar c;
       for(int i=1;i<=n;i++)
       {
          for(int j=1;j<=n;j++)
          {
            if(i==j)
            c[i][j]=0;
            else
            c[i][j]=inf;
          }
       }
       return c;       
  }
 
  auto x=fp(a,b/2);
  x=mul(x,x);
  if(b&1) x=mul(x,a);
  return x;
}
 
 
 
signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int m,k,x,y,z;
 cin>>n>>m>>k;
 ar a;
 for(int i=1;i<=n;i++)
 {
    for(int j=1;j<=n;j++)
    {
      a[i][j]=inf;
    }
 }

 for(int i=1;i<=m;i++)
 {
  cin>>x>>y>>z;
  a[x][y]=min(a[x][y],z);
 }
 
 auto b=fp(a,k);
 if(b[1][n]==inf)
  b[1][n]=-1;
 cout<<b[1][n];

 
 
}
