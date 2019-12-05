#include <bits/stdc++.h>
using namespace std;
#define int long long int
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int s1=500009;
    int v[s1]={0};
    std::vector<int> ans(s1,1);
    for(int i=2;i<=s1;i++)
    {
        if(v[i]==0)
        {
            int s=s1/i+5;
            int p[s],h[s];
            p[1]=1;
            h[1]=i;
            for(int j=2;j*i<=s1;j++)
            {
                v[j*i]=1;
                p[j]=1;
                h[j]=i;
                
                if(j%i==0){
                p[j]+=p[j/i];
                h[j]*=h[j/i];
                }
                
                ans[j*i]*=(h[j]*i-1)/(i-1);
            }
            ans[i]+=i;
        }
    }
     
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    cout<<ans[n]-n<<endl;
	}
	return 0;
}
