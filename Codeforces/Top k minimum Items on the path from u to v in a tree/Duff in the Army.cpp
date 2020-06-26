/*
https://codeforces.com/problemset/problem/587/C
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
//#define int long long
int min(int a,int b){
	return (a<b)?a:b;
}
int max(int a,int b){
	return (a>b)?a:b;
}
const int N=1e5+15;

vector<int> v[N],city[N];
int par[N],dp[N][18],lvl[N]={0};

priority_queue<int> q[N],dpq[N][18];


int n;

void dfs(int node,int p=0)
{
	lvl[node]=lvl[p]+1;
	par[node]=p;
	for(auto i:v[node])
	{
		if(i==p)
			continue;
		dfs(i,node);
	}
}

void merge(priority_queue<int> &q1,priority_queue<int> &q2)
{
	priority_queue<int> q3=q2;
	while(!q3.empty())
	{
		q1.push(q3.top());
		q3.pop();
	}
	while(q1.size()>10)
	{
		q1.pop();
	}
}

void precompute()
{
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=par[i];
		dpq[i][0]=q[par[i]];
	}

	for(int j=1;j<18;j++)
	{
		for(int i=1;i<=n;i++)
		{
			dp[i][j]=dp[dp[i][j-1]][j-1];
			dpq[i][j]=dpq[i][j-1];
			merge(dpq[i][j],dpq[dp[i][j-1]][j-1]);
		}
	}
}

int isancestor(int x,int y)
{
	int d=lvl[y]-lvl[x];
	while(d>0)
	{
		int jump=log2(d);
		y=dp[y][jump];
		d-=(1ll<<jump);
	}
	if(x==y)
	return 1;
	return 0;	
}

priority_queue<int> LCA(int x,int y,int a)
{
	if(x==y)
		return q[x];

	

	if(lvl[x]>lvl[y])
		swap(x,y);
	int d=lvl[y]-lvl[x];

	priority_queue<int> q1=q[y];
	if(!isancestor(x,y)){
	merge(q1,q[x]);
	}


	while(d>0)
	{
		int jump=log2(d);
		merge(q1,dpq[y][jump]);
		y=dp[y][jump];
		d-=(1ll<<jump);
	}



	while(x!=y)
	{
		int jump=log2(lvl[x]);
		while(jump>0&&dp[x][jump]==dp[y][jump])
		{
			jump--;
		}
		merge(q1,dpq[x][jump]);
		if(dp[x][jump]!=dp[y][jump])
		merge(q1,dpq[y][jump]);
		x=dp[x][jump];
		y=dp[y][jump];
	}
	return q1;
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int x,y,m,query,a;

 cin>>n>>m>>query;
 for(int i=1;i<n;i++)
 {
 	cin>>x>>y;
 	v[x].push_back(y);
 	v[y].push_back(x);
 }

 for(int i=1;i<=m;i++)
 {
 	cin>>x;
 	city[x].push_back(i);
 	q[x].push(i);
 }

 
 for(int i=1;i<=n;i++)
 {
 	while(q[i].size()>10)
 		q[i].pop();
 }

 dfs(1);
precompute(); 
 
 while(query--)
 {
 	cin>>x>>y>>a;
 	auto it=LCA(x,y,a);
 	while(it.size()>a)
 		it.pop();
 	cout<<it.size()<<" ";
 	vector<int> ans;
 	while(!it.empty())
 	{
 		ans.push_back(it.top());
 		it.pop();
 	}
 	reverse(ans.begin(),ans.end());
 	for(auto i:ans)
 		cout<<i<<" ";
 	cout<<endl;

 }



}
