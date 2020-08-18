#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

class comp
{
    public:
    bool operator ()(pair<string,int> a,pair<string,int> b){
        a.second<b.second;
    }

};

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 srand(time(0));


 multiset<pair<string,int>,comp> m;
 m.insert({"a",5});
 m.insert({"b",1});

 for(auto i:m)
 {
    cout<<i.first<<" "<<i.second<<endl;
 }

}
