/*
https://codeforces.com/contest/165/problem/E
https://codeforces.com/blog/entry/45223

a&b=0
so b is the subset of the mask of complement of a

for each mask we have to store any number which is the subset of the mask

*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
//#define int long long

const int N=(1ll<<22)+5;
int dp[N];


signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 int n;
 cin>>n;
 int a[n+1];
 memset(dp,-1,sizeof(dp));
 for(int i=1;i<=n;i++)
 {
   cin>>a[i];
   dp[a[i]]=a[i];
 }

for(int j=1;j<23;j++)
{
   for(int i=0;i<(1ll<<22);i++)
   {
        if((i>>(j-1))&1)
        {
            dp[i]=max(dp[i],dp[i^(1ll<<(j-1))]);
        }
    }
}

for(int i=1;i<=n;i++)
{
    cout<<dp[(a[i]^((1ll<<22)-1))]<<" ";
}


}
