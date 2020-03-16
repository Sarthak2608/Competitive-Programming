/*
Time Complexity:O(nlogn+qlogn)
You are given an array of length n and q query, For each query count the number of element from index l to index r which are less than or equal to y
*/

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
// __gnu_pbds::gp_hash_table<int,int> mp;
using namespace std;
using namespace __gnu_pbds;
const int mxn=2e5+10;
int n,q,x1,x2,y,x;
vector<int> bit(mxn);

void update(int node,int val)
{
    for(;node<=mxn;node+=node&(-node))
    bit[node]+=val;
}
int get(int node)
{
    int x=0;
    for(;node>0;node-=node&(-node))
    {
        x+=bit[node];
    }
    return x;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,q;
    cin>>n>>q;
    vector<int> process[n+1];  
    vector<int> vv;
    map<int,int> mp;
    vector<int> ar(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>ar[i];
        mp[ar[i]];
    }
    
    vector<array<int,3>> query(q+1);
    vector<int> ans(q+1);
    //Offline Queries
    for(int i=1;i<=q;i++)
    {
        /*
            The answer of each query from l to r is count(r)-count(l-1)
            Where count(i) function represents the number of elements less than y upto index i;
        */
        cin>>query[i][0]>>query[i][1]>>query[i][2];
        mp[query[i][2]];
        
        //It will calculate the value of count(r)
        process[query[i][1]].push_back(i); 
       
        //It will calculate the value of count(l-1)
        process[query[i][0]-1].push_back(-i); 
      
    }
    
    
    //Coordinate Compression
    int c=1;
    for(auto &i:mp)
    i.second=c++;
    
    //Updating New Coordinate
    for(int i=1;i<=n;i++)
    ar[i]=mp[ar[i]];
    for(int i=1;i<query.size();i++){
    query[i][2]=mp[query[i][2]];
    }
    for(int i=1;i<=n;i++)
    {
        update(ar[i],1);
        for(auto j:process[i])
        {
            int query_id=max(j,-j);
            int x=get(query[query_id][2]);
            if(j>0)
            ans[query_id]+=x;
            else
            ans[query_id]-=x;
        }
    }
    for(int i=1;i<=q;i++)
    cout<<ans[i]<<endl;
	return 0;
}
