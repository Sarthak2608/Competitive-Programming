/*

Time complx: O( (R-L)*LogR )
Space complx: O(sqrt(R))

Idea:first find all possible prime divisor of all numbers in the range
then for sqrt(N) block run the seive

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define ar array<int,2>
#define inf 1000000000000000000 
#define deb(x) cerr << "\n" << (#x) << " is " << (x) << endl
int mod=1e9+7;
int min(int a,int b){return (a<b)?a:b;}
int max(int a,int b){return (a>b)?a:b;}
int fp(int a,int b){if(b==0) return 1;int x=fp(a,b/2);x=(x*x)%mod;if(b&1) x=(x*a)%mod;return x;}
auto random_add = [] { char *p = new char; delete p; return uint64_t(p); };
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_add() | 1);
mt19937_64 rng(SEED);


class SegementSeive
{
    public:
    
    vector<int> SimpleSeive(int N)
    {
        vector<int> prime;
        int mark[N+1]={0};
        for(int i=2;i<=N;i++)
        {
            if(mark[i]==0)
            {
                prime.push_back(i);
                for(int j=2;j*i<=N;j++)
                mark[j*i]=1;
            }
        }
        return prime;
    }
    
    
    vector<int> getPrimeLtoR(int l,int r)
    {
        if(l==1)
        l++;
        int sz=sqrtl(r);
        auto prime=SimpleSeive(sz);
        
        int lw=l;
        int hg=lw+sz;
        
        vector<int> ans;
        while(lw<=r)
        {
            hg=min(hg,r);
            int mark[sz+2]={0};
            for(int i=0;i<prime.size();i++)
            {
                int start=((lw+prime[i]-1)/prime[i])*prime[i];
                for(int j=start;j<=hg;j+=prime[i])
                {
                    if(prime[i]!=j)
                    mark[j-lw]=1;
                }
            }
            for(int i=lw;i<=hg;i++)
            if(mark[i-lw]==0)
            ans.push_back(i);
            lw=hg+1;
            hg=lw+sz;
        }
        return ans;
    }
};




signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 int L=20,R=30;
 SegementSeive obj;
 auto prime=obj.getPrimeLtoR(L,R);
 for(auto i:prime){
  cout<<i<<" ";
  }


}
