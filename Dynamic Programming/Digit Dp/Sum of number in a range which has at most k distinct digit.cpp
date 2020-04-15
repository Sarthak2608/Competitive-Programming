/*
https://codeforces.com/contest/1073/problem/E
https://codeforces.com/contest/1073/submission/76908268

 mask represent wich digit already used
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int mod=998244353;
int min(int a,int b){
    return (a<b)?a:b;
}
int max(int a,int b){
    return (a>b)?a:b;
}
int fp(int a,int b){
    if(b==0) return 1;
    int x=fp(a,b/2);
    x=(x*x)%mod;
    if(b&1) x=(x*a)%mod;
    return x;
}

int k;
vector<int> d;
int mp[21][2][5000][2];
array<int,2> digit(int pos,int f,int mask)
{
      int tmpmask=mask;
      int ct=0;
      while(tmpmask>0)
      {
        if(tmpmask&1)
          ct++;
        tmpmask>>=1;
      }
      if(ct>k)
        return {0,0};
    

    if(pos==d.size())
    {
        return {1,0};   
    }
    
    if(mp[pos][f][mask][0]!=-1)
    return {mp[pos][f][mask][0],mp[pos][f][mask][1]};
    int lmt=9;
    if(f==0)
    {
      lmt=d[pos];
    }
    int sum=0,ans=0;
    for(int i=0;i<=lmt;i++)
    {
        int nf=f;
        int nmask=mask;
        int npos=pos+1;
        if(i<lmt)
        {
            nf=1;
        }
        if(!(mask==0&&i==0))
        {
           nmask|=(1ll<<i);
        }
        
        int x=(fp(10,d.size()-pos-1)*i)%mod;
        array<int,2> res=digit(npos,nf,nmask);
        sum=(sum+res[0])%mod;
        ans=(ans+res[1])%mod;
        ans=(ans+(x*res[0]))%mod%mod;
    }
   
    mp[pos][f][mask][0]=sum;
    mp[pos][f][mask][1]=ans;
    return {sum,ans};
}

int solve(int n)
{
    memset(mp,-1,sizeof(mp));
    if(n==0)
        return 0;
    d.clear();
    while(n>0)
    {
        d.push_back(n%10);
        n/=10;
    }
    reverse(d.begin(),d.end());
   
   int x=digit(0,0,0)[1];

   return x;
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int l,r;

 cin>>l>>r>>k;
 int sum=solve(r)-solve(l-1);
 sum=(sum+mod)%mod;
 cout<<sum<<endl;
}
