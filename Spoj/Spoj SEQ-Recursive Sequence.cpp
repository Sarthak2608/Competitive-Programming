//Solving recurrence relation using matrix method
//By Sarthak Jain
#include<bits/stdc++.h>
using namespace std;
#define int long long int
int mod=1e9;
vector<int> c,b;
int k;
vector<vector<int>> mul(vector<vector<int>> &v1,vector<vector<int>> &v2)
{
    int r=v1.size()-1;
    int c=v2[0].size()-1;
    
    vector<vector<int>> res(r+1,vector<int>(c+1));
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            
            for(int k=1;k<v2.size();k++)
            {
                res[i][j]=(res[i][j]+(v1[i][k]*v2[k][j])%mod)%mod;
            }
            
        }
    }
    
    return res;
}

vector<vector<int>> fp(vector<vector<int>> &A,int n)
{
    int r=A.size()-1;
    int c=A[0].size()-1;
    vector<vector<int>> res(r+1,vector<int>(c+1));
    if(n==0)
    {
        for(int i=1;i<=min(r,c);i++)
        res[i][i]=1;
        
        return res;
    }
    
    res=fp(A,n/2);
    
    res=mul(res,res);
    
    if(n&1)
    {
        res=mul(res,A);
    }
    
    return res;
}

signed main() {
    int t;
    cin>>t;
    while(t--)
    {

        cin>>k;
        c=vector<int>(k+1);
        b=vector<int>(k+1);
        vector<vector<int>> adj(k+1,vector<int>(k+1));
         vector<vector<int>> A0(k+1,vector<int>(2)); 
        for(int i=1;i<=k;i++)
        {
            cin>>b[i];
            if(b[i]>=mod)
            b[i]-=mod;
            A0[i][1]=b[i];
        }
        for(int i=1;i<=k;i++)
        {
            cin>>c[i];
            if(c[i]>=mod)
            c[i]-=mod;
            adj[k][k-i+1]=c[i];
        }
        
        for(int i=1;i<k;i++)
        adj[i][i+1]=1;
        
        int n;
        cin>>n;
        adj=fp(adj,n-1);
        adj=mul(adj,A0);
        cout<<adj[1][1]<<endl;
        
        
    }   
	return 0;
}
