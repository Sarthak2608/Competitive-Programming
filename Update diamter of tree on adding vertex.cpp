/*
 https://codeforces.com/problemset/problem/379/F
 https://codeforces.com/blog/entry/10171?#comment-156540
 
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
const int N=1e6+5;
int level[N],par[N]; 
int dp[N][25];

void add(int node)
{
  for(int i=1;i<21;i++)
  {
    dp[node][i]=dp[dp[node][i-1]][i-1];
  }
}

int LCA(int a,int b)
{
  int dis=0;
  if(level[a]>level[b])
    swap(a,b);
  int dif=level[b]-level[a];
  while(dif>0)
  {
    int jump=log2(dif);
    b=dp[b][jump];
    dis+=1ll<<jump;
    dif-=(1ll<<jump);
  }
 

  while(a!=b)
  {
    int jump=log2(level[a]);
    while(jump>0&&dp[a][jump]==dp[b][jump])
      jump--;
    dis+=(1ll<<(jump+1));
    a=dp[a][jump];
    b=dp[b][jump];
  }

  return dis;
}


signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int q,x;
 cin>>q;
 memset(dp,0,sizeof(dp));
 int d1=2,d2=3;  //End point of the diameter
 int dis=2;
 level[1]=0;     
 level[2]=1;
 level[3]=1;
 level[4]=1;


 dp[1][0]=0;
 dp[2][0]=1;
 dp[3][0]=1;
 dp[4][0]=1;

 int nxt=5,a,b;
 while(q--)
 { 
   cin>>x;
   a=nxt;
   b=nxt+1;

   dp[a][0]=x;
   dp[b][0]=x;
   
   level[a]=level[x]+1;
   level[b]=level[x]+1;
   add(a);
   add(b);
   int nd1=d1,nd2=d2;
   int ndis=dis;

   int temp1=LCA(a,d1);
   if(temp1>ndis)
   {
      ndis=temp1;
      nd1=d1;
      nd2=a;
   }

   int temp2=LCA(a,d2);
   if(temp2>ndis)
   {
      ndis=temp2;
      nd1=a;
      nd2=d2;
   }
   
   d1=nd1;
   d2=nd2;
   dis=ndis;
   cout<<ndis<<endl;
   nxt+=2;
 }
  
}
