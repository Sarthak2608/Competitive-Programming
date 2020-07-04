/*
https://cses.fi/problemset/task/1111/
https://www.youtube.com/watch?v=0CKUjDcUYYA
first find longest palindrome of even length then odd length
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
const int N=1e6+6;
int hshf[N],hshr[N],pw[N],ipw[N],prime=17,n;
string s;
int pos=1,bestLen=1;

bool chk(int i,int l)
{
	int x=hshf[i+l-1]-hshf[i-1];
	if(x<0)
		x+=mod;
	x=(x*ipw[i])%mod;

	int y=hshr[i]-hshr[i+l];
	if(y<0)
		y+=mod;
	y=(y*ipw[n-i-l+2])%mod;
	return (x==y);
}

bool isPalindromeOflenMid(int l)
{
	for(int i=1;i<=n-l+1;i++)
	{
		if(chk(i,l))
		{
			if(bestLen<l)
			{
				bestLen=l;
				pos=i;
			}
			return true;
		}
	}
	return false;
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 pw[0]=1;
 ipw[0]=1;
 int ip=fp(prime,mod-2);
 for(int i=1;i<N;i++)
 {
 	pw[i]=prime*pw[i-1];
 	if(pw[i]>=mod)
 		pw[i]%=mod;
 	ipw[i]=(ip*ipw[i-1]);
 	if(ipw[i]>=mod)
 		ipw[i]%=mod;
 }

 cin>>s;
 n=s.size();
 s="#"+s;
 hshf[0]=0;
 hshr[n+1]=0;
 for(int i=1;i<=n;i++)
 {
 	hshf[i]=(pw[i]*s[i])+hshf[i-1];
 	if(hshf[i]>=mod)
 		hshf[i]%=mod;
 }

 for(int i=n;i>=1;i--)
 {
 	hshr[i]=pw[n-i+1]*s[i]+hshr[i+1];
 	if(hshr[i]>=mod)
 		hshr[i]%=mod;
 }


 for(int parity:{0,1})
 {
 	int l=1;
 	int h=n;
 	if(l%2!=parity)
 		l++;
 	if(h%2!=parity)
 		h--;
 	while(l<=h)
 	{
 		int mid=(l+h)/2;
 		if(mid%2!=parity)
 			mid++;
 		if(isPalindromeOflenMid(mid))
 		{
 			l=mid+2;
 		}
 		else
 		{
 			h=mid-2;
 		}
 	}
 }

 cout<<s.substr(pos,bestLen);



}
