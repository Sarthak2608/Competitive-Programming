/*
Preprocess:O(nlogn)
Query:O(1)
youtube.com/watch?v=c5O7E_PDO4U
https://codeforces.com/contest/359/submission/75752540
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
 
 int n;
 cin>>n;
 int a[n+1];
 for(int i=1;i<=n;i++)
 {
 	cin>>a[i];
 }
 
 int k=log2(n);
 int sparse[n+1][k+1][2];  
 memset(sparse,0,sizeof(sparse));
 for(int j=0;j<=k;j++)
 {
    for(int i=1;i<=n;i++)
    {
    	if(j==0)
    	{
    		sparse[i][j][0]=a[i];
    		sparse[i][j][1]=a[i];
    		continue;
    	}
        if((i+(1ll<<j)-1)>n)
            continue;

    sparse[i][j][0]=min(sparse[i][j-1][0],sparse[i+(1ll<<(j-1))][j-1][0]);
    sparse[i][j][1]=__gcd(sparse[i][j-1][1],sparse[i+(1ll<<(j-1))][j-1][1]);	
    }
 }

 int q;
 cin>>q;
 while(q--)
 {
    int l,r;
    cin>>l>>r;
    int jump=log2(r-l+1);
    int mn=min(sparse[l][jump][0],sparse[l+(r-l+1-(1ll<<jump))][jump][0]);
    int g=__gcd(sparse[l][jump][1],sparse[l+(r-l+1-(1ll<<jump))][jump][1]);
    cout<<"Minimum Element from "<<l<<" to "<<r<<" = "<<mn<<endl;
    cout<<"GCD from "<<l<<" to "<<r<<" = "<<g<<endl;
 }


}
