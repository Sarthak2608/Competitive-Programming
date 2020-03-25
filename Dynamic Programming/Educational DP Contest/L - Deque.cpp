/*
 dp[i][j] defines the required score for the range i to j
 if n is odd then last chance will be of Taro otherwise of Jiro
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 int n;
 cin>>n;
 int a[n+1];
 int dp[n+1][n+1];
 memset(dp,0,sizeof(dp));
 for(int i=1;i<=n;i++)
 {
      cin>>a[i];
 }
 int x=1;    //x=0 if the taro chance else x=1 for jiro
 if(n&1)
 {
      x=0;
 }
 for(int i=1;i<=n;i++)
 {
      dp[i][i]=a[i];
      if(x==1)
      dp[i][i]*=-1;
 }
 for(int len=1;len<n;len++)
 {
     x^=1;
     for(int i=1;i+len<=n;i++)
     {
          if(x==0)
          dp[i][i+len]=max(dp[i][i+len-1]+a[i+len],dp[i+1][i+len]+a[i]);
          else
          dp[i][i+len]=min(dp[i][i+len-1]-a[i+len],dp[i+1][i+len]-a[i]);
     }
 }
 cout<<dp[1][n]<<endl;
 

}
