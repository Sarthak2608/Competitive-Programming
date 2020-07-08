/*
https://codeforces.com/edu/course/2/lesson/2/4/practice/contest/269119/problem/A

lcp:

s[p[i]]  = X+Y  (let X has k character)
s[p[i+1]]= X+Z

Y<Z

s[p[i+1]+1]<s[p[i]] and it will have at least k-1 common character


p[q]= s[p[i]]

p[j-1]=......     //lcp(p[j],p[j-1]) will also at least k character
p[j]= s[p[i+1]+1]

note: if we want to find lcp(s[i..],s[j...])
then it will be the min(lcp[p[c[i]] to lcp[p[c[j]]])

c[i] store the position of suffix start at ith pos in suffix array p 

*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int min(int a,int b)
{
	if(a<b)
		return a;
	return b;
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

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 string s;
 cin>>s;
 s+='$';  
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
 while((1<<k)<n)
 {
 	vector<array<int,2>> a(n);

 	for(int i=0;i<n;i++)
 	{
 		int idx=(p[i]-(1<<k)+n)%n;
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

 		array<int,2> p1={c[p[i-1]],c[(p[i-1]+(1<<k))%n]};
		array<int,2> p2={c[p[i]],c[(p[i]+(1<<k))%n]};

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
 
//suffix array
for(int i=0;i<n;i++)
	cout<<p[i]<<" ";
cout<<endl;

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
for(int i=1;i<n;i++)
{
	cout<<lcp[i]<<" ";
}

 

}


