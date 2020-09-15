/*
  https://www.youtube.com/watch?v=xq3ABa-px_g
  Time Complexity: E log(N) 
  
  idea: insert the source node in set then pick the node which has lower cost incommimg edge, then pop that node(x)
  After this relax all unvisited node which are connected with x then repeat the process.
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

struct edge
{
    int x,y,w;
};



const int N=2e5+5;


class MST
{
public:
    int n,m,i1;
    vector<vector<array<int,3>>> v;
    vector<int> vis,incommingEdgeId,cost;
    vector<edge> ed;
    MST(int N):v(N),vis(N),incommingEdgeId(N),cost(N),ed(N){

    }

    void init(int _n,int _m)
    {
        i1=0;
        n=_n;
         for(int i=1;i<=n;i++)
         {
            v[i].clear();
            cost[i]=inf;
            vis[i]=0;
            incommingEdgeId[i]=-1;
         }
    }

    void add_edge(int x,int y,int w)
    {
         ++i1;
         ed[i1].x=x;
         ed[i1].y=y;
         ed[i1].w=w;
         v[x].push_back({y,w,i1});
         v[y].push_back({x,w,i1});     
    }

    int get_cost()
    {
         set<array<int,2>> s;
         int src=1;
         cost[src]=0;
         s.insert({0,src});
         int ans=0;
         while(!s.empty())
         {
            int node=(*s.begin())[1];
            s.erase(s.begin());
            vis[node]=1;
            ans+=cost[node];
            for(auto i:v[node])
            {
                if(!vis[i[0]]&&i[1]<cost[i[0]])
                {
                    auto it=s.find({cost[i[0]],i[0]});
                    if(it!=s.end())
                    s.erase({cost[i[0]],i[0]});
                    cost[i[0]]=i[1];
                    s.insert({cost[i[0]],i[0]});
                    incommingEdgeId[i[0]]=i[2];
                }
            }
         }
         return ans;
    }

    void print_mst()
    {
         for(int i=1;i<=n;i++)
         {
            if(incommingEdgeId[i]!=-1)
            {
                int id=incommingEdgeId[i];
                cout<<ed[id].x<<" "<<ed[id].y<<" "<<ed[id].w<<endl;
            }
         }
    }

};



signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 

 int n,m,x,y,w;
 cin>>n>>m;
 MST obj(N);
 obj.init(n,m);

 for(int i=1;i<=m;i++)
 {
    cin>>x>>y>>w;
    obj.add_edge(x,y,w);
 }

 
 cout<<obj.get_cost()<<endl;
 //obj.print_mst();
}

/*
4 5
1 2 10
2 3 15
1 3 5
4 2 2
4 3 40
*/
