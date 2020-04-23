#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
vector<int> freq(100005),mp(100005);
int ans=1;

void add(int x)
{
  freq[mp[x]]--;
  mp[x]++;
  freq[mp[x]]++;
  if(mp[x]>ans)
    ans++;
}

void remove(int x)
{
  freq[mp[x]]--;
  mp[x]--;
  freq[mp[x]]++;
  if(freq[ans]==0)
    ans--;
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

 int n,q;

 cin>>n>>q;
 int a[n+1];
 
 for(int i=0;i<n;i++)
 {
  cin>>a[i];
 }
 vector<array<int,3>> query(q);
 for(int i=0;i<q;i++)
 {
  cin>>query[i][0]>>query[i][1];
  query[i][2]=i;
 }

 int blk=sqrt(n);

 sort(query.begin(),query.end(),[&](array<int,3> a , array<int,3> b){

  int lf=a[0]/blk;
  int rf=b[0]/blk;
  if(lf==rf)
    return a[1]<b[1];
  return lf<rf;
 });
 int l=0;
 int r=0;
 freq[0]=n-1;
 mp[a[0]]++;
 freq[1]=1;
 int res[q];
 for(int i=0;i<q;i++)
 {
    int L=query[i][0];
    int R=query[i][1]; 
    while(L<l)
    {
       l--;
       add(a[l]);
    }
    while(r<R)
    {
      r++;
      add(a[r]);
    }

    while(L>l)
    {
      remove(a[l]);
      l++;
    }

    while(r>R)
    {
      remove(a[r]);
      r--;
    }
    res[query[i][2]]=ans;
 }
 for(int i=0;i<q;i++)
  cout<<res[i]<<endl;

 


}
