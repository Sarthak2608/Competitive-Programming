#include <iostream>
#include <vector>
#include<array>

using namespace std;
#define int long long int

int mod=1e9+7;
const int N=51;

array<array<int,N>,N> C;
array<array<int,N>,N> Mul(array<array<int,N>,N> &A,array<array<int,N>,N> &B)
{
    int c,d;
    for(int i=0;i<N;i++)
    C[i].fill(0);

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            c=0;
            for(int k=0;k<N;k++)
            {
                c+=(A[i][k]*B[k][j]);
                if(c>=mod)
                    c%=mod;
            }
            C[i][j]=c;
        }
    }
    // for(int i=0;i<N;i++)
    //     for(int j=0;j<N;j++)
    //         if(C[i][j]>=mod)
    //             C[i][j]%=mod;
    return C;
}
array<array<int,N>,N> fp(array<array<int,N>,N> &a,int b)
{
        array<array<int,N>,N> res;
        for(int i=0;i<N;i++)
        {
            res[i].fill(0);
            res[i][i]=1;
        }

        while(b>0)
        {
            if(b&1)
            {
                res=Mul(res,a);
            }
            a=Mul(a,a);
            b>>=1;
        }
       return res;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n,k;
cin>>n>>k;

array<array<int,N>,N> v;
for(int i=0;i<N;i++)
v[i].fill(0);

for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
        cin>>v[i][j];
}

auto r=fp(v,k);

int ans=0;
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        cout<<r[i][j]<<" ";
    }
    cout<<endl;
}


  return 0;
}
