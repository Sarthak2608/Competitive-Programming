/*

dp[i] stores the max score if we consider only items whose set bit is ON
enumerate the mask of i then maximize the score

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define ar array<int,2>
#define inf 1000000000000000000 
int mod=1e9+7;
int min(int a,int b){return (a<b)?a:b;}
int max(int a,int b){return (a>b)?a:b;}
int fp(int a,int b){if(b==0) return 1;int x=fp(a,b/2);x=(x*x)%mod;if(b&1) x=(x*a)%mod;return x;}


const int N=2e5+5;
int dp[1ll<<16];
signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 

 int n;
 cin>>n;
 int c[n][n];
 for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        cin>>c[i][j];
 memset(dp,0,sizeof(dp));
 for(int i=0;i<(1ll<<n);i++)
 {
    for(int j=0;j<n;j++)
    {
        if((i>>j)&1)
        {
            for(int k=j+1;k<n;k++)
            {
                if((i>>k)&1)
                {
                    dp[i]+=c[j][k];        
                }
            }          
        }
    }

    for(int mask=i;mask;mask=(mask-1)&i)
    {
        dp[i]=max(dp[mask]+dp[i^mask],dp[i]);
    }
 }

 cout<<dp[(1ll<<n)-1];


}
