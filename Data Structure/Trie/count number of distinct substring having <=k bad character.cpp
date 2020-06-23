/*
https://codeforces.com/problemset/problem/271/D
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


struct node
{
	int tot;
	int link[26];
	node()
	{
		tot=0;
		memset(link,-1,sizeof(link));
	}
};

const int N=1505*1505;
vector<node> bit(N);
int k,c=1,ans=0;

string s2,s;

void insert(int id,int pos,int n,int b)
{
	if(pos!=n)
	{
		if(b<=k){
			if(bit[id].tot==0){
				ans++;
			}
			bit[id].tot++;
		}
	}

	if(pos==s.size())
		return;

	if(bit[id].link[s[pos]-'a']==-1)
	{
		bit[id].link[s[pos]-'a']=++c;
	}

	if(s2[s[pos]-'a']=='0')
		b++;
	insert(bit[id].link[s[pos]-'a'],pos+1,n,b);
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 

 cin>>s;

 cin>>s2; 

 cin>>k;
 
 for(int i=0;i<s.size();i++)
 {

 	insert(1,i,i,0);

 }

 cout<<ans;
 

}
