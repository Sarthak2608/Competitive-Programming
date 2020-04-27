/*
https://www.spoj.com/problems/MKTHNUM/
https://www.youtube.com/watch?v=DQY3CQK4Ar0
*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
const int N=1e5+5;
int a[N];
int Invf[N];
struct node
{
  int val;
  int l;
  int r;
  node()
  {
    val=0;
    l=r=0;
  }
};
vector<vector<node>> bit(4*N);


void build(int id,int l,int r)
{
   if(l==r)
   {
     node n;
     bit[id].push_back(n);
     return;
   }
   int mid=(l+r)/2;
   build(2*id,l,mid);
   build(2*id+1,mid+1,r);
   node n;
   bit[id].push_back(n);
}


int update(int id,int l,int r,int point,int prev,int val)
{
  if(point<l||r<point)
    return bit[id].size()-1;
  if(l==point&&point==r)
  {
     node n;
     n.val=val;
     bit[id].push_back(n);
     return bit[id].size()-1;
  }
  int mid=(l+r)/2;
  node n;
  n.l=bit[id][prev].l;
  n.r=bit[id][prev].r;
  if(point<=mid)
  {
     n.l=update(2*id,l,mid,point,n.l,val);
  }
  else
  {
     n.r=update(2*id+1,mid+1,r,point,n.r,val);
  }
  n.val=bit[2*id][n.l].val+bit[2*id+1][n.r].val;
  bit[id].push_back(n);
  return bit[id].size()-1;
}

int get(int id,int l,int r,int T1,int T2,int k)
{
  if(l==r)
  {
    return l;
  }
  int mid=(l+r)/2;
  
  int x=bit[2*id][bit[id][T2].l].val-bit[2*id][bit[id][T1].l].val;
  if(x>=k)
  {
    return get(2*id,l,mid,bit[id][T1].l,bit[id][T2].l,k);
  }
  return get(2*id+1,mid+1,r,bit[id][T1].r,bit[id][T2].r,k-x);

}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 int n,q;
 cin>>n>>q;

 map<int,int> mp;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  mp[a[i]];
 }
 int id=0;
 for(auto &i:mp)
 {
   i.second=++id;
   Invf[id]=i.first;
 }
 for(int i=1;i<=n;i++)
 {
   a[i]=mp[a[i]];
 }
 cout<<endl;
 map<int,int> freq;
 build(1,1,id);
 int link[n+1];
 link[0]=0;
 for(int i=1;i<=n;i++)
 {
    freq[a[i]]++;
    link[i]=update(1,1,id,a[i],link[i-1],freq[a[i]]);
 }
 

 while(q--)
 {
  int l,r,k;
  cin>>l>>r>>k;
  int x=get(1,1,id,link[l-1],link[r],k);
  cout<<Invf[x]<<endl;


 }




}
