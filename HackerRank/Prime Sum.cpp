#include <bits/stdc++.h>

using namespace std;
vector<int> prime;
long Mul(long a, long b, long p)
        {
            a%=p;
            b%=p;
            long long ans = 0;
            while (b != 0)
            {
                if (b % 2 == 1) ans = (ans + a) % p;
                a = a * 2 % p;
                b /= 2;
            }
            return ans;
        }

long long fp(long long a,long long b,long long mod)
{
    if(b==0)
    return 1;
    long long x=fp(a,b/2,mod);
    x=Mul(x,x,mod);
    if(b&1)
    x=Mul(x,a,mod);
    return x;
}
long long myran(long mod){
     long long a=rand()%mod;
     long long b=rand()%mod;
     return (Mul(a,RAND_MAX+1,mod)+b)%mod;
}


bool probablyPrimeFermat(long n, int iter=5) {
    if(n<4)
    {
        if( n==2||n==3)
        return true;
        return false;
    }
     for(auto p:prime)
     {
         if(p*p>n)
         break;

         if(n%p==0)
         return false;
     }
      for (int i = 0; i < iter; i++) {
        long long a = 2 + myran(n - 3) % (n - 3);
        //cout<<a<<endl;
        a%=n;
        if (fp(a, n - 1, n) != 1)
            return false;
    }
    return true;
}


// Complete the solve function below.
string solve(long n, long k) {

long two=n/2,three=0;
if(n&1)
{
    two--;
    three++;
}

long mn=0;
if(two==1)
{
  mn=1;
}
else if(two>1)
{
    mn=2;
}
if(three!=0)
mn++;

if(two+three<k)
return "No";

if(k==2)
{
    if(n%2==0)
    return "Yes";
    n-=2;
    if(n<=1)
    return "No";

    if(probablyPrimeFermat(n))
    return "Yes";
    return "No";

}
if(k>=mn)
return "Yes";

if(k==1){
if(probablyPrimeFermat(n))
    return "Yes";
    return "No";
}


return "No";
}

int main()
{
    const long mxn=100;
    int visit[105]={0};
    for(int i=2;i<=mxn;i++)
    {
        if(visit[i]==0){
            prime.push_back(i);
            for(int j=2;j*i<=mxn;j++)
            {
               visit[i*j]=1;
            }
        }
    }
  //  cout<<prime.size()<<endl;
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        long n,k;
        cin>>n>>k;
        cout<<solve(n,k)<<'\n';
    }
}
