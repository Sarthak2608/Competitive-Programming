/*
http://acm.hdu.edu.cn/showproblem.php?pid=5306
https://github.com/Bassel-Bakr/ONLINE_JUDGE/blob/master/HDU/gorgeous_sequence.cpp#L90
https://codeforces.com/blog/entry/57319
*/
#include <iostream>
#include<vector>
#include<array>
using namespace std;
#define endl "\n"
#define int long long
#define INT_MIN -1e9
int mod=1e9+7;
int min(int a,int b){
	return (a<b)?a:b;
}
int max(int a,int b){
	return (a>b)?a:b;
}
vector<int> a(1000005);


class SegmentTreeBeats
{
public:
	const int N=1ll<<21;
	vector<int> bit,sum;
	vector<array<int,2>> mx1,mx2;
	int n;
	SegmentTreeBeats()
	{
		bit=vector<int>(N);
		sum=vector<int>(N);
		mx1=vector<array<int,2>>(N);
		mx2=vector<array<int,2>>(N);
	}
	void init(int N1)
	{
		n=N1;
	}
	void merge(int id)
	{
		int lf=2*id;
		int rf=2*id+1;
		mx1[id]=mx1[lf];
		mx2[id]=mx2[lf];

		if(mx1[lf][0]==mx1[rf][0])
		{
			mx1[id][1]+=mx1[rf][1];
			if(mx2[lf][0]==mx2[rf][0])
			{
				mx2[id][1]+=mx2[rf][1];
			}
			else
			{
				mx2[id]=max(mx2[lf],mx2[rf]);
			}
		}
		else if(mx1[lf][0]>mx1[rf][0])
		{
			mx1[id]=mx1[lf];
			mx2[id]=max(mx2[lf],mx1[rf]);
		}
		else
		{
			mx1[id]=mx1[rf];
			mx2[id]=max(mx1[lf],mx2[rf]);
		}
		sum[id]=sum[lf]+sum[rf];
	}
	void build(int id,int l,int r)
	{
		if(l==r)
		{
			sum[id]=a[l];
			bit[id]=a[l];
			mx1[id][0]=a[l];
			mx1[id][1]=1;
			mx2[id][0]=INT_MIN;
			mx2[id][1]=0;
			return;
		}
		int mid=(l+r)/2;
		build(2*id,l,mid);
		build(2*id+1,mid+1,r);
		merge(id);
	}
	void propagate(int id)
	{
		 if(mx1[id][0]<mx1[2*id][0])
		 sum[2*id]=sum[2*id]-mx1[2*id][0]*mx1[2*id][1]+mx1[id][0]*mx1[2*id][1];
		
		 if(mx1[id][0]<mx1[2*id+1][0])
		 sum[2*id+1]=sum[2*id+1]-mx1[2*id+1][0]*mx1[2*id+1][1]+mx1[id][0]*mx1[2*id+1][1];


		mx1[2*id][0]=min(mx1[2*id][0],mx1[id][0]);
		mx1[2*id+1][0]=min(mx1[2*id+1][0],mx1[id][0]);
	}
	void update(int id,int l,int r,int &L,int &R,int &v)
	{
		 if(l>R||r<L||mx1[id][0]<=v)
		 	return;
		 
		 if(L<=l&&r<=R)
		 {
		 	if(mx2[id][0]<=v&&v<mx1[id][0])
		 	{
		 		//do something
		 		sum[id]=sum[id]-mx1[id][0]*mx1[id][1]+v*mx1[id][1];
		 		mx1[id][0]=v;
		 		return;
		 	}
		 }
		 int mid=(l+r)/2;
		 propagate(id);
		 update(2*id,l,mid,L,R,v);
		 update(2*id+1,mid+1,r,L,R,v);
		 merge(id);
		 //cout<<l<<":"<<r<<" {"<<mx1[id][0]<<" "<<mx1[id][1]<<"} {"<<mx2[id][0]<<" "<<mx2[id][1]<<"} sum="<<sum[id]<<"\n";

	}
	int getsum(int id,int l,int r,int &L,int &R)
	{
		 if(l>R||r<L)
		 	return 0;
		 
		 if(L<=l&&r<=R)
		 {
		 	return sum[id];
		 }
		 int mid=(l+r)/2;
		 propagate(id);
		 int y=getsum(2*id,l,mid,L,R)+getsum(2*id+1,mid+1,r,L,R);
		 merge(id);
		 return y;
		
	}
	int getmax(int id,int l,int r,int &L,int &R)
	{
		 if(l>R||r<L)
		 	return 0;
		 
		 if(L<=l&&r<=R)
		 {
		 	return mx1[id][0];
		 }
		 int mid=(l+r)/2;
		 propagate(id);
		 int y=max(getmax(2*id,l,mid,L,R),getmax(2*id+1,mid+1,r,L,R));
		 merge(id);
		 return y;
	}

};

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int t,typ,n,q,x,y,v;

 cin>>t;
 SegmentTreeBeats s;
 while(t--)
 {
 	cin>>n>>q;
 	for(int i=1;i<=n;i++)
 	{
 		cin>>a[i];
 	}
 	s.init(n);
 	s.build(1,1,n);
 	//cout<<endl;
 	while(q--)
    {
    	cin>>typ>>x>>y;
    	if(typ==0)
    	{
    		cin>>v;
    		s.update(1,1,n,x,y,v);
    	}
    	else if(typ==1)
    	{
    		cout<<s.getmax(1,1,n,x,y)<<endl;
    	}
    	else
    	{
    		cout<<s.getsum(1,1,n,x,y)<<endl;
    	}
    }
 
 } 

cout.flush();
}
/*
1
5 6
2 6 1 8 9
0 1 5 5
1 1 5 
2 1 5
0 3 3 2
1 1 5
2 1 5


*/
