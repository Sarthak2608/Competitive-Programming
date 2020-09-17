/*
https://codeforces.com/contest/1183/problem/H

distinct subsequnce of length l in substring [0:i] = (distinct subsequnce of length l-1 in [0:i-1]) + (distinct subsequnce of length l in [0:i-1]) -(distinct subsequnce of length l in [0:i-1] which ends at s[i]) 

*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define ar array<int,2>
#define inf 1000000000000000000 
#define deb(x) cerr << "\n" << (#x) << " is " << (x) << endl
int mod=1e9+7;
int min(int a,int b){return (a<b)?a:b;}
int max(int a,int b){return (a>b)?a:b;}
int fp(int a,int b){if(b==0) return 1;int x=fp(a,b/2);x=(x*x)%mod;if(b&1) x=(x*a)%mod;return x;}
auto random_add = [] { char *p = new char; delete p; return uint64_t(p); };
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_add() | 1);
mt19937_64 rng(SEED);


const int N=2e5+5;



void solve()
{
  int n,k;
  cin>>n;
  string s;
  cin>>s;
  vector<int> dp(n+1);
  int tot[n+1][26]; //tot[i][j] represents subequence of length i which ends at j
  memset(tot,0,sizeof(tot));
  //dp[i] stores the uniques subsequence of length i
  dp[0]=1;
  for(int i=0;i<s.size();i++)
  {
    vector<int> ndp(n+1);
    ndp[0]=1;
    for(int j=1;j<=n;j++)
    {
      ndp[j]=dp[j]+dp[j-1]-tot[j][s[i]-'a'];
      tot[j][s[i]-'a']+=ndp[j]-dp[j];
    }
    dp=ndp;

  }

  for(int i=1;i<=n;i++)
  {
    cout<<dp[i]<<endl;
  }

}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 srand(time(0));
 int t=1;
 //cin>>t;
 for(int i=1;i<=t;i++)
 {
   solve();
 }
}
