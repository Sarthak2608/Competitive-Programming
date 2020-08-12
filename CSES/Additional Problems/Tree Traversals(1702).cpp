/*
https://cses.fi/problemset/task/1702/
*/
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
vector<int> pre(N),ino(N),mp(N);
void s(int l1,int l2,int n)
{
    if(n<=0)return;
    int r=pre[l1];
    int x=mp[r];
    s(l1+1,l2,x-l2);
    s(l1+x-l2+1,x+1,n-x+l2-1);
    cout<<r<<" ";
}
int main(){
  int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>pre[i];
    for(int i=0;i<n;i++)
        cin>>ino[i],
        mp[ino[i]]=i;
    s(0,0,n);
}
