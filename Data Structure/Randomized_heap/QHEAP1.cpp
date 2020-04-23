/*
https://www.hackerrank.com/challenges/qheap1/problem
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int root;
map<int,int> mp;
struct data
{
  int val;
  int l;
  int r;
  int par;
  data():val(0),l(0),r(0),par(0){}
};

vector<data> Tree(100005);  



int merge(int T1,int T2,int p)
{
  Tree[T1].par=p;
  Tree[T2].par=p;
  if(T1==0||T2==0)
  {
     return T1!=0?T1:T2;
  }
  if(Tree[T1].val>Tree[T2].val)
    swap(T1,T2);
  if(rand()&1)        //Randomly merging with the child for expecting log(n) depth
    swap(Tree[T1].l,Tree[T1].r);
  Tree[T1].l=merge(Tree[T1].l,T2,T1);
  Tree[T1].par=p;
  return T1;
}

void del(int node)
{
  int p=Tree[node].par;   
  int id=merge(Tree[node].l,Tree[node].r,p);  //Merging the child node
  if(p==0)
  {
    root=id;
    return;
  }
  if(Tree[p].l==node)                     //connecting the new merged tree with its parent
    Tree[p].l=id;
  else
    Tree[p].r=id;
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

 int n,x;
 cin>>n;
 int typ;
 int id=1;

 root=0;

 while(n--)
 {
   cin>>typ;
   if(typ==1)
   {
     cin>>x;
     mp[x]=id;             //Creating new node at id
     Tree[id].val=x;
     root=merge(root,id,0); 
     id++;
   }
   else if(typ==2)
   {
    cin>>x;
    del(mp[x]);            //deleting the node with its id 
   }
   else
   {
     cout<<Tree[root].val<<endl;   //min heap
   }
 }

}
