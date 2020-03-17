#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int h,w,mod=1e9+7;
 cin>>h>>w;
 int dp[h+5][w+5];
 char ch[h+5][w+5];
 memset(dp,0,sizeof(dp));
 dp[0][0]=1;
 for(int i=0;i<h;i++)
 {
      for(int j=0;j<w;j++)
      {
           cin>>ch[i][j];
      }
 }
 
 for(int i=0;i<h;i++)
 {
      for(int j=0;j<w;j++)
      {
           if(ch[i][j]=='#')
           continue;
           if(ch[i+1][j]=='.')
           dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
           
           if(ch[i][j+1]=='.')
           dp[i][j+1]=(dp[i][j+1]+dp[i][j])%mod;
      }
 }
 cout<<dp[h-1][w-1];
}
