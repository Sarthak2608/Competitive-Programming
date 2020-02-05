#include <bits/stdc++.h>
using namespace std;
#define int long long int 
vector<vector<int>> v;
vector<int> visit,a,parent,ans,beg,en,tree;
int cur=0;
void dfs(int node)
{
    visit[node]=1;
    cur++;
    beg[node]=cur;
    for(auto i:v[node])
    {
        if(!visit[i])
        {
            dfs(i);
        }
    }
    en[node]=cur;
   // cout<<node<<" "<<beg[node]<<" "<<en[node]<<endl;
}

void update(int start,int end,int val)
{
    for(;start<=end;start=start+(start&-start))
    {
        tree[start]+=val;
    }
}

int getSum(int start)
{
    int s=0;
    for(;start>=1;start=start-(start&-start))
    {
        s+=tree[start];
    }
    return s;
}



signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,x,y;
	cin>>n;
	a=vector<int>(n+1);
	v=vector<vector<int>>(n+1);
	visit=vector<int>(n+1);
	beg=vector<int>(n+1);
	en=vector<int>(n+1);
	tree=vector<int>(n+1);
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
	dfs(1);
	for(int i=1;i<=n;i++)
	{
	    update(beg[i],n,a[i]*a[i]);
	}
	int q,type,u,val,sum;
	cin>>q;
	while(q--)
	{
	   cin>>type>>u;
	   if(type==1)
	   {
	       cin>>val;
	       update(beg[u],n,-a[u]*a[u]+val*val);
	       a[u]=val;
	   }
	   else
	   {
	       sum=getSum(en[u])-getSum(beg[u]-1);
	       cout<<sum<<endl;
	   }
	}
	return 0;
}
