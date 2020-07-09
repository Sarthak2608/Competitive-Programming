/*
https://codeforces.com/problemset/problem/1093/E
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
int n;
vector<int> bt[N],bit[N];
vector<int> a(N),b(N),pa,pb;
int ia[N],ib[N];


void up(int node,int j)
{
	for(;node<=n;node+=node&-node)
		bt[node].push_back(j);
}


void update(int i,int j,int x)
{
	for(;i<=n;i+=(i&-i))
	{
		for(auto it=lower_bound(bt[i].begin(),bt[i].end(),j)-bt[i].begin()+1;it<bit[i].size();it+=it&-it)
				bit[i][it]+=x;

	}
}



int get(int i,int j)
{
	int x=0;
	for(;i>0;i-=i&-i)
	{
		auto it1=lower_bound(bt[i].begin(),bt[i].end(),j+1);

		if(it1==bt[i].begin())
			continue;
		it1--;
		for(auto it=it1-bt[i].begin()+1;it>0;it-=it&-it)
				x+=bit[i][it];
	}
	return x;
}

int myget(int i,int j1,int j2)
{
	return get(i,j2)-get(i,j1-1);
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int m,x,y;
 cin>>n>>m;

 for(int i=1;i<=n;i++){
 	cin>>a[i];
 	ia[a[i]]=i;
 }
 pa=a;
 for(int i=1;i<=n;i++)
 {
 	cin>>b[i];
 	ib[b[i]]=i;
 }
 pb=b;

 for(int i=1;i<=n;i++)
 {
 	up(ia[i],ib[i]);
 }

 array<int,5> qr[m+1];
 for(int i=1;i<=m;i++)
 {
 	cin>>qr[i][0];
 	if(qr[i][0]==1)
 	{
 		for(int j=1;j<=4;j++)
 		{
 			cin>>qr[i][j];
 		}
 	}
 	else
 	{
 		cin>>x>>y;
 		ib[b[x]]=y;
 		ib[b[y]]=x;
 		swap(b[x],b[y]);
 		up(ia[b[x]],ib[b[x]]);
 		up(ia[b[y]],ib[b[y]]);

 		qr[i][1]=x;
 		qr[i][2]=y;
 	}
 }



for(int i=1;i<=n;i++)
{
	sort(bt[i].begin(),bt[i].end());
	bt[i].resize(distance(bt[i].begin(),unique(bt[i].begin(),bt[i].end())));
	bit[i]=vector<int>(bt[i].size()+2);
}


a=pa;
b=pb;




 for(int i=1;i<=n;i++){
 	ia[a[i]]=i;
 }

 for(int i=1;i<=n;i++)
 {
 	ib[b[i]]=i;
 }

 for(int i=1;i<=n;i++)
 {
 	update(ia[i],ib[i],1);
 }


 for(int i=1;i<=m;i++)
 {
 	if(qr[i][0]==1)
 	{
 		int ans=myget(qr[i][2],qr[i][3],qr[i][4])-myget(qr[i][1]-1,qr[i][3],qr[i][4]);
 		cout<<ans<<endl;
 	}
 	else
 	{
 		x=qr[i][1];
 		y=qr[i][2];
 		
 		update(ia[b[x]],ib[b[x]],-1);
 		update(ia[b[y]],ib[b[y]],-1);

 		ib[b[x]]=y;
 		ib[b[y]]=x;
 		swap(b[x],b[y]);
 		
 		update(ia[b[x]],ib[b[x]],1);
 		update(ia[b[y]],ib[b[y]],1);

 	}
 }


}
