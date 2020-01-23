#include <bits/stdc++.h> 
using namespace std; 
#define int long long int
vector<vector<int>> v;

void dfs(int node,int par,vector<int> &dis)
{
    // cout<<node<<" "<<dis[node]<<endl;
     for(auto i:v[node])
     {
          if(i!=par)
          {
               dis[i]=dis[node]+1;
               dfs(i,node,dis);
          }
     }
}
signed main()
{
  
    int n,x,y;
    cin>>n;
    v= vector<vector<int>>(n+1);
    for(int i=1;i<=n-1;i++)
    {
         cin>>x>>y;
         v[x].push_back(y);
         v[y].push_back(x);
    }
    vector<int> dis(n+1);
    dfs(x,-1,dis);
    int c=0,a=-1;
    for(int i=1;i<=n;i++)
    {
         if(dis[i]>c)
         {
              c=dis[i];
              a=i;
         }
    }
   // cout<<a<<endl;
    
    vector<int> dis2(n+1);
    dfs(a,-1,dis2);
    int b=-1;
    c=0;
    for(int i=1;i<=n;i++)
    {
         if(dis2[i]>c)
         {
              c=dis2[i];
              b=i;
         }
    }
  //  cout<<b<<endl;
    

     cout<<a<<" "<<b<<" ";
    return 0;
}
