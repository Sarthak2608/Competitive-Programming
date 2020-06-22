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
 int n,a,b;
 cin>>n>>a>>b;
 queue<int> q;
 int v[n+1];
 int sm[n+1],mx[n+1];
 int s=0;
 sm[0]=0;
 mx[0]=0;
 
 for(int i=1;i<=n;i++)
 {
    cin>>v[i];
    sm[i]=sm[i-1]+v[i];
 }

 for(int i=1;i<=n;i++)
 {
    s+=v[i];
    q.push(v[i]);
    while(s<0||q.size()>b-a)
    {
        s-=q.front();
        q.pop();
    }
    mx[i]=s;
 }
 int ans=-1e18;
 for(int i=a;i<=n;i++)
 {
    ans=max(ans,sm[i]-sm[i-a]+mx[i-a]);
 }
 cout<<ans;


}
