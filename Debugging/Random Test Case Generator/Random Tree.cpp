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

vector<array<int,2>> edge;

void star(int n)
{
	for(int i=2;i<=n;i++)
	{
		edge.push_back({1,i});
	}
}

void linear(int n)
{
	for(int i=1;i<n;i++)
	{
		edge.push_back({i,i+1});
	}
}

void binary(int n)
{
	vector<int> v={1};
	int node=2;
	while(node<=n)
	{
		vector<int> nv;
		for(int j=0;j<v.size()&&node<=n;j++)
		{
			edge.push_back({v[j],node});
			nv.push_back(node);
			node++;
			if(node<=n){
				edge.push_back({v[j],node});
				nv.push_back(node);
				node++;
			}
		}
		v=nv;
	}	
}

void RandomTree(int n)
{
 	 vector<int> v={1};
 	 int sz=1;
 	 for(int i=1;i<n;i++)
 	 {
 	 	int pos=rand()%sz;
 	 	++sz;
 	 	edge.push_back({v[pos],sz});
 	 	v.push_back(sz);
 	 }
}

vector<int> tmp;

void setProbality()
{
	vector<int> p={10,10,10,70};  //set acc to need
	for(int i=0;i<p.size();i++)
		for(int k=1;k<=p[i];k++)
			tmp.push_back(i);
	random_shuffle(tmp.begin(),tmp.end());
}

void generate(int n)
{
	int sz=tmp.size();
	int id=tmp[rand()%sz];
	if(id==0)
	{
		star(n);
	}
	else if(id==1)
	{
		linear(n);
	}
	else if(id==2)
	{
		binary(n);
	}
	else if(id==3)
	{
		RandomTree(n);
	}

}




signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 srand(time(0));
 setProbality();
 int t=1;
 //cout<<t<<endl;
 while(t--)
 {
	int n=rand()%100+1;
	cout<<n<<endl;
	//RandomTree(n);
	generate(n);
	for(auto i:edge)
	cout<<i[0]<<" "<<i[1]<<endl; 
 }


}
