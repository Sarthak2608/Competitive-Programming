/*
https://www.youtube.com/watch?v=Ep1ge5zJ8EM
https://paste.ubuntu.com/p/SJKG87qnT5/
https://www.spoj.com/problems/DYNACON1/
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
const int N=2e5+5;
string op[N]; 
int n,link[N],u[N],v[N],par[N],sz[N];
map<array<int,2>,int> mp;
stack<array<int,3>> st;
int find(int a)  
{
   if(a==par[a])
   {
    return a;
   }
   else
   {
     int x=find(par[a]);
     if(par[a]!=x)
     {
        st.push({1,a,par[a]});
     }
     par[a]=x;
     return x;
   }
}

void unite(int a,int b)  //Unite the two components
{
   a=find(a);
   b=find(b);
   if(a==b)
    return;
   if(sz[a]<sz[b])
   {
      swap(a,b);
   }
   //size of b is smaller
   par[b]=a;
   st.push({1,b,b});
   sz[a]+=sz[b];
   st.push({2,a,sz[b]});
}

void rollback(int t)  
{
  while(st.size()>t)
  {
    int typ=st.top()[0];
    int x=st.top()[1];
    int y=st.top()[2];
    if(typ==1)
    {
        par[x]=y;
    }
    else
    {
        sz[x]-=y;
    }
    st.pop();
  }
}


void solve(int l,int r)
{
   if(l==r)
   {
    if(op[l]=="conn")
    {
      
      int a=find(u[l]);
      int b=find(v[l]);
      
      if(a==b)
      {
        cout<<"YES\n";
      }
      else
      {
        cout<<"NO\n";
      }
    }
    return;
   }
   int mid=(l+r)/2;
   int now=st.size();

   for(int i=mid+1;i<=r;i++)
   {
    if(link[i]==0)  //skip the query
      continue;
        if(link[i]<l) 
        {
           unite(u[i],v[i]);  //unite the component,because the edge[i] exist in the time l to mid 
        }
   }
   solve(l,mid);
   rollback(now);  //Rollback updates until stack size is now

   for(int i=l;i<=mid;i++)
   {
    if(link[i]==0)
      continue;
      if(link[i]>r)
      {
          unite(u[i],v[i]);  //unite the component,because the edge[i] exist in the time mid+1 to r 
      }
   }
   solve(mid+1,r);
   rollback(now);

}

void init()
{
  for(int i=1;i<=n;i++)
  {
    par[i]=i;
    sz[i]=1;
  }
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int k,x,y;

 cin>>n>>k;
 init();
 for(int i=1;i<=k;i++)
 {
    cin>>op[i]>>x>>y;
    if(x>y)
      swap(x,y);
    u[i]=x;
    v[i]=y;

    if(op[i]=="add")
    {
        mp[{x,y}]=i;
    }
    else if(op[i]=="rem")
    {
        auto it=mp.find({x,y});  //link[i] store the index of moment when the edge is added and vice versa
        link[it->second]=i;
        link[i]=it->second;
        mp.erase(it);
    }
 } 
 for(auto i:mp)  //Remove all edges after the kth query
 {
   k++;
   op[k]="rem";
   link[i.second]=k;
   link[k]=i.second;
   u[k]=i.first[0];
   v[k]=i.first[1];
 }
 solve(1,k);

}
