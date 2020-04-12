/*
  sort the query according to r
  if suppose we have to find the answer of the query value of r is i 
  then using prefix sum calculate the required answer
*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int mod=1e9+7;

const int mxn=1e6+5;
int bit[mxn+5]={0};


void update(int node,int val)
{
  for(;node<=mxn;node+=(node&(-node)))
  {
    bit[node]+=val;
  }
}
int get(int node)
{
  int sum=0;
  for(;node>0;node-=(node&(-node)))
    sum+=bit[node];
  return sum;
}
int rangeSum(int l,int r)
{
  int x= get(r)-get(l-1);
  return x;
}


signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

 int n;
 cin>>n;
 int a[n+1];
 map<int,int> mp;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  mp[a[i]];
 }
 int id=0;
 for(auto &it:mp)
  it.second=++id;
 for(int i=1;i<=n;i++)
  a[i]=mp[a[i]]; //Compressing the node to store the index of element
 int q;
 cin>>q;
 vector<array<int,3>> query(q+1);
 for(int i=1;i<=q;i++)
 {
  cin>>query[i][0]>>query[i][1];
  query[i][2]=i;
 }
 

 sort(query.begin()+1,query.end(),[](array<int,3> a,array<int,3> b){
   if(a[1]<b[1])
      return 1;
    if(a[1]>b[1])
      return 0;
    if(a[0]<b[0])
      return 1;
    return 0;
 });

 int ans[q+1];
 int curq=1;
 vector<int> pos[n+1];
 for(int i=1;i<=n;i++)
 {
  int sz=pos[a[i]].size();
  update(i,1);
  if(pos[a[i]].size()>0)
  {
    update(pos[a[i]][sz-1],-2);
  }
  if(pos[a[i]].size()>1)
  {
    update(pos[a[i]][sz-2],1);
  }
  pos[a[i]].push_back(i);

  while(curq<=q&&query[curq][1]==i)
  { 
    int x=rangeSum(query[curq][0],query[curq][1]);
    ans[query[curq][2]]=x;
    curq++;
  }

 }
 for(int i=1;i<=q;i++)
  cout<<ans[i]<<endl;




}
