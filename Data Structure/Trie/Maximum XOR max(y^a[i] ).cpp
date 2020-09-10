#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define ar array<int,2>
#define inf 1000000000000000000 
int mod=1e9+7;
int min(int a,int b){return (a<b)?a:b;}
int max(int a,int b){return (a>b)?a:b;}



const int N=2e5+5;
int cost=0;

struct node{
  int ct;
  int l,r;
  node()
  {
    ct=0;
    l=-1;
    r=-1;
  }
};

class trie
{
public:
  int sz;
  vector<node> bit;
  trie()
  {
    node o;
    sz=0;
    bit.push_back(o);
  }

  void insert(int id,int b,int y)
  {
    if(b==-1)
    {
      bit[id].ct++;
      return ;
    }
    int x=(y>>b)&1,nxt;
    if(x==0)
    {
      if(bit[id].l==-1){
        node o;
        bit.push_back(o);
        bit[id].l=++sz;
      }
      nxt=bit[id].l;
    }
    else{
      if(bit[id].r==-1){
        node o;
        bit.push_back(o);
        bit[id].r=++sz;
      }
      nxt=bit[id].r;
    }

    insert(nxt,b-1,y);
  }

  int get(int id,int b,int y)
  {
    if(b==-1)
    {
      return 0;
    }
    int x=(y>>b)&1,nxt,z=0;
    if(x==1){
      if(bit[id].r!=-1){
      nxt=bit[id].r;
      }
      else{
      nxt=bit[id].l;
      z=(1ll<<b);
      }
    }
    else{
      if(bit[id].l!=-1){
      nxt=bit[id].l;
      }
      else{
      nxt=bit[id].r;
      z=(1ll<<b);
      }
    }
    if(nxt==-1){
      return inf;
    }
    return get(nxt,b-1,y)+z;
  }
};


signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 

  trie obj;
  obj.insert(0,30,3);
  cout<<obj.get(0,30,2)<<endl;

}
