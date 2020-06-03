/*
https://codeforces.com/problemset/problem/1205/B
remove each edge (x,y)
then using bfs find shortest path from x to y(d) then cycle length is d+1

Time Complexity: O(m*m)


*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int min(int a,int b){
    return (a<b)?a:b;
}
int max(int a,int b){
    return (a>b)?a:b;
}
const int N=2e5+5;
vector<int> v[N],vis(N),dis(N);
int n,ans=INT_MAX;


int bfs(int src,int des)
{

        for(int i=1;i<=n;i++)
        {
            dis[i]=INT_MAX;
        }
        dis[src]=0;
        queue<int> q;
        q.push(src);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto i:v[node])
            {
                if(dis[i]==INT_MAX)
                {
                    q.push(i);
                    dis[i]=dis[node]+1;
                }
            }
        }
        return dis[des];
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int m;
 cin>>n>>m;
 int x,y;

 vector<array<int,2>> edges;

 for(int i=1;i<=m;i++)
 {
   cin>>x>>y;
   edges.push_back({x,y});
 }

 for(int i=0;i<edges.size();i++)
 {
    for(int i=1;i<=n;i++)
        v[i].clear();
    for(int j=0;j<edges.size();j++)
    {
        if(i!=j)
        {
            v[edges[j][0]].push_back(edges[j][1]);
            v[edges[j][1]].push_back(edges[j][0]);
        }
    }
    ans=min(ans,1+bfs(edges[i][0],edges[i][1]));
 }
 if(ans==INT_MAX)
    ans=-1;
cout<<ans;



}


/*
7 8
1 7 
1 6
6 2
2 7
3 7
3 4
4 5
5 2

4
*/
