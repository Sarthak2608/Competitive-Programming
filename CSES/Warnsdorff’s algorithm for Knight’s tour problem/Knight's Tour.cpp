/*
https://www.geeksforgeeks.org/warnsdorffs-algorithm-knights-tour-problem/
https://cses.fi/problemset/task/1689/
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

const int N=8;
int ans[N+1][N+1];

int dx[]={2,2,-2,-2,1,-1,1,-1};
int dy[]={1,-1,1,-1,2,2,-2,-2};

int isvalid(int x,int y)
{
  if(x>=1&&y>=1&&x<=N&&y<=N&&ans[x][y]==0)
      return 1;
    return 0;
}

int degree(int x,int y)
{
  int ct=0;
  for(int i=0;i<8;i++)
  {
    if(isvalid(x+dx[i],y+dy[i]))
      ct++;
  }
  return ct;
}
void print()
{
  for(int i=1;i<=N;i++)
       {
        for(int j=1;j<=N;j++)
          cout<<ans[i][j]<<" ";
        cout<<endl;
       }
}

bool solve(int x,int y,int v)
{
    //cout<<x<<" "<<y<<endl;

    if(v==N*N){
      ans[x][y]=v;
       print();
      return 1;
    }
    
  
    vector<array<int,2>> tmp;
    for(int i=0;i<8;i++)
    {
      int nx=x+dx[i];
      int ny=y+dy[i];
      if(!isvalid(nx,ny)) continue;
      int d1=degree(nx,ny);
      tmp.push_back({d1,i});
    }


    sort(tmp.begin(),tmp.end());
    ans[x][y]=v;
    for(auto i:tmp)
    {
      int nx=x+dx[i[1]];
      int ny=y+dy[i[1]];
      int ok=solve(nx,ny,v+1);
      if(ok)
        return 1;
    }

    ans[x][y]=0;
    return 0;
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int x,y;
 cin>>x>>y;
 memset(ans,0,sizeof(ans));
 int ok=solve(y,x,1);

  
}
