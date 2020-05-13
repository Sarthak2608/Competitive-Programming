/*
https://www.spoj.com/problems/SUBXOR/
let x[i] denote the xor of A[1]^..^A[i]
x[i]^x[j]<k denote subarray from j to i have xor <k
so count the number of pair with each i having xor<k

*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
const int N=1e6,B=32;
int bit[N][3],n=1;
void insert(int node,int x,int pos)
{
  bit[node][2]++;
  if(pos==0)
  {
    bit[node][(x>>pos)&1]++;
    return;
  }
   if(!bit[node][(x>>pos)&1])
   {
     bit[node][(x>>pos)&1]=++n;
   }
   insert(bit[node][(x>>pos)&1],x,pos-1);
}

int search(int node,int x,int pos)
{
   if(pos==0)
   {
   
     return bit[node][x&1];
   }
   return search(bit[node][(x>>pos)&1],x,pos-1);
}

int get(int node,int x,int k,int pos)
{
  if(pos==0)
  {
    if(k&1)
    {
      return bit[node][2];
    }
    else
    {
      return bit[node][(x>>pos)&1];
    }
  }
  if((k>>pos)&1)
  {
      return bit[bit[node][(x>>pos)&1]][2]+get(bit[node][1-((x>>pos)&1)],x,k,pos-1);
  }
  else
  {
      return get(bit[node][(x>>pos)&1],x,k,pos-1);
  }
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int t;
 cin>>t;
 while(t--){
 memset(bit,0,sizeof(bit));
 int n,k,x=0,ans=0;
 cin>>n>>k;
 k--;
 int a[n+1];
 insert(1,0,B);
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  x^=a[i];
  int y=get(1,x,k,B);
  ans+=y;
  insert(1,x,B);
 }
 cout<<ans<<endl;
 }


}
