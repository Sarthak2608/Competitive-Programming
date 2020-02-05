/*
  Solving recurrence relation using matrix method
  By Sarthak Jain
  
  f(n) = n*(36^n) + 36 + f(n-1)*36
  
  |f(n)           |  =   |36   1  0  1 |  |f(n-1)   |
  |n+1)*(36^(n+1) |  =   | 0  36 36  0 |  |n*(36^n) |
  |36^(n+1)       |  =   | 0   0 36  0 |  |36^n     |
  |36             |  =   | 0   0  0  1 |  |36       |
  
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
int mod=1e9+7;
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
        vector<vector<int>> adj(5,vector<int>(5)),A0(5,vector<int>(2));
        adj[1][1]=36;
        adj[1][2]=1;
        adj[1][4]=1;
        adj[2][2]=36;
        adj[2][3]=36;
        adj[3][3]=36;
        adj[4][4]=1;
        
        A0[1][1]=1;
        A0[2][1]=36;
        A0[3][1]=36;
        A0[4][1]=36;
        int n;
        cin>>n;
        if(n==0)
        {
            cout<<1<<endl;
            continue;
        }
        
        adj=fp(adj,n);
        adj=mul(adj,A0);
        cout<<adj[1][1]<<endl;
        
        
    }   
	return 0;
}
