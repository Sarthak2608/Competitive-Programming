/*
  Problem Link:https://codeforces.com/contest/514/problem/D
  Idea:Iterate all possible length l of killing consecutive elements in logN
  using binary search 
  for each each iteration ,calculate the cost of killing consecutive element 
  of length l using queue which maintains the maximum element in a length l.
  Another Solution :https://codeforces.com/contest/514/submission/45492951
*/
#include <bits/stdc++.h>
using namespace std;
 
 
signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int n,m,k;

 cin>>n>>m>>k;
 int a[n+1][m+1];
 for(int i=1;i<=n;i++)
 {
   for(int j=1;j<=m;j++)
   {
     cin>>a[i][j];
   }
 }
 vector<int> res;
 int lw=1;
 int hw=n;
 int ans=0;
 while(lw<=hw)
 {
  int f=0;
  int mid=(lw+hw)/2;
  deque<int> q[m+1];
    
  for(int i=1;i<=n;i++)
  {
    int sm=0;
    vector<int> tmp;
    for(int j=1;j<=m;j++)
    {
       
       while(!q[j].empty()&&q[j].front()<a[i][j])
       {
        q[j].pop_front();
       }
       q[j].push_front(a[i][j]);
      
       if(i>=mid)
       {
        tmp.push_back(q[j].back());
         sm+=q[j].back();
         if(!q[j].empty()&&q[j].back()==a[i-mid+1][j])
          q[j].pop_back();
       }
    }

    if(i>=mid)
    {
      if(sm<=k)
      {
        f=1;
        if(ans<mid)
        {
          ans=mid;
          res=tmp;
        }
        break;
      }
    }
    
  } 


  if(!f)
  {
    hw=mid-1;
  }
  else
  {
    lw=mid+1;
  }
 }

 if(res.size()==0)
 {
  res.push_back(k);
  for(int i=2;i<=m;i++)
    res.push_back(0);
 }

 for(auto i:res)
 {
  cout<<i<<" ";
 }


}
