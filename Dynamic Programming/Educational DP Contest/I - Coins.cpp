/*
 dp[i][j] represent the probability of getting j heads in i coins tosses
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int n;
 cin>>n;
 double ar[n+1];
 for(int i=1;i<=n;i++)
 {
      cin>>ar[i];
 }
 double ans=0,dp[n+1][n+1];
 memset(dp,0,sizeof(dp));
 dp[1][0]=1-ar[1];
 dp[1][1]=ar[1];
 for(int i=2;i<=n;i++)
 {
      for(int j=0;j<=i;j++)
      {
           dp[i][j]=(1-ar[i])*dp[i-1][j];
           dp[i][j]+=ar[i]*dp[i-1][j-1];
      }
 }

 
 for(int i=0;i<=n;i++)
 {
      if(i>(n-i))
      {
           ans+=dp[n][i];
      }
 }
 
 std::cout << std::setprecision(9) << ans << '\n';

}
