
#include<bits/stdc++.h>
using namespace std;
#define int long long int
int bits=30,s=0;
int basis[30];
void insert(int x)
{
    for(int i=bits-1;i>=0;i--)
    {
        if(x&(1ll<<i))
        {
            if(!basis[i])
            {
                s++;
                basis[i]=x;
                return ;
            }
            x=x^basis[i];
        }
    }
}

signed main(){
    
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        insert(x);
    }
    cout<<(1ll<<(n-s))-1;
    return 0;
}
