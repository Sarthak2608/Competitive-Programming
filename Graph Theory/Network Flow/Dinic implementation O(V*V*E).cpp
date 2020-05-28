/*
https://open.kattis.com/problems/maxflow
https://cp-algorithms.com/graph/dinic.html
https://www.youtube.com/watch?v=M6cm8UeeziI

O(V*V*E)

step 1) make level graph using bfs
step 2) run dfs till the augmented path is found
and simulataneously block the path if the path does not end at sink
step 3) repeat step 1 till path is found

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

const int N=505,M=20005;
vector<array<int,2>> v[N];
vector<int> edgeId(M),flow(M);
int n;
map<array<int,2>,int> mp;
class Dinic
{
public:
  int src,des,n;
  vector<int> lvl,nxt;
  vector<array<int,2>> path;
  Dinic()
  {
    lvl=vector<int>(N);
    nxt=vector<int>(N);
  }
  void init(int n1,int Src,int Des)
  {
      n=n1;
      src=Src;
      des=Des;
      for(int i=1;i<=n;i++)
      { 
        v[i].clear();
      }
  }
  bool bfs()
  {
    queue<int> q;
    q.push(src);
    fill(lvl.begin(),lvl.end(),-1);
    lvl[src]=0;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto i:v[node])
        {
           if(lvl[i[0]]!=-1||edgeId[i[1]]==0)
              continue;
            q.push(i[0]);
            lvl[i[0]]=lvl[node]+1;
        }
    }
    return lvl[des]!=-1;
  }
  int dfs(int node,int push)
  {
     if(push==0||node==des){
      if(node==des)
      path.push_back({des,-1});
      return push;
     }

    for(;nxt[node]<v[node].size();nxt[node]++,path.clear())
    {
       int id=v[node][nxt[node]][1];
       int y=v[node][nxt[node]][0];
       if(edgeId[id]==0||lvl[node]+1!=lvl[y])
        continue;
      int f=dfs(y,min(push,edgeId[id]));
      if(f==0)
        continue;
    
      flow[id]+=f;
      path.push_back({node,id});
      return f;
    }
    return 0;
  }
  
  int maxflow()
  {
      int mx=0;
      while(bfs())
      {
          fill(nxt.begin(),nxt.end(),0);
          for(int f;f=dfs(src,INT_MAX);){
            if (f==0)
            {
               path.clear();
               break;
            }
              reverse(path.begin(),path.end());
              for(int j=0;j<path.size()-1;j++)
              {
                edgeId[path[j][1]]-=f;
                edgeId[path[j][1]^1]+=f;

                int x=path[j][0];
                int y=path[j+1][0];
                int f1=f;
                if(x>y)
                {
                  swap(x,y);
                  f1*=-1;
                }
                auto it=mp.find({x,y});
                if(it!=mp.end())
                {
                    it->second+=f1;
                }
                else
                {
                  mp[{x,y}]=f1;
                }

              }
              //print augmented path
              // for(auto j:path)
              //   cout<<j[0]<<" ";
              // cout<<endl;
              mx+=f;
              path.clear();
          }
      }
      return mx;
  }
};

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 Dinic d;
 int x,y,src,des,m,c;
 cin>>n>>m>>src>>des;
 d.init(n,src,des);
 int id=-1;
 for(int i=1;i<=m;i++)
 {
   cin>>x>>y>>c;
   v[x].push_back({y,++id});
   edgeId[id]=c;
   v[y].push_back({x,++id});
 }

 

 int f=d.maxflow();
 vector<array<int,3>> ans;
 for(int i=0;i<n;i++)
 {
   for(auto j:v[i])
   {
      if((flow[j[1]]-flow[j[1]^1])>0)
      {
          ans.push_back({i,j[0],flow[j[1]]-flow[j[1]^1]});
      }
   }
 }
 
 cout<<n<<" "<<f<<" "<<ans.size()<<endl;
 for(auto i:ans)
 {
   
   cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
 }




}
/*
4 5 0 3
0 1 10
1 2 1
1 3 1
0 2 1
2 3 10
*/
