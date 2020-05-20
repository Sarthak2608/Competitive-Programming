/*
https://codeforces.com/problemset/problem/756/C

from
l to r
bit[node].push stores the number of element exist in range l to r  
bit[node].pop stores the number of element to be pop (1 to l-1)


*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int min(int a,int b){
  return (a<b)?a:b;
}
int max(int a,int b){
  return (a>b)?a:b;
}
struct node
{
  int push,pop;
  node()
  {
    push=0;       
    pop=0;
  }
};
const int N=1e6+5;
int a[N]={0};
vector<node> bit(4*N);

void update(int id,int l,int r,int point,int x)
{
    if(point<l||point>r)
      return;
    
    if(l==r&&l==point)
    {
        a[l]=x;
        //cout<<l<<" "<<x<<endl;
        if(x==-1)
        {
            bit[id].pop=1;
        }
        else
        {
            bit[id].push=1;
        }
        return;
    }
    int mid=(l+r)/2;
    update(2*id,l,mid,point,x);
    update(2*id+1,mid+1,r,point,x);
    bit[id].pop=bit[2*id].pop;
    bit[id].push=bit[2*id+1].push;

    if(bit[2*id].push>bit[2*id+1].pop)
    {
        bit[id].push+=bit[2*id].push-bit[2*id+1].pop;
    }
    else
    {
        bit[id].pop+=-bit[2*id].push+bit[2*id+1].pop; 
    }
}
int get(int id,int l,int r,int d)
{
    if(bit[id].push==0)
    return -1;

    if(l==r)
    {
      if(d==0)
      {
        return a[l];
      }
        return -1;
    }


    int mid=(l+r)/2;
    if(bit[2*id+1].push-d>0)
    {
      return get(2*id+1,mid+1,r,d);
    }

    d-=bit[2*id+1].push;
    d+=bit[2*id+1].pop; 
    return get(2*id,l,mid,d);
}



signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int n,pos,typ,x;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
   cin>>pos>>typ;
   if(typ==1)
   {
    cin>>x;
    update(1,1,n,pos,x);
   }
   else
   {
     update(1,1,n,pos,-1);
   }
   cout<<get(1,1,n,0)<<endl;
 }

}
