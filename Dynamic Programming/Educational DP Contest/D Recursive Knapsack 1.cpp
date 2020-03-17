#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,w;
vector<vector<int>> a,dp;

int ans=0;
int fun(int pos,int w)
{
    if(pos==n)
    return 0;
     
    if(dp[pos][w]!=-1)
    return dp[pos][w];
   
  
         
    int x=0;
    if(w>=a[pos][0])
        x=a[pos][1]+fun(pos+1,w-a[pos][0]);
    dp[pos][w]=max(x,fun(pos+1,w));
    ans=max(ans,dp[pos][w]);
    return dp[pos][w];
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 cin>>n>>w;
 dp=vector<vector<int>>(n,vector<int>(w+5,-1));
 a=vector<vector<int>>(n,vector<int>(2));
 for(int i=0;i<n;i++)
 {
      cin>>a[i][0]>>a[i][1];
 }
 fun(0,w);
 cout<<ans;
 
} 
