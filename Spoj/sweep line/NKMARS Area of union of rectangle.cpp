/*
https://www.spoj.com/problems/NKMARS/
https://codeforces.com/blog/entry/44484?#comment-290165

Using this approach we can find the number of positive element in a range with range updates

  Time Complexity : O(nlogn)
  sort the events by x coordinate
  then activate the segment from y1 to y2 at x1
  then at all x
  add the small area=(x-prevx)*(total active y points)
  
  In segment tree each node(l to r) ,
  sum denote the (r-l+1)
  a1 denotes the left element in range is active or not
  a2 denotes the  right element in range is active or not
  ans denotes the total active element in a range from l to r if p[node]=0
  if p[node]!=0 means the we have to increment the value in range from l to r then all element will be positive
  
  deactivate the segment from y1 to y2 at x2
*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int mod=1e9+7;

const int N=300005;

struct event 
{
    int y1,y2;
    int act;
};

struct node
{
  int p,a1,a2;
  int ans;
  int sum;
  node()
  {
    p=0;
    ans=0;
    sum=0;
  }
};

vector<event> v[N];
vector<node> bit(4*N);


int ask(int id)
{
  if(bit[id].p)
  {
     //cout<<bit[id].sum<<endl;
     bit[id].a1=1;
     bit[id].a2=1;
     return bit[id].sum;
  }
  return bit[id].ans;
}

void build(int id,int l,int r)
{
  if(l==r)
  {
    bit[id].sum=0;
    return;
  }
  int mid=(l+r)/2;
  build(2*id,l,mid);
  build(2*id+1,mid+1,r);
  bit[id].sum=r-l;
}

void neutral(int id)
{
  bit[id].ans=ask(2*id)+ask(2*id+1);
  if(!bit[id].p){
     if(bit[2*id].a2==1&&bit[2*id+1].a1==1){
        bit[id].ans+=1;
     }
  }
  bit[id].a1=bit[2*id].a1;
  bit[id].a2=bit[2*id+1].a2;
}

void update(int id,int l,int r,int L,int R,int val)
{
  if(l>R||r<L)
    return;
  if(L<=l&&r<=R)
  {
      bit[id].p+=val;
      if(bit[id].p==0)
      {
        bit[id].a1=0;
        bit[id].a2=0;
        if(l!=r)
        {
           neutral(id);           
        }
      }
      //cout<<l<<" "<<r<<" "<<bit[id].p<<endl;
      return;
  }
  int mid=(l+r)/2;
  update(2*id,l,mid,L,R,val);
  update(2*id+1,mid+1,r,L,R,val);
  neutral(id);
 // cout<<l<<" : "<<r<<" "<<bit[id].ans<<endl;
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 map<int,int> mp;
 int n,x1,x2,y1,y2;
 cin>>n;
 
 for(int i=1;i<=n;i++)
 {
  cin>>x1>>y1>>x2>>y2;
  x1++;
  x2++;
  y1++;
  y2++;
  struct event e;
  e.y1=y1;
  e.y2=y2;
  e.act=1;
  v[x1].push_back(e);
  e.act=-1;
  v[x2].push_back(e);
  mp[x1];
  mp[x2];
 }
 build(1,1,300000);
 int ans=0,tot=0;
 int px=mp.begin()->first;
 for(auto i:mp)
 {
    int x=i.first;
    auto it=ask(1);
    //cout<<x<<" "<<it<<endl;
    ans+=it*(x-px);
    px=x;
    for(auto e:v[x])
    {
      update(1,1,300000,e.y1,e.y2,e.act);
    }
 }
 cout<<ans;


}
