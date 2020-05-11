/*
https://www.hackerrank.com/contests/may-world-codesprint/challenges/travel-in-hackerland/problem
https://codeforces.com/blog/entry/45578
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
const int N=1e5+5;
vector<array<int,3>> edge(N);
vector<int> tocheck[N];
int n,typ[N],par[N],mn[N],sz[N];
map<int,int> mp[N];
void init()
{
  for(int i=1;i<=n;i++)
  {
    mp[i].clear();
    par[i]=i;
    mn[i]=0;
    mp[i][typ[i]];
  }
}

int find(int x)
{
   return (x==par[x])?x:(par[x]=find(par[x]));
}

void unite(int x,int y,int val)
{
  x=find(x);
  y=find(y);
  if(x==y)
    return;
  if(mp[x].size()<mp[y].size())
    swap(x,y);

  for(auto i:mp[y])
  {
    mp[x][i.first];
  }
  mp[y].clear();
  par[y]=x;
  mn[x]=max({mn[x],mn[y],val});
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int m,q,x;
 cin>>n>>m>>q;
 for(int i=1;i<=n;i++)
 {
  cin>>x;
  typ[i]=x;
 }
 for(int i=1;i<=m;i++)
 {
    cin>>edge[i][1]>>edge[i][2]>>edge[i][0];
 }
 sort(edge.begin()+1,edge.begin()+m+1);

 int lw[q+1],hg[q+1],ans[q+1];
 vector<array<int,3>> qr(q+1);
 for(int i=1;i<=q;i++)
 {
    cin>>qr[i][0]>>qr[i][1]>>qr[i][2];
    lw[i]=1;
    hg[i]=m;
    ans[i]=-1;
 }

 bool changed=true;
 
 while(changed)
 {
  changed=false;

  for(int i=1;i<=q;i++)
  {
    if(lw[i]<=hg[i])
    {
      changed=true;
      int mid=(lw[i]+hg[i])/2;
      tocheck[mid].push_back(i);
    }
  }
  init();

  for(int i=1;i<=m;i++)
  {
     unite(edge[i][1],edge[i][2],edge[i][0]);
     for(auto j:tocheck[i])
     {
        int x=find(qr[j][0]);
        int y=find(qr[j][1]);
        if(x==y&&mp[x].size()>=qr[j][2])
        {
          ans[j]=mn[x];
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
 for(int i=1;i<=q;i++)
 {
  cout<<ans[i]<<endl;
 }



}

/*
7 6 2
1 1 4 5 1 3 2
1 2 3
2 6 2
2 3 4
3 4 3
2 4 9
5 7 9
1 2 4
1 7 3

*/
