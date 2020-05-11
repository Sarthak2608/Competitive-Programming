/*
https://codeforces.com/blog/entry/45578
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int unsigned long long
int mod=1e9+7;
int min(int a,int b){
  return (a<b)?a:b;
}
int max(int a,int b){
  return (a>b)?a:b;
}
const int N=3e5+15;
const int mxn=N;
vector<int> bit(mxn); 
vector<int> v[N],tocheck[N];
int req[N];

void update(int node,int v)
{
  for(;node<mxn;node+=(node&(-node)))
  {
    bit[node]+=v;
  }
}

int get(int node)
{
  int x=0;
  for(;node>0;node-=(node&(-node)))
  {
      x+=bit[node];
  }
  return x;
}

void range(int l,int r,int a)
{
  if(l<=r)
  {
     update(l,a);
     update(r+1,-a);
  }
  else
  {
    update(1,a);
    update(r+1,-a);
    update(l,a);
  }
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 int n,m,x;
 cin>>n>>m;
 for(int i=1;i<=m;i++)
 {
    cin>>x;
    v[x].push_back(i);
 }

 for(int i=1;i<=n;i++)
 {
  cin>>req[i];
 }

 int q;
 cin>>q;
 vector<array<int,3>> qr(q+1);
 
 int lw[n+1];
 int hg[n+1];
 int ans[n+1];
 //memset(ans,-1,sizeof(ans));
 for(int i=1;i<=n;i++)
 {
   ans[i]=INT_MAX;
   lw[i]=1;
   hg[i]=q;
 }

 for(int i=1;i<=q;i++)
 {
   cin>>qr[i][0]>>qr[i][1]>>qr[i][2];
 }
 int changed=true;
 while(changed)  //Time Complexity : O(logq)
 {
    changed=false; 
    for(int i=1;i<=n;i++)
    {
      if(lw[i]<=hg[i])
      {
         changed=true;
         int mid=(lw[i]+hg[i])/2;
         tocheck[mid].push_back(i);
      }
    }
    for(int i=1;i<mxn;i++)
    {
      bit[i]=0;
    }

    for(int i=1;i<=q;i++)  //O(qlog(mxn))  log(mxn) comes due to the update in fenwick tree
    {
       range(qr[i][0],qr[i][1],qr[i][2]);
       for(auto j:tocheck[i])
       {
          int x=0;
          for(auto k:v[j])
          {
            x+=get(k);
          }
          if(x>=req[j])
          {
            ans[j]=i;
            hg[j]=i-1;
          }
          else
          {
            lw[j]=i+1;
          }
       }
       tocheck[i].clear();
    }

    
 }
 for(int i=1;i<=n;i++)
 {
  if(ans[i]==INT_MAX)
    cout<<"NIE\n";
  else
    cout<<ans[i]<<endl;
 }


}
