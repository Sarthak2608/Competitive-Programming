/*
 dp[i] stores who will win ,when the length of pile is i .
 if the first player is winning by taking any element x from array then dp[i]=0 othewise 1
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long



signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int n,k;
 cin>>n>>k;
 int ar[n+1];
 for(int i=1;i<=n;i++)
 {
      cin>>ar[i];
 }
 int dp[100005];
 dp[0]=1; 
 for(int i=1;i<=1e5;i++)
 {
      for(int j=1;j<=n;j++)
      {
           if(i-ar[j]>=0){        
           dp[i]=1^dp[i-ar[j]];
           if(!dp[i])             
           break;
           }
           else{
           dp[i]=1;
           }
      }
 }
 if(dp[k]==0){
 cout<<"First";
 }
 else{
 cout<<"Second";
 }
 
}
