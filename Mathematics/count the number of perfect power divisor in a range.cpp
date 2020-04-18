/*
 https://codeforces.com/problemset/problem/955/C

*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int mxn=1e6;
vector<int> temp;
void pre()
{
	int mxn2=1e18;
	for(int i=2;i<=mxn;i++)
	{
		for(int j=i;j<=mxn2;)
		{
			 if((mxn2/j)<i)
			 	break;
			j*=i;

			if((mxn2/j)<i)
				break;
			j*=i;
		      if(j<=0)
		      break;
			int sq=sqrtl(j);
			if(sq*sq==j)
				continue;
			temp.push_back(j);
			
		}
	}
	//cout<<temp.size()<<endl;
	sort(temp.begin(),temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end()); 
  
}

int solve(int n)
{
	int ans=sqrtl(n);
	ans+=upper_bound(temp.begin(),temp.end(),n)-temp.begin();
    return ans;
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 pre();
 int t;
 cin>>t;
 while(t--)
 {
   int a,b;
   cin>>a>>b;
   cout<<solve(b)-solve(a-1)<<endl;
 }

}
