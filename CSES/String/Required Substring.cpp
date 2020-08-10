/*
https://cses.fi/problemset/task/1112/

Time:O(n*m*m) or O(n*m) not confirm

But using some pre calculation we can reduce to o(n*m)

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


/*
To count:
 s*****
 xs****
 xxs***
 xxxs**
 xxxxs*
 xxxxxs
  
 for each i:
 dp[len of the max prefix of s ending at i-1]=count the number of string of len i-1 having prefix of len
 and there is not a substring s in the string[0:i-1]

*/
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int m=s.size();
    int pi[m+1];
    pi[0]=0;
    int j=0;
    for(int i=1;i<m;i++)
    {
      while(j>0&&s[i]!=s[j])
      {
        j=pi[j-1];
      }
      if(s[j]==s[i])
        j++;
      pi[i]=j;
    }
    int dp[m+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
      int ndp[m+1];
      memset(ndp,0,sizeof(ndp));
      for(char ch='A';ch<='Z';ch++)
      {
        for(int j=m-1;j>=0;j--)
        {
          if(s[j]==ch){
          ndp[j+1]+=dp[j];
          if(ndp[j+1]>=mod)
            ndp[j+1]-=mod;
          }
          else{
            int k=j;  //we can reduce time complexity by precalculating this for each ch
            while(k>0&&s[k]!=ch)
            {
              k=pi[k-1];
            }
            if(s[k]==ch){
              ndp[k+1]+=dp[j];
              if(ndp[k+1]>=mod)
              ndp[k+1]-=mod;
            }
            else{
              ndp[k]+=dp[j];
              if(ndp[k]>=mod)
                ndp[k]-=mod;
            }

          }
        }
      }
      memcpy(dp,ndp,sizeof(dp));
      ans+=(dp[m]*fp(26,n-i))%mod;
      if(ans>=mod)
        ans%=mod;
    }
    cout<<ans<<endl;

}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 srand(time(0));
 int t;
 t=1;
 for(int i=1;i<=t;i++)
 {
   solve();
 }


}
