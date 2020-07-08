#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long


//this function sort the a by first value
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
 s+='$';  //'$' is lexico smaller than 'a'
 int n=s.size();
 
 //p[i] stores the starting pos of ith suffix sorted order of suffix upto 2^k character in each suffix
 //c[i] store the class of each suffix start at ith pos
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
 	/*
 	now we want to sort the string(2^k+2^k) (left+right) character
	we will use the order of p to sort the right part  
 	*/
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


 for(int i=0;i<n;i++)
 {
 	cout<<p[i]<<" ";
 }


}
