#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long


class sqrtDecomposition
{
  public:
  int n;
  int blkSize;
  vector<int> v,block;

  sqrtDecomposition(int N)
  {
     n=N;
     v=vector<int>(N);
     blkSize=sqrtl(N);
     block=vector<int>(blkSize+5,INT_MAX);
  }
  
  void contribute(int blkid,int val)
  {
     block[blkid]=min(block[blkid],val);
  }
  
  void init()
  {
    for(int i=0;i<n;i++)
    {
      cin>>v[i];
    }
    
    for(int i=0;i<n;i++)
    {
       contribute(i/blkSize,v[i]);
    }

  }

  void update(int index,int val)  //Time Complexity : sqrt(n)
  {
     v[index]=val;
     int curBlk=index/blkSize;
     block[curBlk]=INT_MAX;
     int i=(curBlk)*blkSize;
     for(;i<n&&i<((curBlk+1)*blkSize);i++)
     {
         contribute(curBlk,v[i]);
     }
  }

  int query(int l,int r)        //Time Complexity : sqrt(n)
  {
    int lfBlk=l/blkSize;
    int rgBlk=r/blkSize;

    int ans=INT_MAX;
    if(lfBlk==rgBlk)
    {
      for(int i=l;i<=r;i++)
      {
        ans=min(ans,v[i]);
      }
      return ans;
    }
    for(int i=l;i<((lfBlk+1)*blkSize);i++)
      ans=min(ans,v[i]);
    for(int i=lfBlk+1;i<rgBlk;i++)
      ans=min(ans,block[i]);
    for(int i=r;i>=(rgBlk)*blkSize;i--)
      ans=min(ans,v[i]);
    return ans;
  }
  

  
};


signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int n,x;
 cin>>n;
 
 sqrtDecomposition s(n);
 s.init();

 int q,l,r;
 cin>>q;
 while(q--)
 {
    cin>>l>>r;
    cout<<s.query(l,r)<<endl;
 }

}
