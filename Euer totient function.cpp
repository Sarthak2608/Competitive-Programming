#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n=1e6+1;
	vector<int> v(n+1);
	v[1]=1;
	for(int i=2;i<=n;i++)
	{
	    if(v[i]==0)
	    {
	        v[i]=i-1;
	        for(int j=2;j*i<=n;j++)
	        {
	            if(v[j*i]==0)
	            {
	                v[j*i]=j*i;
	            }
	            v[j*i]-=v[j*i]/i;
	        }
	    }
	}
	
	int t;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    cout<<v[n]<<endl;
	}
	return 0;
}
