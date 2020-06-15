/*
https://cses.fi/problemset/task/1076/
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int mod=1e9+7;
int min(int a,int b){
    return (a<b)?a:b;
}
int max(int a,int b){
    return (a>b)?a:b;
}

const int N=2e5+5;
int a[N];
int n,k;
multiset<int> s1,s2;
int p,q;
void balance()
{
    while(s1.size()>p)
    {
        s2.insert((*s1.rbegin()));
        s1.erase(s1.find(*s1.rbegin()));
    }
    while(s2.size()>q)
    {
        s1.insert((*s2.begin()));
        s2.erase(s2.find(*s2.begin()));
    }
}
 
void insert(int x)
{
    if(s1.size()==0&&s2.size()==0)
    {
        s1.insert(x);
        return;
    }
    else if(s1.size()==0)
    {
        s2.insert(x);
    }
    else if(x>=(*s1.rbegin()))
    {
        s2.insert(x);
    }
    else
    {
        s1.insert(x);
    }
    if(s1.size()+s2.size()<k)
        return;
 
    balance();
 
}
 
void remove(int x)
{
    auto it=s1.find(x);
    if(it!=s1.end())
    {
        s1.erase(it);
    }
    else if(s2.find(x)!=s2.end())
    {
        s2.erase(s2.find(x));
    }
    balance();
}
signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 
 
cin>>n>>k;
p=k/2;
q=k/2;
if(k&1)
p++;
for(int i=1;i<=n;i++)
{
    cin>>a[i];
    insert(a[i]);
    if(i>=k)
    {
        cout<<(*s1.rbegin())<<" ";
        remove(a[i-k+1]);
    }
}
 
}
