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
vector<int> v[N],vis(N),col(N);
int n;
bool dfs(int node,int c)
{
  vis[node]=1;
  col[node]=c;
  for(auto i:v[node])
  {
    if(!vis[i])
    {
      if(!dfs(i,c^1))
        return false;
    }
    else if(col[i]==col[node])
    {
      return false;
    }
  }
  return true;
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int m,ans=0,x,y;
 cin>>n>>m;

 for(int i=1;i<=m;i++)
 {
   cin>>x>>y;
   v[x].push_back(y);
   v[y].push_back(x);
 }


 for(int i=1;i<=n;i++)
 {
   if(!vis[i])
   {
      if(!dfs(i,0))
      {
        cout<<"Yes Odd cycle is present";
        return 0;
      }
   }
 }
 cout<<"No";

}
