/*
Run bfs on all possible (9!) grid
https://cses.fi/problemset/task/1670/


https://www.codechef.com/viewsolution/36765926
*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ar array<int,2>
#define inf 1000000000000000000 
int mod=1e9+7;
int min(int a,int b){return (a<b)?a:b;}
int max(int a,int b){return (a>b)?a:b;}
int fp(int a,int b){if(b==0) return 1;int x=fp(a,b/2);x=(x*x)%mod;if(b&1) x=(x*a)%mod;return x;}



unordered_map<int,int> steps;



signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 

 int v[3][3];
 int tmp[9];


 queue<int> q; 

 int x1=0,z1=1;
 for(int i=0;i<3;i++)
 {
  for(int j=0;j<3;j++)
  {
      x1+=z1*(i*3+j+1);
      z1*=10;
  } 
 }

 q.push(x1);
 steps[x1]=0;

 auto get=[&]()->int{
  int y=0,z=1;
  for(int i=0;i<9;i++)
  {
    y+=tmp[i]*z;
    z*=10;
  }
  return y;
 };

for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
      cin>>tmp[i*3+j];
    }
}
int fin=get();

 while(!q.empty())
 {
    int g=q.front();
    int s=steps[g];
    if(g==fin)
    {
      cout<<s;
      return 0;
    }
    for(int i=0;i<9;i++)
    {
      tmp[i]=g%10;
      g/=10;
    }

    for(int k=0;k<9;k++)
    {
      int i=k/3;
      int j=k%3;
       if(i+1<3)
        {
            swap(tmp[i*3+j],tmp[(i+1)*3+j]);
            int y=get();
            if(!steps.count(y))
            {
              q.push(y);
              steps[y]=s+1;
            }
            swap(tmp[i*3+j],tmp[(i+1)*3+j]);
        }
        if(j+1<3)
        {
            swap(tmp[i*3+j],tmp[i*3+j+1]);
            int y=get();
            if(!steps.count(y))
            {
              q.push(y);
              steps[y]=s+1;
            }
            swap(tmp[i*3+j],tmp[i*3+j+1]);
        }

    }


    q.pop();
 }


cout<<-1;



}

/*
2 1 3
7 5 9
8 4 6
*/
