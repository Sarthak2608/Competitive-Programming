#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

 int n,w;
 cin>>n>>w;
 int wt[n],val[n];
 int sum_val=0;
 
 for(int i=0;i<n;i++)
 {
      cin>>wt[i]>>val[i];
      sum_val+=val[i];
 }
 
 vector<int> dp(sum_val+1,INT_MAX);  //stores the minimum weight with exactly value i(0<=i<=sum_val)
 dp[0]=0;
 for(int i=0;i<n;i++)
 {
      for(int v=sum_val;v>=val[i];v--)
      {
           dp[v]=min(dp[v],dp[v-val[i]]+wt[i]);
      }
 }
 int ans=0;
 for(int i=0;i<=sum_val;i++)
 {
      if(dp[i]<=w)
      ans=max(ans,i);
 }
 cout<<ans;
}
