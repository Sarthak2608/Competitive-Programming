/*
https://www.youtube.com/watch?v=CpZh4eF8QBw
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int mod=1e9+7;
int min(int a,int b){
  return (a<b)?a:b;
}
int max(int a,int b){
  return (a>b)?a:b;
}


signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

 string a;
 cin>>a;
// the z box is from l to r 
 int l=0,r=0;
 int z[a.size()+1]={0};
 for(int i=1;i<a.size();i++)
 {
    if(i>r)
    {
      //brute force
       l=i;
       r=i;
       while(r<a.size()&&a[r-l]==a[r])
       {
          r++;
       }
       z[i]=r-l;
       r--;
    }
    else
    {
      // pattern[0 to r-l-1] = pattern[l to r]    
      int k1=i-l;
      if(z[k1]+i<r)
      {
        //  at i total possible matches don't touch the Z box then copy the value
        z[i]=z[k1];
        continue;
      }
      l=i;
      //brute force
      while(r<a.size()&&a[r-l]==a[r])
      {
          r++;
      }
      z[i]=r-l;
      r--;
    }

 }
 int ans=0;

 for(int i=0;i<a.size();i++)
 {
  cout<<z[i]<<" ";
 }
 cout<<ans<<endl;
 
}
