/*
https://codeforces.com/contest/920/problem/E
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int n,m,x,y;
const int N=200005;
vector<set<int>> v(N);
set<int> s;
int sz;
void dfs(int node)
{
   sz++;
   vector<int> temp;
   for(auto i:s)
   {
   	if(v[node].find(i)==v[node].end())
   	{
       temp.push_back(i);
   	}
   }
   for(auto i:temp)
   {
   	s.erase(i);
   }
   for(auto i:temp)
   {
   	dfs(i);
   }
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 cin>>n>>m;
 for(int i=1;i<=n;i++)
 	s.insert(i);
 for(int i=1;i<=m;i++)
 {
 	cin>>x>>y;
 	v[x].insert(y);
 	v[y].insert(x);
 }
 vector<int> ans; 
 for(int i=1;i<=n;i++)
 {
 	if(s.find(i)!=s.end())
 	{
 		s.erase(i);
 		sz=0;
 		dfs(i);
 		ans.push_back(sz);
 	}
 }
 sort(ans.begin(), ans.end());
 cout<<ans.size()<<endl;
 for(auto i:ans)
 	cout<<i<<" ";

}
