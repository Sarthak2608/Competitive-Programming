/*
https://codeforces.com/problemset/problem/552/D
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

const int N=2e5+5;


signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

 int n;
 cin>>n;
 int a[n+1][2];
 for(int i=1;i<=n;i++)
 {
    cin>>a[i][0]>>a[i][1];
 }
 int ans=0;
 for(int i=1;i<=n;i++)
 {
    vector<array<int,2>> v;
    for(int j=1;j<=n;j++)  
    {
        if(i==j) continue;
        int dy=a[i][1]-a[j][1];
        int dx=a[i][0]-a[j][0];
        if(dx==0)
        {
            dy=1;
        }
        if(dy==0)
        {
            dx=1;
        }
        if(dx<0){
            dx*=-1;
            dy*=-1;
        }
        int g=__gcd(abs(dx),abs(dy));
        dx/=g;
        dy/=g;
        v.push_back({dx,dy});
    }
    int ct=0;
    sort(v.begin(),v.end());
    for(int j=0;j<v.size();j++)
    {
        ct++;
        if(j+1<v.size()&&v[j]==v[j+1])
            continue;
        ans+=ct*(n-ct-1);  //ct=number of points lie on the line start from i having solve v[j]
        ct=0;
    }
 }
 ans/=6;
 cout<<ans;

}
