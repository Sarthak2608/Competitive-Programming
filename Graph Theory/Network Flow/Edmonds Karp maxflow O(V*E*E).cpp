/*
O(V*E*E)
Simply run bfs from source to other unvisited vertices if it has capacity greater than zero 
then when we reach the destination then backtrack the path and take the min of the flow of path 
then subrtract the capacity by min of the path and increase the capacity of opposite path
Repeat the Process till there is no augmented path.


https://www.youtube.com/watch?v=GiN3jRdgxU4  Tushar Roy
https://www.youtube.com/watch?v=LdOnanfc5TM
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int min(int a,int b){
  return (a<b)?a:b;
}
int max(int a,int b){
  return (a>b)?a:b;
}

const int N=200;
int v[N][N];
int n=200;   //number of vertices

int EdmondsKarp()
{
   vector<int> vis(n+1),par(n+1);
   queue<int> q;
   int src='A';
   int des='Z';
   q.push(src);
   vis[src]=1;
   while(!q.empty())
   {
     int node=q.front();
     if(node==des)
     {
        vector<int> path;
        int mn=INT_MAX;
        while(node!=src)
        {
           path.push_back(node);
           mn=min(mn,v[par[node]][node]);
           node=par[node];
        }
        path.push_back(src);
        for(int i=0;i<path.size()-1;i++)
        {
            v[path[i+1]][path[i]]-=mn;
            v[path[i]][path[i+1]]+=mn;
        }

        //augmented path 
        for(int i=path.size()-1;i>=0;i--)
          cout<<char(path[i])<<" ";
        cout<<endl;
        return mn;
     }
     q.pop();
     for(int i=1;i<=n;i++)
     {
        if(v[node][i]>0&&!vis[i])
        {
            q.push(i);
            vis[i]=1;
            par[i]=node;
        }
     }
   }
   return 0;
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 memset(v,0,sizeof(v));
 int m;
 cin>>m;
 char x,y;
 int w;
 for(int i=1;i<=m;i++)
 {
   cin>>x>>y>>w;
   v[x][y]+=w;
 }
 int flow,maxflow=0;
 do
 {
    flow=EdmondsKarp();
    maxflow+=flow;
 }while(flow!=0);
 cout<<maxflow;

}
/*
5
A B 3
B C 3
C D 5
D Z 4
B Z 6


*/
