/*
https://codeforces.com/contest/915/problem/F

for max
sort the vertices in ascending order then make the tree with the vertices in order and simulatneously count the the countribution of the current node in all simple paths 
between their children which pass through the current vertex  
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int min(int a,int b){
	return (a<b)?a:b;
}
int max(int a,int b){
	return (a>b)?a:b;
}
const int N=1e6+5;
int a[N],par[N];
int n,sz[N];
vector<int> v[N];

int find(int x)
{
	return (x==par[x])?x:par[x]=find(par[x]);
}


int solve()
{

 int ans=0;

 vector<array<int,2>> ord;
 for(int i=1;i<=n;i++)
 {
 	ord.push_back({a[i],i});
 	par[i]=i;
 	sz[i]=1;
 }

 sort(ord.begin(),ord.end());

 int mark[n+1]={0};

 for(auto j:ord)
 {
 	mark[j[1]]=1;
 	ans+=j[0];
 	int tot=1;
 	int p=find(j[1]);
 	int node=p;

 	for(auto k:v[j[1]])
 	{
 		if(!mark[k])
 			continue;
 		//cout<<k<<":\n";
 		int y=sz[find(k)];
 		if(sz[find(node)]<y)
 			node=find(k);
 		tot+=y;
 	}

 	int tt=tot;
	for(auto k:v[j[1]])
 	{
 		if(!mark[k])
 			continue;
		ans+=(tot-sz[find(k)])*sz[find(k)]*j[0];
 		tot-=sz[find(k)];
 		par[find(k)]=node;
 	} 	

 	par[find(j[1])]=node;
 	sz[node]=tt;

 }


return ans;

}


signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 cin>>n;
 
 int x,y;

 for(int i=1;i<=n;i++)
 {
 	cin>>a[i];
 }

 for(int i=1;i<n;i++)
 {
 	cin>>x>>y;
 	v[x].push_back(y);
 	v[y].push_back(x);
 }



int ans=solve();



 for(int i=1;i<=n;i++)
 {
 	a[i]*=-1;
 }
 
ans+=solve();
cout<<ans;

}

/*


6
2 2 3 1 5 10
1 2
1 3
1 4
2 5
4 6


5
2 2 3 1 5 
1 2
1 3
1 4
2 5

*/
