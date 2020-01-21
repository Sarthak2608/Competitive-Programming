#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n,sum=0,ans=0;
		cin>>n;
		int v[n+1];
		unordered_map<int,int> m; 
		for(int i=1;i<=n;i++)
		{
			cin>>v[i];
			v[i]%=n;
			v[i]=(v[i]+n)%n;
			sum+=v[i];
			sum%=n;
			m[sum]++;
		}
        sum=0;
		for(int i=1;i<=n;i++)
		{
			ans+=m[sum];
			sum=(sum+v[i])%n;
			m[sum]--;

		}
        cout<<ans<<endl;
	}
	return 0;
}
