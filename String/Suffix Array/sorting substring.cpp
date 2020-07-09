/*
https://codeforces.com/edu/course/2/lesson/2/5/practice/contest/269656/problem/C

first create lcp and suffix array
simply sort the substring using comparator function
In comparator function calcualate the lcp of the two string in O(1) using sparse table
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int min(int a,int b){
	return (a<b)?a:b;
}
int max(int a,int b){
	return (a>b)?a:b;
}
void count_sort(vector<array<int,2>> &a)
{
	int n=a.size();
	vector<int> freq(n),pos(n);
	for(auto i:a)
		freq[i[0]]++;
	for(int i=1;i<n;i++)
	{
		pos[i]=pos[i-1]+freq[i-1];
	}
	vector<array<int,2>> a_new(n);
	
	for(auto i:a)
	{
		a_new[pos[i[0]]]=i;
		pos[i[0]]++;
	}
	a=a_new;
}

class sparse
{
	const int N=1e6+5;
	vector<vector<int>> bit;
	vector<int> a;
	int n;
public:
	void init(vector<int> A)
	{
		a=A;
		n=a.size();
		int j=log2(n);
		bit=vector<vector<int>>(n,vector<int>(j+1));
		process();
	}

	void process()
	{
		for(int i=0;i<n;i++)
		{
			bit[i][0]=a[i];
		}
		for(int k=1;(1ll<<k)<n;k++)
		{
			for(int i=0;i+(1ll<<k)-1<n;i++)
			{

				bit[i][k]=min(bit[i][k-1],bit[i+(1ll<<(k-1))][k-1]);
			}
		}
	}
	int rmq(int i,int j)
	{
		if(i>j)
			swap(i,j);
		i++;
		int l=j-i+1;
		int jump=log2(l);
		return min(bit[i][jump],bit[i+l-(1ll<<jump)][jump]);
	}
};

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 string s;
 cin>>s;
 char ch=31;
 s+=ch;
 int n=s.size();
 
 vector<int> p(n),c(n);
 
 {
 	vector<array<int,2>> a(n);
 	for(int i=0;i<n;i++)
 	{
 		a[i]={s[i],i};
 	}
 	sort(a.begin(),a.end());
 	

 	p[0]=a[0][1];
 	c[p[0]]=0;
 	for(int i=1;i<n;i++)
 	{
 		p[i]=a[i][1];
 		if(a[i][0]==a[i-1][0])
 		{
 			c[p[i]]=c[p[i-1]];
 		}
 		else
 		{
 			c[p[i]]=c[p[i-1]]+1;
 		}
 	}

 }


 int k=0;
 while((1ll<<k)<n)
 {
 	vector<array<int,2>> a(n);

 	for(int i=0;i<n;i++)
 	{
 		int idx=(p[i]-(1ll<<k)+n)%n;
 		a[i][0]=c[idx];
 		a[i][1]=idx;
 	}
 	
 	count_sort(a);
 	vector<int> c_new(n);
 	p[0]=a[0][1];
 	c_new[p[0]]=0;
 	for(int i=1;i<n;i++)
 	{
 		p[i]=a[i][1];

 		array<int,2> p1={c[p[i-1]],c[(p[i-1]+(1ll<<k))%n]};
		array<int,2> p2={c[p[i]],c[(p[i]+(1ll<<k))%n]};

		if(p1==p2)
		{
			c_new[p[i]]=c_new[p[i-1]];
		}
		else
		{
			c_new[p[i]]=c_new[p[i-1]]+1;
		}
 	}
 	c=c_new;
 	k++;
 }


//lcps
vector<int> lcp(n);
k=0;
for(int i=0;i<n-1;i++)
{
	int pi=c[i];

	int j=p[c[i]-1];
	while(s[i+k]==s[j+k])
	{
		k++;
	}
	lcp[pi]=k;
	k=max(k-1,0);
}

// for(int i=0;i<n;i++)
// {
// 	cout<<p[i]<<" ";
// }
// cout<<endl<<endl;


// for(int i=0;i<n;i++)
// {
// 	cout<<lcp[i]<<" ";
// }
// cout<<endl;


sparse obj;
obj.init(lcp);


int q;
cin>>q;
int l,r;
vector<array<int,2>> qr(q);
for(int i=0;i<q;i++)
{
	cin>>qr[i][0]>>qr[i][1];
	qr[i][0]--;
	qr[i][1]--;
}

sort(qr.begin(),qr.end(),[&](array<int,2> x,array<int,2> y){
	int l1=x[1]-x[0]+1;
	int l2=y[1]-y[0]+1;
	int m;
	if(x[0]!=y[0])
		m=obj.rmq(c[x[0]],c[y[0]]);  //lcp(s[x[0]...n],s[y[0]....n]) in O(1)
	else
		m=n-x[0];	//if both substring starts at same pos
	int mn=min({l1,l2,m});
	if(mn==l1&&mn==l2)	//both are equal
	{
		if(x[0]!=y[0])
			return x[0]<y[0];
		return x[1]<y[1];
	}
	if(mn==l1)
		return true;
	if(mn==l2)
		return false;

	return s[x[0]+mn]<s[y[0]+mn];
});



for(auto i:qr)
{
	cout<<i[0]+1<<" "<<i[1]+1<<endl;
}




}

