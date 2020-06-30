/*
calculate the shortest path 
make a new graph such that each edge in a graph should be a part of any shortest path
fact: this graph will we DAG
then calculate the number of shortest path etc using dp
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
int fp(int a,int b){
	if(b==0) return 1;
	int x=fp(a,b/2);
	x=(x*x)%mod;
	if(b&1) x=(x*a)%mod;
	return x;
}
const int N=2e5+5;
int edge[N][3];
vector<vector<array<int,2>>> v1(N),v2(N);
vector<int> v3[N];
vector<int> dis1,dis2;
int n;

void shortestpath(int src,vector<vector<array<int,2>>> &v,vector<int> &dis)
{
	dis[src]=0;
	priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> q;
	q.push({0,src});
	vector<int> vis(n+1);
	while(!q.empty())
	{
		int node=q.top()[1];
		int d=q.top()[0];
		q.pop();
		if(vis[node])
			continue;
		vis[node]=1;
		for(auto i:v[node])
		{
			if(dis[i[0]]>i[1]+d)
			{
				dis[i[0]]=i[1]+d;
				q.push({dis[i[0]],i[0]});
			}
		}
	}
}

int dp[N][3];

array<int,3> dag(int node)
{
	if(node==n)
	{
		return {1,0,0};
	}
	if(dp[node][0]!=-1)
	{
		return {dp[node][0],dp[node][1],dp[node][2]};
	}
    
    array<int,3> ans;
    ans[0]=0;
    ans[1]=1e18;
    ans[2]=0;

    for(auto i:v3[node])
    {
    	auto ar=dag(i);
    	ans[0]=(ans[0]+ar[0])%mod;
    	ans[1]=min(ans[1],1+ar[1]);
    	ans[2]=max(ans[2],1+ar[2]);
    }
    dp[node][0]=ans[0];
    dp[node][1]=ans[1];
    dp[node][2]=ans[2];
    return ans;

}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int m,x,y,z;
 cin>>n>>m;
 
 memset(dp,-1,sizeof(dp));

 for(int i=1;i<=m;i++)
 {
 	cin>>edge[i][0]>>edge[i][1]>>edge[i][2];
 	v1[edge[i][0]].push_back({edge[i][1],edge[i][2]});
 	v2[edge[i][1]].push_back({edge[i][0],edge[i][2]});
 }
 
 dis1=vector<int>(n+1,1e18);
 dis2=vector<int>(n+1,1e18);
 
 shortestpath(1,v1,dis1);
 shortestpath(n,v2,dis2);
 
 for(int i=1;i<=m;i++)
 {
 	int x=edge[i][0];
 	int y=edge[i][1];
 	int w=edge[i][2];

 	if(dis2[y]+dis1[x]+w==dis1[n])
 	{
 		v3[x].push_back(y);
 	}
 }


 auto ar=dag(1);
 
 cout<<dis1[n]<<" "<<ar[0]<<" "<<ar[1]<<" "<<ar[2];



}
