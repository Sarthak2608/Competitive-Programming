/*
1 based indexing
https://www.spoj.com/problems/LCA/
https://codeforces.com/blog/entry/18369
*/
#include <bits/stdc++.h>
using namespace std;
int n,u,x,v,n1;
const int N=2e6+5;
int tm1;
vector<vector<int>> adj(N); 
vector<int> inv(N),level(N),parent(N),first(N),last(N);
 
vector<int> ord;
 
 
class sparseTable
{
public:
  static const int N=2e6+5;
  int n,k;
  vector<vector<int>> sparse;
  vector<int> a;
  sparseTable()
  {
      sparse=vector<vector<int>>(N,vector<int>(24));
  } 
  //1based 
  void init(int n1,vector<int> &a1)
  {
        n=n1;
        k=log2(n);
        a=a1;
        preprocess();
  }
  void preprocess(){
         for(int j=0;j<=k;j++)
         {
            for(int i=1;i<=n;i++)
            {
              if(j==0)
              {
                sparse[i][j]=a[i];
                sparse[i][j]=a[i];
                continue;
              }
                if((i+(1ll<<j)-1)>n)
                    continue;
 
              sparse[i][j]=min(sparse[i][j-1],sparse[i+(1ll<<(j-1))][j-1]);
            }
         }
  }
  int minQuery(int l,int r)
  {
    int jump=log2(r-l+1);
    int mn=min(sparse[l][jump],sparse[l+(r-l+1-(1ll<<jump))][jump]);
    return mn;
  }
}sT;
 
void dfs(int node,int l,int p)
{
    ++tm1;
    ord.push_back(tm1);
    inv[tm1]=node;
    first[node]=ord.size()-1;
 
    level[node]=l;
    parent[node]=p;
    for(auto child:adj[node])
    {
        if(child!=p)
        {
           
            dfs(child,l+1,node);
            ord.push_back(ord[first[node]]);
        }
    }
 
  
}
 
int LCA(int x,int y)
{
  if(x==y)
    return x;
   if(first[x]>first[y])
    swap(x,y);
   return inv[sT.minQuery(first[x]+1,first[y]+1)];  
}
 
 
void init()
{
    ord.clear();
    tm1=0;
    for(int i=0;i<=n;i++)
    {
      adj[i].clear();
    }
}
 
int main() {
  int t,tt=1;
  cin>>t;
  while(t--)
  {
      cout<<"Case "<<tt<<":"<<endl;
      tt++;
      cin>>n;
      init();
      for(int i=1;i<=n;i++)
      {
          cin>>x;
          for(int j=1;j<=x;j++)
          {
              cin>>v;
              adj[i].push_back(v);
              adj[v].push_back(i);
          }
      }
      

      tm1=0;  
      dfs(1,0,0);
      ord.insert(ord.begin(),0);
      sT.init(ord.size()-1,ord);


      int q;
      cin>>q;
      while(q--)
      {
          cin>>u>>v;
          cout<<LCA(u,v)<<endl;
      }
  }
  return 0;
}
 
/*
*/
