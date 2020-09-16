/*

code is copied from
https://github.com/Ashishgup1/Competitive-Coding/blob/master/FFT%20(Iterative).cpp
just for use
http://p.ip.fi/ultI


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





typedef complex<double> base;
 
const double PI = acos(-1.0l);
const int N = 8e5+5;
const int Maxb = 19;
const int Maxp = 450;
const int MOD=1e9+7;
 
vector<int> rev;
vector<base> omega;
 
void calc_rev(int n, int log_n) //Call this before FFT
{
    omega.assign(n, 0);
    rev.assign(n, 0);
    for(int i=0;i<n;i++)
    {
        rev[i]=0;
        for(int j=0;j<log_n;j++)
        {
            if((i>>j)&1)
                rev[i] |= 1<<(log_n-j-1);
        }
    }
}
 
void fft(vector<base> &A, int n, bool invert)
{
    for(int i=0;i<n;i++)
    {
        if(i<rev[i])
            swap(A[i], A[rev[i]]);
    }
    for(int len=2;len<=n;len<<=1)
    {
        double ang=2*PI/len * (invert?-1:+1);
        int half=(len>>1);
 
        base curomega(cos(ang), sin(ang));
        omega[0]=base(1, 0);
 
        for(int i=1;i<half;i++)
            omega[i]=omega[i-1]*curomega;
 
        for(int i=0;i<n;i+=len)
        {
            base t;
            int pu = i,
                pv = i+half,
                pu_end = i+half,
                pw = 0;
            for(; pu!=pu_end; pu++, pv++, pw++)
            {
                t=A[pv] * omega[pw];
                A[pv] = A[pu] - t;
                A[pu] += t;
            }
        }
    }
 
    if(invert)
        for(int i=0;i<n;i++)
            A[i]/=n;
}
 
void multiply(int n, vector<base> &A, vector<base> &B, vector<int> &C)
{
    fft(A, n, false);
    fft(B, n, false);
    for(int i=0;i<n;i++)
        A[i] *= B[i];
    fft(A, n, true);
    for(int i=0;i<n;i++)
    {
        C[i] = (int)(A[i].real() + 0.5);
        C[i] %= MOD;
    }
}
 
void Solve(int n, vector<int> &coeffA, vector<int> &coeffB, vector<int> &result, bool big1, bool big2) //Call 4 times: 00, 01, 10, 11
{
    vector<base> A(n), B(n);
    for(int i=0;i<n;i++)
    {
        A[i]=big1?coeffA[i]/Maxp : coeffA[i]%Maxp;
        B[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        B[i]=big2?coeffB[i]/Maxp : coeffB[i]%Maxp;
    }
    vector<int> C(n);
    multiply(n, A, B, C);
    for(int i=0;i<n;i++)
    {
        int add=C[i];
        if(big1)
            add*=Maxp;
        if(big2)
            add*=Maxp;
        add%=MOD;
        result[i]+=add;
        result[i]%=MOD;
    }
}
 
void do_FFT(vector<int> &A, vector<int> &B, vector<int> &result)
{
    int n=1, bits=0;
    while(n<2*A.size() || n<2*B.size())
        n<<=1, bits++;
    result.assign(n, 0);
    calc_rev(n, bits);
    vector<int> tempA(A.begin(), A.end());
    vector<int> tempB(B.begin(), B.end());
    tempA.resize(n);
    tempB.resize(n);
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            Solve(n, tempA, tempB, result, i, j);
        }
    }
}


signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 

 int n,m;
 cin>>n>>m;
 vector<int> a(n),b(m),c;
 for(int i=0;i<n;i++)
    cin>>a[i];
 for(int i=0;i<m;i++)
    cin>>b[i];
 do_FFT(a,b,c);
 c.resize(a.size()+b.size()-1);
 for(auto i:c)
    cout<<i<<" ";



}

/*

2
2
1 2
3 4

f(x)=1*(x^0) + 2(x^1)
g(x)=3*(x^0) + 4(x^1)

h(x)=f(x)*g(x)
h(x)= 3*(x^0) + 10*(x^1) +8*(x^2) 


*/
