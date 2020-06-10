
/*
https://cses.fi/problemset/task/1145/
https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
https://codeforces.com/blog/entry/70018

other approch:
iterate from right
let i then using segment tree find 1+max(len(increaseSequence start at j)) such that a[i]<a[j] and i<j

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
int a[N];

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

 int n;
 cin>>n;
 vector<int> dp;

 for(int i=1;i<=n;i++)
 {
    cin>>a[i];
    auto it=lower_bound(dp.begin(), dp.end(),a[i]);
    if(it==dp.end())
        dp.push_back(a[i]);
    else
        *it=a[i];
 }
 cout<<dp.size();


}
