/*
 https://infoarena.ro/problema/matrice2
 https://www.youtube.com/watch?v=_q7aMi-5Uos
 https://codeforces.com/blog/entry/75369
*/

#include <fstream>
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long


int n;
 int node(int &i,int &j)
{
  return (i-1)*n+j;
}
vector<vector<int>> query;
vector<int> par;
vector<map<int,int>> st;

int find(int &a)
{
  if(par[a]==a)
    return a;
  return par[a]=find(par[a]);
}
int a,b;
void  addedge(int &val,int &a1,int &b1)
{
   a=find(a1);
   b=find(b1);
   if(st[a].size()<st[b].size())
    swap(a,b);

   if(a==b)
    return ;

   for(auto i:st[b])
   {
    if(st[a].find(i.first)==st[a].end())
    {
       
       st[a][i.first]=1;
    }
    else
    {
      query[i.first][4]=val; 
       st[a].erase(i.first);
    }
   }
   par[b]=a;
   st[b].clear();

}

signed main() {
ifstream in("matrice2.in");
ofstream out("matrice2.out");
  
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 int q;
 in>>n>>q;
 par=vector<int>(n*n+1);
 st=vector<map<int,int>>(n*n+1);

 for(int i=1;i<=n*n;i++)
   par[i]=i;

 query=vector<vector<int>>(q+1,vector<int>(5));
 int v[n+1][n+1];

 for(int i=1;i<=n;i++)
 {
  for(int j=1;j<=n;j++)
  {
    in>>v[i][j];
  }
 }
 int nx,ny;
 vector<array<int,3>> edges;
 int dx[]={1,-1,0,0};
 int dy[]={0,0,1,-1};

 for(int i=1;i<=n;i++)
 {
  for(int j=1;j<=n;j++)
  {
      for(int k=0;k<4;k++)
      {
        nx=i+dx[k];
        ny=j+dy[k];
        if(nx<1||ny<1||nx>n||ny>n)
          continue;

        edges.push_back({min(v[i][j],v[nx][ny]),node(i,j),node(nx,ny)});

      }
  }
 }

 sort(edges.begin(),edges.end());
 reverse(edges.begin(),edges.end());


 for(int i=1;i<=q;i++)
 {
  in>>query[i][0]>>query[i][1]>>query[i][2]>>query[i][3];
   if(query[i][0]==query[i][2]&&query[i][1]==query[i][3])
  {
    query[i][4]=v[query[i][0]][query[i][1]];
    continue;
  }

  st[node(query[i][0],query[i][1])][i]=1;
  st[node(query[i][2],query[i][3])][i]=1;
 }
  
 for(auto i:edges)
 {
  addedge(i[0],i[1],i[2]);
 } 

 for(int i=1;i<=q;i++){
  out<<query[i][4]<<'\n';
  
}
in.close();
out.close();

}
