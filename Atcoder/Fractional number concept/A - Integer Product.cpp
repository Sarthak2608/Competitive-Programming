//https://atcoder.jp/contests/agc047/tasks/agc047_a

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



void solve()
{
   int n;
   cin>>n;
   int ans=0;
   map<array<int,2>,int> mp; 
   for(int i=1;i<=n;i++)
   {
    long double x1;
    cin>>x1;
    int x=round(x1*1e9);
    //cout<<x<<endl;
    int a=0,b=0;
    while(x%2==0){
      x/=2;
      a++;
    }
    while(x%5==0)
    {
      b++;
      x/=5;
    }

    for(auto i:mp)
    {
      if((i.first[0]+a)>=18&&(i.first[1]+b)>=18)
        ans+=i.second;
    }
    mp[{a,b}]++;
   }  

   cout<<ans;
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
