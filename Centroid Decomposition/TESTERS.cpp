/*

Reference:https://www.youtube.com/watch?v=3pk02p1-weU&t=2540s

Select the centroid of the tree then solve the problem of the subtree of the centroid and then block the centroid 
,then solve the subproblem of the subtree by finding their subtree centroid 
Time Compleity:O(n(LogN)(LogN))
T(n)=T(n/2)+O(nLogN)



*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
#define int long long 


vector<vector<int>> v;
vector<int> abt,block,par;

vector<int> bit,bit2,size;
int sz=0,mxn,offset,ans;

void update(int node,int val)
{
    node=-node;
    node+=offset;
    for(;node<=mxn;node+=node&(-node)){
    bit[node]+=val;
    bit2[node]++;
    }
}

array<int,2> get(int node)
{
    node=-node;
    node+=offset;
    int x=0,y=0;
    for(;node>0;node-=node&(-node)){
    x+=bit[node];
    y+=bit2[node];
    }
    return {x,y};
}

void dfs(int node,int p)
{
    sz++;
    size[node]=1;
    for(auto i:v[node])
    {
        if(i==p||block[i])
        continue;
        dfs(i,node);
        size[node]+=size[i];
    }
}
int centroid,bestsize;
void dfs2(int node,int p)
{
    
    int x=0,mx=0;
    for(auto i:v[node])
    {
        if(i==p||block[i])
        continue;
        dfs2(i,node);
        x+=size[i];
        mx=max(mx,size[i]);
    }
    mx=max(mx,sz-1-x);
    if(mx<bestsize){
    centroid=node;
    bestsize=mx;
    }
}

void solve(int node,int p)
{
   sz=0;
   dfs(node,node);
   centroid=node;
   bestsize=sz;
   dfs2(node,node);
   node=centroid;
   //cout<<"centroid: "<<centroid<<" "<<sz<<endl;
  mxn=2*sz+20;
  offset=sz+10;
  bit=vector<int>(mxn);
  bit2=vector<int>(mxn);
   
  for(auto i:v[node])
  {
      if(block[i])
      continue;
      //cout<<i<<endl;
       
      vector<array<int,2>> buf;
      queue<array<int,3>> q;
      q.push({i,abt[node]+abt[i],2});
      par[i]=node;
      while(!q.empty())
      {
          int u=q.front()[0];
          int s=q.front()[1];
          int d=q.front()[2];
          //cout<<u<<" "<<s<<" "<<d<<" "<<node<<" "<<par[u]<<endl;
          q.pop();
          if(s>=0)
          ans+=d;
          auto t=get(-s);
        //  cout<<t[0]<<" "<<t[1]<<endl;
          ans=ans+t[0]+t[1]*d;
          buf.push_back({s,d});
          for(auto c:v[u])
          {
                if(block[c]||c==par[u])
                     continue;
                par[c]=u;
                q.push({c,s+abt[c],d+1});
          }
      }
      //cout<<"ans="<<ans<<endl;
      for(auto j:buf)
      {
         // cout<<j[0]-abt[node]<<" "<<j[1]-1<<endl;
          update(j[0]-abt[node],j[1]-1);
      }
  }
  if(abt[node]>0)
  ans++;
  //cout<<ans<<endl;
   block[node]=1;
//   return;
   for(auto i:v[node])
   {
       if(block[i])
       continue;
       solve(i,i);
   }
}

signed main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    ans=0;
    int x,y;
    int mxn=15*(1e5);
    int sum[mxn+1]={0};
    for(int i=1;i<=mxn;i++)
    {
        for(int j=i;j<=mxn;j+=i)
        sum[j]=(sum[j]+(i%10*i%10))%10;
    }
    
	int n;
	cin>>n;
	par=vector<int>(n+1);
	size=vector<int>(n+1);
	block=vector<int>(n+1);
	abt=vector<int>(n+1);
	v=vector<vector<int>>(n+1);
	for(int i=1;i<n;i++)
	{
	    cin>>x>>y;
	    v[x].push_back(y);
	    v[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
	    cin>>x;
	    abt[i]=(sum[x]&1)==0?-1:1;
	    //cout<<abt[i]<<" ";
	}
	solve(1,1);
	//cout<<endl;
	cout<<ans;
	//cout<<endl;
	return 0;
}
