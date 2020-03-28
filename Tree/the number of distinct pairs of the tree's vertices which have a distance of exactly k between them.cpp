/*
 Time Complexity:O(nk)
 Idea : calculate the number of nodes from each node which are at k distance .
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int n,k,ans=0;
vector<vector<int>> v,dp;

void dfs(int node,int p)
{
	//cout<<node<<endl;
	
	for(auto i:v[node])
	{
		if(i==p)
			continue;
		dfs(i,node);
		for(int j=1;j<=k;j++)
		{
			dp[node][j]+=dp[i][j-1];
		}
	}
	dp[node][0]=1;
}

void dfs2(int node,int p)
{
	ans+=dp[node][k];
	for(auto i:v[node])
	{
		if(i==p)
			continue;
		for(int j=k;j>=1;j--)
		{
			dp[i][j]+=dp[node][j-1];
			if(j-2>=0)
			dp[i][j]-=dp[i][j-2];
		}
		dfs2(i,node);
	}
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int x,y;
 cin>>n>>k;
 v=vector<vector<int>>(n+1);
 dp=vector<vector<int>>(n+1,vector<int>(k+1));
 for(int i=1;i<n;i++)
 {
 	cin>>x>>y;
 	v[x].push_back(y);
 	v[y].push_back(x);
 }
 dfs(1,1);
 dfs2(1,1);
 cout<<ans/2;

}
