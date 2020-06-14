/*
https://cses.fi/problemset/task/1081/
*/
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

const int N=1e6+6;
int div1[N]={0},ar[N];

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int ans=0; 
int n,x;
cin>>n;
for(int i=1;i<=n;i++)
{
    cin>>ar[i];
    if(div1[ar[i]]==1)
    {
        ans=max(ans,ar[i]);
    }
    div1[ar[i]]=1;
}


 for(int i=1;i<N;i++){
    int ct=0;
    for(int j=i;j<N;j+=i)
    {
        ct+=div1[j];
    }
    if(ct>=2)
        ans=max(ans,i);
  }

  cout<<ans;



}
