/*
 sort the query according to block id ,if tie then sort the query by r in increasing order
 Time Complexity: O(qlogq+Nsqrt(N))
*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

struct query
{
  int l,r,id;
};

vector<int>  mp(1000005);
int ans=0;
void remove(int e)
{
      mp[e]--;
      if(mp[e]==0)
      {
        ans--;
      }
}
void add(int e)
{
      mp[e]++;
      if(mp[e]==1)
      {
        ans++;
      }
}
void solve()
{
  int n;
  cin>>n;
  vector<int> v(n);
  unordered_map<int,int> mp2;
  for(int i=0;i<n;i++)
  {
      cin>>v[i];
      mp2[v[i]];
  }
  int cnt=1;
  for(auto &i:mp2)
  {
    i.second=cnt++;
  }
  for(auto &i:v)
    i=mp2[i];
  int blkSize=sqrtl(n);
  int q;
  cin>>q;
  int res[q];
  vector<query> Qr(q);
  for(int i=0;i<q;i++)
  {
     cin>>Qr[i].l>>Qr[i].r;
     Qr[i].l--;
     Qr[i].r--;
     Qr[i].id=i;
  }
  sort(Qr.begin(), Qr.end(),[&](query a,query b){
     if(a.l/blkSize!=b.l/blkSize)
     {
      return a.l<b.l;
     }
     return a.r<b.r;
  });

  int Ml=0,Mr=0;
  add(v[0]);
  for(auto i:Qr)
  {
     int l=i.l;
     int r=i.r;

     while(Ml>i.l)
     {
      Ml--;
      add(v[Ml]);
     }

     while(Mr<i.r)
     {
      Mr++;
      add(v[Mr]);
     }

     while(Ml<i.l)
     {
      remove(v[Ml]);
      Ml++;
     }
   
     while(Mr>i.r)
     {
      remove(v[Mr]);
      Mr--;
     }

     res[i.id]=ans;

  }
  for(int i=0;i<q;i++)
    cout<<res[i]<<"\n";
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 solve();


}

/*
6
1 1 2 3 5 8
1
1 4
1 3
3 6
*/
