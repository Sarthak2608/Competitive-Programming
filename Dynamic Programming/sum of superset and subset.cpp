#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long


//https://codeforces.com/blog/entry/45223
//ans[i]=A[x] where x is the subset of i such that x&i=x
//N is the number of bits
vector<int> countSumOfSubset(int N,vector<int> &A){
    vector<int> F(1ll<<N); 
    for(int i = 0; i<(1<<N); ++i)
        F[i] = A[i];
    for(int i = 0;i < N; ++i) for(int mask = 0; mask < (1<<N); ++mask){
        if(mask & (1<<i))
            F[mask] += F[mask^(1<<i)];  // here you can do anything
    }
    return F;
}
 

//ans[i]=A[x] where i is the subset of x such that x&i=i
vector<int> countSumOfSuperSet(int N,vector<int> &A){
    vector<int> F(1ll<<N),F2(1ll<<N); 
    int msk=(1ll<<N)-1;
    for(int i = 0; i<(1<<N); ++i){
        F[msk^i] = A[i];
    }
    for(int i = 0;i < N; ++i) for(int mask = 0; mask < (1<<N); ++mask){
        if(mask & (1<<i))
            F[mask] += F[mask^(1<<i)];
    }

    for(int i = 0; i<(1<<N); ++i)
        F2[msk^i] = F[i];
    return F2;
}
 

 
void solve()
{
    int N;
    cin>>N;
    vector<int> a(1ll<<N);
    //cout<<a.size()<<endl;
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        assert(a.size()>x);
        a[x]++;
    }



    auto b=countSumOfSubset(N,a);
    for(int i=0;i<b.size();i++){
        cout<<i<<" "<<b[i]<<endl;
    }



    cout<<endl;
    auto c=countSumOfSuperSet(N,a);
    for(int i=0;i<c.size();i++){
        cout<<i<<" "<<c[i]<<endl;
    }    

}
 
signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 srand(time(0));
 int t=1;
// cin>>t;
 for(int i=1;i<=t;i++){
   solve();
 }
}
