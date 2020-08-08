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
struct node
{
  int lnk[26];
  int ct;
  node()
  {
    ct=0;
    memset(lnk,0,sizeof(lnk));
  }
};


const int N=1e6+5,N2=5e3+5;
vector<node> bit(N);
int sz=1;
int dp[N2];


void insert(string &s,int node,int pos)
{
  if(pos==s.size())
  {
    bit[node].ct++;
    return ;
  }
  int c=s[pos]-'a';
  if(bit[node].lnk[c]==0)
  {
    bit[node].lnk[c]=++sz;
  }
 
  insert(s,bit[node].lnk[c],pos+1);
}

int dfs(string &s,int node,int pos)
{
  
  int ans=0;
  if(bit[node].ct>0){
    ans+=bit[node].ct*dp[pos];
  }
  
  if(pos==s.size())
    return ans;


  int l=bit[node].lnk[s[pos]-'a'];
  if(l==-1)
    return ans;
  ans+=dfs(s,l,pos+1);
  return ans%mod;
}



void solve()
{
  memset(dp,0,sizeof(dp));
  string s;
  cin>>s;
  int q;
  cin>>q;
  while(q--)
  {
    string tmp;
    cin>>tmp;
    insert(tmp,1,0);
  }

  dp[s.size()]=1;
  for(int i=s.size()-1;i>=0;i--)
  {
    dp[i]=dfs(s,1,i);
  }
  cout<<dp[0];


}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 srand(time(0));
 int t=1;
// cin>>t;
 for(int i=1;i<=t;i++)
 {
   solve();
 }


}
