/*
https://codeforces.com/contest/242/problem/E
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
const int N=4e5+5;
int bit[N][22][3];
int a[N];
void propagate(int id)
{
  for(int j=0;j<22;j++)
  {
    bit[2*id][j][2]^=bit[id][j][2];
    bit[2*id+1][j][2]^=bit[id][j][2];
    bit[id][j][2]=0;
  }
}

void update(int id,int l,int r,int L,int R,int x)
{
   if(l>R||r<L)
    return ;
   if(L<=l&&r<=R)
   {
      for(int j=0;j<22;j++)
      {
        if((x>>j)&1)
        {
          bit[id][j][2]^=1;
        }
      }
      return;
   }
   propagate(id);
   int mid=(l+r)/2;
   update(2*id,l,mid,L,R,x);
   update(2*id+1,mid+1,r,L,R,x);
   for(int j=0;j<22;j++)
   {
    int x=bit[2*id][j][2];
    int y=bit[2*id+1][j][2];
    bit[id][j][0]=bit[2*id][j][x]+bit[2*id+1][j][y];
    bit[id][j][1]=bit[2*id][j][1^x]+bit[2*id+1][j][1^y];
   }
}

int get(int id,int l,int r,int L,int R)
{
  int ans=0;
  if(l>R||r<L)
    return 0;
  if(L<=l&&r<=R)
  {
    for(int j=0;j<22;j++)
    {
      int x=bit[id][j][2];
      ans+=bit[id][j][1^x]*(1ll<<j);
    }
    return ans;
  }
  propagate(id);
  int mid=(l+r)/2;
  ans=get(2*id,l,mid,L,R)+get(2*id+1,mid+1,r,L,R);
  for(int j=0;j<22;j++)
  {
    int x=bit[2*id][j][2];
    int y=bit[2*id+1][j][2];
    bit[id][j][0]=bit[2*id][j][x]+bit[2*id+1][j][y];
    bit[id][j][1]=bit[2*id][j][1^x]+bit[2*id+1][j][1^y];
  }
  return ans;

}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 memset(bit,0,sizeof(bit));
 for(int i=1;i<N;i++)
  for(int j=0;j<22;j++)
    bit[i][j][0]=1;

 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  update(1,1,n,i,i,a[i]);
 }

 int typ,l,r,x;
 int q;
 cin>>q;
 while(q--)
 {
    cin>>typ;
    if(typ==1)
    {
      cin>>l>>r;
      cout<<get(1,1,n,l,r)<<endl;

    }
    else
    {
      cin>>l>>r>>x;
      update(1,1,n,l,r,x);
    }
 }
  
}
