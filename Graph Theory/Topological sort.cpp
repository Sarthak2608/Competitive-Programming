/*
https://cses.fi/problemset/task/1679/

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
vector<int> v[N],indeg(N);
int n;

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int m,x,y;
 cin>>n>>m;
 for(int i=1;i<=m;i++)
 {
  cin>>x>>y;
  v[x].push_back(y);
  indeg[y]++;
 }
 queue<int> q;
 for(int i=1;i<=n;i++)
 {
  if(indeg[i]==0){
    q.push(i);
  }
 }
 vector<int> ans;
 while(!q.empty())
 {
    int node=q.front();
    ans.push_back(node);
    q.pop(); 
    for(auto i:v[node])
    {
      indeg[i]--;
      if(indeg[i]==0)
      {
        q.push(i);
      }
    }
 }
 if(ans.size()==n)
 {
    for(auto i:ans)
      cout<<i<<" ";
 }
 else
 {
    cout<<"IMPOSSIBLE";
 }



}
