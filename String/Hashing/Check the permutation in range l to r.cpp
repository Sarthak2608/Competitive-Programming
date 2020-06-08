/*
https://codeforces.com/problemset/problem/1175/F

generate random hash
sum[i] = hash[1]^hash[2]^...hash[i] 


then for range l to r,check
sum[r-l+1] == hash[a[l]]^hash[a[l+1]]^..hash[a[r]]

Additional
suppose we want to check two multiset are equal or not then we can use
sum[i]=hash[1]^(number of ocuurence of 1 in a multiset)+....
https://codeforces.com/blog/entry/67484?#comment-517219


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

mt19937_64 rnd(time(NULL));
const int N=3e5+5;
void add(array<int,2> &x,array<int,2> y)
{
    x[0]^=y[0];
    x[1]^=y[1];
}
vector<array<int,2>> sm(N),hsh(N);
int n;
vector<int> a;


signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 array<int,2> x;
 x[0]=0;
 x[1]=0;
 sm[0]=x;
 for(int i=1;i<N;i++)
 {
    array<int,2> y;
    y[0]=rnd();
    y[1]=rnd();
    y[1]=y[1]^rnd();
    hsh[i]=y;
    sm[i]=sm[i-1];
    add(sm[i],y);
 }


 cin>>n;
 a=vector<int>(n);
 auto tmp=sm[0];
 for(int i=0;i<n;i++)
 {
    cin>>a[i];
    add(tmp,hsh[a[i]]);
 }

 if(tmp==sm[n])
 {
    cout<<"It is a permutaion";
 }
 else
 {
    cout<<"Not a permutaion";
 }
 


 

}

