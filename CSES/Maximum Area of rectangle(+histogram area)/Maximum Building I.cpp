/*
https://cses.fi/problemset/task/1147/

*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define ar array<int,2>
#define inf 1000000000000000000 
int mod=1e9+7;
int min(int a,int b){return (a<b)?a:b;}
int max(int a,int b){return (a>b)?a:b;}
int fp(int a,int b){if(b==0) return 1;int x=fp(a,b/2);x=(x*x)%mod;if(b&1) x=(x*a)%mod;return x;}




const int N=1005;
int v[N][N],sum[N][N];


int histogramarea(vector<int> &v)
{
  int ans=0;
  v.push_back(0);
  stack<array<int,2>> st;

  for(int i=0;i<v.size();i++)
  {
    int last=i;
    while(st.size()>0&&st.top()[0]>=v[i])
    {
      last=st.top()[1];
      ans=max(ans,(i-last)*st.top()[0]);
      st.pop();
    }
    st.push({v[i],last});
  }

  return ans;
}

void solve()
{
  string s;
  int n,m;
  cin>>n>>m;
  int sum[n+2][m+2];
  memset(sum,0,sizeof(sum));
  for(int i=1;i<=n;i++)
  {
    cin>>s;
    for(int j=1;j<=m;j++)
    {
      if(s[j-1]=='*')
        v[i][j]=0;
      else
        v[i][j]=1;
    }
  }


  for(int i=1;i<=n;i++)
  {
    for(int j=m;j>=1;j--)
    {
      if(v[i][j])
      sum[i][j]+=1+sum[i][j+1];
    }
  }

  int ans=0;

  for(int j=1;j<=m;j++)
  {
    vector<int> tmp;
    for(int i=1;i<=n;i++)
    {
      tmp.push_back(sum[i][j]);
    }
    ans=max(ans,histogramarea(tmp));
  }
  cout<<ans<<endl;

}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 srand(time(0));
 int t;
 t=1;
 for(int i=1;i<=t;i++)
 {
   solve();
 }


}
