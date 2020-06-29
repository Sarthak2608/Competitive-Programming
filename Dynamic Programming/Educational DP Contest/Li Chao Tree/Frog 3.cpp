/*
https://www.youtube.com/watch?v=DknbfinVLLk
https://atcoder.jp/contests/dp/tasks/dp_z
https://www.desmos.com/calculator  (for visualize graph)
https://codeforces.com/blog/entry/63823

https://robert1003.github.io/2020/02/06/li-chao-segment-tree.html
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

const int N=1e6+5;
int dp[N];
int inf=1e17;

struct line
{
	int m,c;
	line()
	{
		m=0;
		c=inf;
	}
	int getY(int x){
		return m*x+c;
	}
};

vector<line> bit(4*N);

void insert(int id,int l,int r,line nline)
{
	if(l==r)
	{
		if(bit[id].getY(l)>=nline.getY(l))
			bit[id]=nline;
		return;
	}
	int mid=(l+r)/2;
	if(nline.getY(l)<=bit[id].getY(l)&&nline.getY(mid)<=bit[id].getY(mid))  //intersection point lie in [mid+1,r]
	{
		swap(bit[id],nline);
		insert(2*id+1,mid+1,r,nline);
	}
	else if(nline.getY(l)>=bit[id].getY(l)&&nline.getY(mid)>=bit[id].getY(mid))
	{
		insert(2*id+1,mid+1,r,nline);
	}
	else if(nline.getY(r)<=bit[id].getY(r)&&nline.getY(mid+1)<=bit[id].getY(mid+1))  //intersection point lie in [l,mid]
	{
		swap(bit[id],nline);
		insert(2*id,l,mid,nline);
	}
	else if(nline.getY(r)>=bit[id].getY(r)&&nline.getY(mid+1)>=bit[id].getY(mid+1))
	{
		insert(2*id,l,mid,nline);
	}
	else
	{
		return;
	}
}


int get(int id,int l,int r,int x)
{
	int y=bit[id].getY(x);
	if(l==r)
	{
		return y;
	}
	int mid=(l+r)/2;
	if(x<=mid)
		return min(y,get(2*id,l,mid,x));
	else
		return min(y,get(2*id+1,mid+1,r,x));
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

 int n,c;
 cin>>n>>c;
 int h[n+1];
 for(int i=1;i<=n;i++)
 {
 	cin>>h[i];
 }
 
 for(int i=1;i<=n;i++)
 {
 	if(i==1)
 		dp[i]=0;
 	else
 		dp[i]=c+h[i]*h[i]+get(1,1,1e6,h[i]);
 	line nline;
 	nline.m=-2*h[i];
 	nline.c=h[i]*h[i]+dp[i];
 	insert(1,1,1e6,nline);
}
 cout<<dp[n];



}

/*
*/
