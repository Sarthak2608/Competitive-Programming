/*
Tarjans Strongly Connected Components algorithm
https://www.youtube.com/watch?v=TyWtx7q2D7Y

Kosaraju's Algorithm:
In the strong connected components ,all nodes are reachable to each other.

First run dfs and store the path of dfs when all node are visited. then transpose the graph,run the dfs again on a random node and
color the all the discocvered node through random node. 



Problem:https://codeforces.com/problemset/problem/999/E
first find the strong connected component then assume each connected component as a node and make the new graph ,solve the problem.
Fact :In this new graph there will no cycle.

*/

#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 5010;
vector<vector<int>> v1(N),v2(N),ng(N);
vector<int> vis(N),col(N),indegree(N);

vector<int> ord;

void dfs1(int node,int p)
{
	//cout<<node<<endl;
	vis[node]=1;
	for(auto i:v1[node])
	{
		if(i==p)
			continue;
		if(!vis[i])
		dfs1(i,node);
	}
	ord.push_back(node);
}
int cnt=0;
void dfs2(int node,int p)
{
	col[node]=cnt;
	vis[node]=1;
	for(auto i:v2[node])
	{
       if(i==p)
			continue;
		if(!vis[i])
		dfs2(i,node);
	}
} 

void dfs3(int node,int p)
{
	//cout<<node<<endl;
	vis[node]=1;
	for(auto i:ng[node])
	{
		if(i==p)
			continue;
		if(!vis[i])
		dfs3(i,node);
	}
	//ord.push_back(node);
}


int main() {

int n,m,s,x,y;
cin>>n>>m>>s;

for(int i=1;i<=m;i++)
{
	cin>>x>>y;
	v1[x].push_back(y);
	v2[y].push_back(x);
}

for(int i=1;i<=n;i++)
{
	if(!vis[i]){
     dfs1(i,-1);
	}
}


vis=vector<int>(N);



reverse(ord.begin(), ord.end());
for(auto i:ord)
{
	if(!vis[i]){
		cnt++;
     dfs2(i,-1);
	}
}

for(int i=1;i<=n;i++)
{
	for(auto j:v1[i])
	{
		if(col[i]!=col[j]){
			indegree[col[j]]++;
		ng[col[i]].push_back(col[j]);
	    }
	}
}
vis=vector<int>(N);
dfs3(col[s],-1);
int ans=0;
for(int i=1;i<=cnt;i++)
{
	if(!vis[i]&&indegree[i]==0)
		ans++;
}
cout<<ans;

}
