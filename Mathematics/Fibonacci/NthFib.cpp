#include <bits/stdc++.h>
#include <vector>

using namespace std;
#define int long long int
int mod=1e9+7;
vector<vector<int>> Mul(vector<vector<int>> A,vector<vector<int>> B)
{
    vector<vector<int>> C(A.size(),vector<int>(B[0].size()));
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<B[0].size();j++)
        {
            int c=0;
            for(int k=0;k<A[0].size();k++)
            {
                c=( c + (A[i][k]*B[k][j])%mod )%mod;
            }
            C[i][j]=c;
        }
    }
    return C;
}
vector<vector<int>> fp(vector<vector<int>> a,int b)
{
    if(b==0)
    {
        vector<vector<int>> res(a.size(),vector<int>(a[0].size()));
        for(int i=0;i<a.size();i++)
        {
            res[i][i]=1;
        }
        return res;
    }
    vector<vector<int>> res=fp(a,b/2);
    vector<vector<int>> x=Mul(res,res);
    if(b&1)
    x=Mul(x,a);

    return x;

}
signed main(){
    int t,a,b,n;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>n;
        if(n==0)
        {
            cout<<a<<endl;
            continue;
        }
        else if(n==1)
        {
            cout<<b<<endl;
            continue;
        }
        vector<vector<int>> v(2,vector<int>(2));
        v[0][1]=1;
        v[1][1]=1;
        v[1][0]=1;
        vector<vector<int>> res=fp(v,n-1);
        cout<<( (res[0][1]*a)%mod+(res[1][1]*b)%mod ) %mod<<endl;    
        

    }
}
