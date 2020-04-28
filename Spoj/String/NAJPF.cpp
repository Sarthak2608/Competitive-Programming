/*
 https://www.codechef.com/COW42020/problems/COW3G
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

 int n;
 while(cin>>n){
 string a,b,s;
 cin>>a>>b;
 s=a+'#'+b;
 //cout<<s;

 int pi[s.size()+1];
 pi[0]=0;
 int j=0;
 for(int i=1;i<s.size();i++)
 {
        while(j>0&&s[i]!=s[j])
        {
               j=pi[j-1];
        }
        if(s[i]==s[j])
                j++;
        pi[i]=j;
 }
 int f=0;
 //cout<<endl;
 for(int i=0;i<s.size();i++)
 {
        if(pi[i]==a.size())
        {
                f=1;
               // cout<<i<<" ";
                int pos=i-a.size()-1;
                cout<<(pos-a.size()+1)<<endl;
        }
        //cout<<s[i]<<" "<<pi[i]<<endl;
 }
 if(!f)
        cout<<endl;
}

}
