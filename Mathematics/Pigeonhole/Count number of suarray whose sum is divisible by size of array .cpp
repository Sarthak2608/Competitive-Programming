#include<iostream>
#include<map>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		long n,x,ans=0,sum=0;
		cin>>n;
		map<int,int> m;
		m[0]++;
		for(int i=1;i<=n;i++)
		{
			cin>>x;
			sum+=x;
			m[sum%n]++;
		}
		for(auto i:m)
		{
			ans+=(i.second)*(i.second-1)/2;
		}
		cout<<ans<<endl;
	}
	return 0;
}
