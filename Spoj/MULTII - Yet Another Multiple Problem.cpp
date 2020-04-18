/*
https://codeforces.com/blog/entry/70068?#comment-545746
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int mark[10];
int ans=0;
int n;



signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

 int t=1,tt,x,m;

 while(cin>>n)
 {
 
  vector<int> vis(n+5);
  vector<array<int,2>> par(n+5);
  memset(mark,0,sizeof(mark));
  cin>>m;
  for(int i=1;i<=m;i++)
  {
    cin>>x;
    mark[x]=1;
  }
  vector<int> temp;
  queue<int> q;
  q.push(0);
  while(!q.empty())
  {
    int node=q.front();
    q.pop();
    vis[node]=1;
    for(int i=0;i<=9;i++)
    {
      if((node==0&&i==0)||mark[i])
      {
        continue;
      }
      
      int nxt=(node*10+i)%n;
      if(!vis[nxt])
      {
        vis[nxt]=1;
        par[nxt]={node,i};
        q.push(nxt);
      }
      if(nxt==0&&temp.size()==0)
      {
          temp.push_back(i);
          int x=node;
          while(x!=0)
          {
            temp.push_back(par[x][1]);
            x=par[x][0];
          }
      }
     
 
    }
  }

  reverse(temp.begin(),temp.end());
  
  cout<<"Case "<<t<<": ";
  if(temp.size()!=0)
  for(int i=0;i<temp.size();i++)
  {
    cout<<temp[i];
  }
  else
    cout<<-1;

  cout<<endl;
  t++;
 }


}

/*
2345 3
7 8 9
*/
