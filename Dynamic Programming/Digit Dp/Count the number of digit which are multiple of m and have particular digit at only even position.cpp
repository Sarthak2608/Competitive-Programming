
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int mod=1e9+7;
int min(int a,int b){
  return (a<b)?a:b;
}
int max(int a,int b){
  return (a>b)?a:b;
}
int fp(int a,int b,int mod){
  if(b==0) return 1;
  int x=fp(a,b/2,mod);
  x=(x*x)%mod;
  if(b&1) x=(x*a)%mod;
  return x;
}
int m,d1;
vector<int> d;

int dp[2005][2][2005];

void digit(int pos,int f)
{
  if(dp[pos][f][0]!=-1)
    return;
  if(pos==d.size())
  {
     for(int i=0;i<m;i++)
     {
      dp[pos][f][i]=0;
     }
     dp[pos][f][0]=1;
     return;
  }

  for(int i=0;i<m;i++)
  {
    dp[pos][f][i]=0;
  }
  int lmt=9;
  if(f==0)
  {
    lmt=d[pos];
  }
  if(pos&1)
  {
    if(lmt<d1)
      return;
  }
  int x=0;
  for(int i=0;i<=lmt;i++)
  {

    if(pos&1)
    {
      i=d1;
    }
    else 
    {
      if(i==d1)
        continue;
    }
    int npos=pos+1;
    int nf=f;
    if(i<lmt)
      nf=1;
    int y=(fp(10,d.size()-pos-1,m)*i)%m;
    digit(npos,nf);

  
    for(int j=0;j<m;j++)
    {
      dp[pos][f][(j+y)%m]=(dp[pos][f][(j+y)%m]+dp[npos][nf][j])%mod;
    }

    if(pos&1)
    {
      break;
    }
  }
  return;
}


int solve(string a)
{  
  memset(dp,-1,sizeof(dp));
  d.clear();
  for(auto i:a)
  {
     d.push_back(i-'0');
  }

  digit(0,0);
  return dp[0][0][0];
}
signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 string a,b;
 cin>>m>>d1;
 cin>>a>>b;

 int ans=solve(b)-solve(a);
 int f=1;
 int x=0,p=1;
 for(int i=a.size()-1;i>=0;i--)
 {
  if(i&1)
  {
    if(a[i]-'0'!=d1)
      f=0;
  }
  else
  {
    if(a[i]-'0'==d1)
      f=0;
  }
  x=(x+(a[i]-'0')*p)%m;
  p=(p*10)%m;
 }
 if(f&&x==0){
  ans++;
 }
 ans=(ans%mod+mod)%mod;
 cout<<ans;

}
