/**
https://atcoder.jp/contests/dp/tasks/dp_y

no of ways to reach (H,W) =no of ways to reach the first obstacle i * total ways to reach from i to (H,W)


**/

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
int fact[N],inv[N];


int ncr(int n,int r)
{
    return  ( ( (fact[n]*inv[n-r])%mod ) * inv[r] )%mod;
}

int distanceBetweenPoint(array<int,2> p,array<int,2> q)
{
    if(p[0]<=q[0]&&p[1]<=q[1])
    {
        int down=q[1]-p[1];
        int right=q[0]-p[0];
        return ncr(down+right,down);
    }
    return 0;
}


signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 
 fact[0]=1;
 inv[0]=1;
 for(int i=1;i<N;i++)
 {
    fact[i]=(fact[i-1]*i)%mod;
    inv[i]=fp(fact[i],mod-2);
 }


 int n,H,W;
 cin>>H>>W>>n;
 vector<array<int,2>> obs(n);
 for(int i=0;i<n;i++)
 {
    cin>>obs[i][0]>>obs[i][1];
 }
 sort(obs.begin(),obs.end(),[&](array<int,2> p,array<int,2> q){
    return p[0]+p[1]<q[0]+q[1];
 });

 int ways=distanceBetweenPoint({1,1},{H,W});

 //cout<<ways;

 int w[n+1]; //no of ways to reach ith obstacle ,with passing no obstacle 1...i-1
 
 for(int i=0;i<obs.size();i++)
 {
    if(i==0)
    {
        w[i]=distanceBetweenPoint({1,1},obs[i]);
    }
    else
    {
        w[i]=distanceBetweenPoint({1,1},obs[i]);
        for(int j=0;j<i;j++)
        {
            w[i]-=(distanceBetweenPoint(obs[j],obs[i])*w[j])%mod;
            if(w[i]<0)
                w[i]+=mod;
        }
    }
    ways-=(w[i]*distanceBetweenPoint(obs[i],{H,W}))%mod;
    if(ways<0)
        ways+=mod;
 }

 cout<<ways;




}
