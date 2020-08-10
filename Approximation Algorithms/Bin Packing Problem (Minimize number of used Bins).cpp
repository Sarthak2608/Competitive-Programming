/*
https://www.geeksforgeeks.org/bin-packing-problem-minimize-number-of-used-bins/

first put the item which has highest weight
put the each item in a bag such that remaining space is minimum
Fact:using this at most half space will waste

https://cses.fi/problemset/task/1653/  (50% test cases passes)


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


void solve()
{
    int n,x;
    cin>>n>>x;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {
      cin>>a[i];
    } 
    sort(a.begin()+1,a.end(),greater<int>());
    int sz=0;
    int bin[n+1]={0};
    for(int i=1;i<=n;i++)
    {
      int pos=-1;
      for(int j=1;j<=sz;j++)
      {
        if(x-bin[j]>=a[i])
        {
          if(pos==-1)
            pos=j;
          else if(x-bin[j]<x-bin[pos])
            pos=j;
        }
      }
      if(pos==-1)
      {
        sz++;
        bin[sz]+=a[i];
      }
      else
      {
        bin[pos]+=a[i];
      }
    }
    cout<<sz<<endl;

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
