/*
https://cses.fi/problemset/task/1654/

x|y   :  no of y=count(subset of x)
x&y!=0:  no of y=count(subset of(negation of x)))
x&y=x : means we have to count the element which has set bit iff x has set bit then store the number in negation form then count the submask of negaation of x

*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ar array<int,2>
#define inf 1000000000000000000 
int mod=1e9+7;
int min(int a,int b){return (a<b)?a:b;}
int max(int a,int b){return (a>b)?a:b;}
int fp(int a,int b){if(b==0) return 1;int x=fp(a,b/2);x=(x*x)%mod;if(b&1) x=(x*a)%mod;return x;}


const int N=20;
int F[5+1ll<<N],F2[5+1ll<<N];
int flip(int x)
{
    for(int i=N-1;i>=0;i--){
        x^=(1ll<<i);
    }
    return x;
}

void solve()
{
    memset(F,0,sizeof(F));
    memset(F2,0,sizeof(F2));
    int n,x,y,z;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        F[a[i]]++;
        F2[flip(a[i])]++;
    }   

    for(int i = 0;i < N; ++i) for(int mask = (1ll<<N)-1; mask >=0 ; --mask){
    if(mask & (1<<i))
      F[mask] += F[mask^(1<<i)];
    }

    for(int i = 0;i < N; ++i) for(int mask = (1ll<<N)-1; mask >=0 ; --mask){
    if(mask & (1<<i))
      F2[mask] += F2[mask^(1<<i)];
    }    

    for(int i=1;i<=n;i++)
    {       
        int r=flip(a[i]);
        x=F[a[i]];
        y=F2[r];
        z=n-F[r];
        cout<<x<<" "<<y<<" "<<z<<endl;
    }
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
