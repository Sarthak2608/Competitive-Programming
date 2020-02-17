#include <bits/stdc++.h>
using namespace std;
#define int long long int
int p1,p2,p3,x,y,n,tim,mxn=1e5+5;
vector<vector<int>> v;
vector<int> visit,st,en,bit,size;
vector<vector<pair<int,int>>>h;

void update(int x)
{
    for(;x<=n;x+=(x&-x))
    {
        bit[x]++;
    }
}


int sum(int x)
{
    int ans=0;
    for(;x>0;x-=(x&-x))
    {
        ans+=bit[x];
    }
    return ans;
}

int dfs(int node)
{
    st[node]=++tim;
    update(node);
    int sm=sum(node),sm1;
    sm1=sm;
    int sz,szz=0;
    
    for(auto i:v[node])
    {
        if(!st[i])
        {
            sz=dfs(i);
            size[node]+=sz;
            x=sum(node);
            h[node].push_back({x-sm,sz-x+sm});
            sm=x;
        }
    }
    size[node]++;
    int y=node-1-(sm-sm1);
    h[node].push_back({y,n-size[node]-y});
    en[node]=tim;
    
//    cout<<node<<" "<<st[node]<<" "<<en[node]<<" "<<size[node]<<endl;
    
    return size[node];
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
	    tim=0;
	    cin>>n;
	    v=vector<vector<int>>(n+1);
	    h=vector<vector<pair<int,int>>>(n+1);
	    st=vector<int>(n+1);
	    en=vector<int>(n+1);
	    size=vector<int>(n+1);
	    bit=vector<int>(mxn);
	    cin>>p1>>p2>>p3;
	    for(int i=1;i<n;i++)
	    {
	        cin>>x>>y;
	        v[x].push_back(y);
	        v[y].push_back(x);
	    }
	    dfs(1);
	    
	    if(p2==1)
	    {
	        int ans=0;
	        for(int i=1;i<=n;i++)
	        {
	            int nn=h[i].size();
	            if(nn<2)
	            continue;
	            int xx=n-i;
	            
	           for(int j=0;j<nn;j++)
	           {
	            ans+=h[i][j].second*(xx-h[i][j].second);
	           }
	        }
	        cout<<ans/2<<endl;
	    }
	    else if(p2==2)
	    {
	        int ans=0;
	        for(int i=1;i<=n;i++)
	        {
	            int nn=h[i].size();
	            if(nn<2)
	            continue;
	            int xx=n-i;
	            
	           for(int j=0;j<nn;j++)
	           {
	            ans+=h[i][j].first*(xx-h[i][j].second);
	           }
	        }
	        cout<<ans<<endl;
	    }
	    else
	    {
	        int ans=0;
	        for(int i=1;i<=n;i++)
	        {
	            int nn=h[i].size();
	            if(nn<2)
	            continue;
	            int xx=i-1;
	            
	           for(int j=0;j<nn;j++)
	           {
	            ans+=h[i][j].first*(xx-h[i][j].first);
	           }
	        }
	        cout<<ans/2<<endl;
	    }
	    
	}
	return 0;
}
