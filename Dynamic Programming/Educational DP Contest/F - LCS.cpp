/*

  dp[i][j] represent the longet common substring length between first i+1 character of string b 
  and  j+1 character of string a.
  
  idea:
  if last character of two string is same then dp[i][j]=dp[i-1][j-1]
  otherwise dp[i][j]=max(dp[i-1)[j],dp[i][j-1])

*/


#include <bits/stdc++.h>
using namespace std;
#define int int

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

 string a,b,ans="";
 cin>>a>>b;
 int dp[b.size()+1][a.size()+1]={0};
 int n=b.size(),m=a.size();
 int f=0;
 for(int i=0;i<a.size();i++)
 {
      if(a[i]==b[0])
      f=1;
      dp[0][i]=f;
      
 }
 f=0;
 for(int i=0;i<b.size();i++)
 {
      if(a[0]==b[i])
      f=1;
      dp[i][0]=f;
 }
 for(int i=1;i<b.size();i++)
 {
      for(int j=1;j<a.size();j++)
      {
           if(b[i]==a[j])
           {
                dp[i][j]=dp[i-1][j-1]+1;
           }
           else
           {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
           }
      }
 }
 for(int i=n-1,j=m-1;i>=0&&j>=0;)
 {
      if(b[i]==a[j]){
      ans=b[i]+ans;
      i--;
      j--;
      }
      else if(i-1>=0)
      {
           if(dp[i-1][j]==dp[i][j])
           i--;
           else
           j--;
      }
      else
      {
           j--;
      }
 }

 cout<<ans;
 
}
