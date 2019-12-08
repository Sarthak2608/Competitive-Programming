//XOR of all pairs in an array.cpp
//let (x,y) is a pair then (y,x) is also consider equal to the (x,y) pair
//so 1<=i<=j+1<=N (a[i] XOR a[j])

#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main(){
  int mod=1e9+7;
  int n;
  cin>>n;
  int a[n+1];
  for(int i=1;i<=n;i++)
  {
      cin>>a[i];
  }
  bitset<61> b[n+1];
  int c[n+2][61];
  for(int i=1;i<=n;i++)
  {
      for(int j=0;j<=60;j++)
      {
          b[i][j]=a[i]&(1l<<j);
      }
  }
  
  for(int i=n;i>=1;i--)
  {
      for(int j=0;j<=60;j++)
      {
          if(i==n)
          c[i][j]=0;
          c[i-1][j]=(b[i][j]+c[i][j]);
      }
  }
  int res=0;
  for(int i=1;i<=n;i++)
  {
      for(int j=0;j<=60;j++)
      {
          if(b[i][j]==1)
          res=(res+((n-c[i][j]-i)*((1l<<j)%mod))%mod)%mod;
          else
          res=(res+(c[i][j]*((1l<<j)%mod))%mod)%mod;
          res%=mod;
      }
  }
  cout<<res%mod<<endl;
  
}
