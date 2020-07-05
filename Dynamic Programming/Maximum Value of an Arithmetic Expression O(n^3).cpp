/*

Find the maximum value of an arithmetic expression by specifying the order of applying its arithmetic
operations using additional parentheses.
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



signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 string s;
 cin>>s;
 int n=s.size();
 int dp[2][n+1][n+1];
 memset(dp,0,sizeof(dp));

 for(int i=0;i<n;i+=2)
 {
 	dp[0][i][i]=s[i]-'0';
 	dp[1][i][i]=s[i]-'0';
 }

 for(int l=2;l<=(n/2)+1;l++){
	 for(int i=0;i+(l-1)*2<n;i+=2)
	 {
	 	int j=i+(l-1)*2;
	 	dp[0][i][j]=1e18;
	 	dp[1][i][j]=-1e18;
	 	for(int r:{0,1})
	 	for(int p=0;p<2;p++)
	 	{
	 		for(int q=0;q<2;q++)
	 		{
	 			for(int k=i+1;k<j;k+=2){
	 			
	 			if(s[k]=='-')
	 			{	
	 				if(r)
	 				dp[r][i][j]=max(dp[r][i][j],dp[p][i][k-1]-dp[q][k+1][j]);
	 				else
	 				dp[r][i][j]=min(dp[r][i][j],dp[p][i][k-1]-dp[q][k+1][j]);
	 				
	 			}
	 			else if(s[k]=='*')
	 			{
	 				if(r)
	 				dp[r][i][j]=max(dp[r][i][j],dp[p][i][k-1]*dp[q][k+1][j]);
	 				else
	 				dp[r][i][j]=min(dp[r][i][j],dp[p][i][k-1]*dp[q][k+1][j]);
	 				
	 			}
	 			else
	 			{
	 				if(r)
	 				dp[r][i][j]=max(dp[r][i][j],dp[p][i][k-1]+dp[q][k+1][j]);
	 				else
	 				dp[r][i][j]=min(dp[r][i][j],dp[p][i][k-1]+dp[q][k+1][j]);
	 				
	 			}
	 			}
	 		}
	 	}
	 } 
 }
 cout<<dp[1][0][n-1];



}
/*
5-8+7*4-8+9
ans:200
Explanation:200 = (5 − ((8 + 7) × (4 − (8 + 9))))
*/
