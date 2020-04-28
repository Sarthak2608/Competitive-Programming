/*
 https://www.codechef.com/COW42020/problems/COW3G
 ref: https://www.codechef.com/viewsolution/32401675
 my : https://www.codechef.com/viewsolution/32409543
 Idea 1:
 make all possible contribution into the lcm from one integer with all possible prime number and the greedily select other integer
 
 Idea 2:
 brute force ,sort in descending order the select i and then iterate j=i to n till the product of a[j]*a[i]>ans
 
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
int fp(int a,int b){
	if(b==0) return 1;
	int x=fp(a,b/2);
	x=(x*x)%mod;
	if(b&1) x=(x*a)%mod;
	return x;
}
const int N=1e5+5;

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

 
 int present[N]={0};


 int n;
 cin>>n;
 int a[n+1];
 for(int i=1;i<=n;i++)
 {
 	cin>>a[i];
 	vector<pair<int,int>> v;
 	for(int j=2;j*j<=a[i];j++)
 	{
        if(a[i]%j==0)
        {
        	int x=1;
        	while(a[i]%j==0)
        	{
        		x*=j;
        		a[i]/=j;
        	}
        	v.push_back({j,x});
        }
 	}
 	if(a[i]>1)
 		v.push_back({a[i],a[i]});

       

        for(int j=1;j<(1ll<<v.size());j++)  //Try all combination of base of prime
        {
             int at=1;    //p1*p2*p3
             int val=1;   //p1^a*p2^b*p3^c
             for(int b=0;b<v.size();b++)
             {
                if(j&(1ll<<b))
                {
                   at*=v[b].first;
                   val*=v[b].second;  
                }
             }
             if(present[at]<val)
             {
                present[at]=val;
             }
        }
 }
present[1]=1;
int ans=1;
set<pair<int,int>> s;   
for(int i=1;i<N;i++)
{
        if(present[i])
        {
                //Assume in max pair of lcm the contribution from one integer is present[p1*p2]=p1^a*p2^b
                //then it other integer will coprime with it and greedily select the other integer
                for(auto j:s)
                {
                        if(__gcd(j.second,present[i])==1)
                        {
                                ans=max(ans,-present[i]*j.first);
                                break;
                        }
                }
                s.insert({-present[i],i});  //-ve sign used to behave the set as greater
        }
}

cout<<ans;

}
