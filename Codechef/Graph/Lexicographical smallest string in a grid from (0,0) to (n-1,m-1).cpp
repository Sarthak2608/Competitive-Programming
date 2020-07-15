/*
https://www.codechef.com/COLE2020/problems/CLLEXO

make a graph ,put each node in a graph if it is possible to form a valid string from that node

traverse the graph levelwise

for each level(l) select all lexicographical smallest node in level(l+1)

*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int mod=1e9+7;
int min(int a,int b){
  return (a<b)?a:b;
}
int max(int a,int b){
  return (a>b)?a:b;
}
int fp(int a,int b){
  if(b==0) return 1;
  int x=fp(a,b/2);
  x=(x*x)%mod;
  if(b&1) x=(x*a)%mod;
  return x;
}

vector<vector<char>> v;

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 int t;
 cin>>t;
 while(t--){
  int n,m;
  cin>>n>>m;
   v=vector<vector<char>>(n+1,vector<char>(m+1));

  string s;
  for(int i=0;i<n;i++)
  {
    cin>>s;
    for(int j=0;j<m;j++)
      v[i][j]=s[j];
  }

  int mark[n+2][m+2];
  memset(mark,0,sizeof(mark));

  mark[n-1][m]=1;
  for(int i=n-1;i>=0;i--)
    for(int j=m-1;j>=0;j--){
      if(v[i][j]!='#')
      mark[i][j]=mark[i+1][j]|mark[i][j+1];
    }
    

  char ch1,ch;
  vector<int> q;
  q.emplace_back(0);
  int f,x,y;
  vector<char> ans;

  while(q.size()>0)
  {

    vector<int> temp;
    
    ch='z';
    
    x=q[0]/m;
    y=q[0]%m;
    //cout<<x<<":"<<y<<endl;
    ans.push_back(v[x][y]);
    if(x==n-1&&y==m-1)
      break;

    for(auto &p:q)
    {
        x=p/m;
        y=p%m;
       
        if(x+1<n)
        {
          if(mark[x+1][y]){
            
            if(v[x+1][y]<ch)
            {
              temp.clear();
              ch=v[x+1][y];
            }
            
            if(v[x+1][y]==ch){
            temp.emplace_back((x+1)*m+y);
            }

            mark[x+1][y]=0;
          }
        }
        if(y+1<m)
        {
          
          if(mark[x][y+1]){
            
            if(v[x][y+1]<ch)
            {
              temp.clear();
              ch=v[x][y+1];
            }
            if(v[x][y+1]==ch){
            temp.emplace_back((x)*m+y+1);
           }
           mark[x][y+1]=0;
            
          }
        }
    }
   
    q=temp;

  }

  for(auto i:ans)
    cout<<i;
  cout<<endl;


 }
}

/*

2
3 3
xab
a#z
caa
5 1
a
b
c
d
e


1
4 4
aaaa
bcba
ddd#
aaaa



*/
