/*
 1.We can sort the integers from 0 to 10^9.
 2.We can also sort negative number , for this before sort we have to add something so that all becomes positive integers then after sort 
   subtract something which is added before.
 2.Time complexity O(max(n,2^16))
*/

#include <bits/stdc++.h>
using namespace std;

 void fastsort(vector<int> &a,int n,int shift)
{
    vector<int> a1(n+1);
    int v=(1<<16)-1;
    int pr[v+5]={0};
    for(int i=1;i<=n;i++)
    {
        pr[((a[i]>>shift)&v)+1]++;
    }
    
    for(int i=1;i<=v+1;i++)
    pr[i]+=pr[i-1];
    
    for(int i=1;i<=n;i++)
    {
        a1[pr[(a[i]>>shift)&v]+1]=a[i];
        pr[(a[i]>>shift)&v]++;
    }
    a=a1;
}
 
 
signed main()
{
    
          int n;
          cin>>n;
          vector<int> v(n+1);
          for(int i=1;i<=n;i++)
          {
               cin>>v[i];
          }
          if(n>10000){
          fastsort(v,2*n,0);
          fastsort(v,2*n,16);
          }
          else
          sort(v.begin()+1,v.end());
}
