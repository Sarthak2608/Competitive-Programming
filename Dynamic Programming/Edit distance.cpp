/*
https://www.youtube.com/watch?v=We3YDTzNXEk
https://cses.fi/problemset/task/1639/
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

const int N=5005;
int dp[N][N];

//dp[i][j] stores minimum steps to convert a[1:i] to b[1:j]

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 

 string a,b;
 cin>>a>>b;
 int n=a.size();
 int m=b.size();
 
 a='#'+a;
 b='#'+b;

 dp[0][0]=0;
 for(int i=1;i<=n;i++)
 {
    dp[i][0]=i;  //deleting character a[1:i]
 }
 for(int i=1;i<=m;i++)
 {
     dp[0][i]=i;  //adding character b[1:i]  
 }


 for(int i=1;i<=n;i++)
 {
    for(int j=1;j<=m;j++)
    {
        if(a[i]==b[j])
        {
            dp[i][j]=dp[i-1][j-1];
        }
        else
        {
            dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
            //              delete     add        edit
        }
    }
 }
 


 cout<<dp[n][m];

}
