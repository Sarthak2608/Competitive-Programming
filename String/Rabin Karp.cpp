#include <bits/stdc++.h>
using namespace std;
#define int long long int
int mxn=1e6+5,mod=1e9+7,prime=31;
int p[1000005];
int myhash(string s,int l)
{
    int ans=0;
    for(int i=0;i<l;i++)
    {
        ans=( ans+(p[i]*s[i])%mod )%mod;
    }
    return ans;
    
}
signed main() {
    p[0]=1;
    for(int i=1;i<mxn;i++)
    {
        p[i]=(p[i-1]*prime)%mod;
    }
    
	int t;
	cin>>t;
	while(t--)
	{
	    string a,b;
	    cin>>a>>b;
	    if(a.size()<b.size())
	    {
	        cout<<"Not Found\n\n";
	        continue;
	    }
	    vector<int> res;
	    int s=b.size();
	    int pthash=myhash(b,b.size()),e=1;
	    int strhash=myhash(a,b.size());
	    for(int i=0;i<=(a.size()-b.size());i++)
	    {
	        if((pthash*e)%mod==strhash)
	        {
	            res.push_back(i+1);
	        }
	        strhash=(strhash-(a[i]*e)%mod)%mod;
	        strhash=(strhash+mod)%mod;
	        e=(e*prime)%mod;
	        if((i+s)<a.size())
	         strhash=(strhash+(a[i+s]*( (e*p[s-1])%mod) )%mod)%mod;
	    }
	    if(res.size()==0)
	    {
	        cout<<"Not Found\n\n";
	        continue;
	    }
	    else
	    {
	     cout<<res.size()<<endl;
	     for(auto j:res)
	     cout<<j<<" ";
	     cout<<endl;
	    }
	    cout<<endl;
	}
	return 0;
}
