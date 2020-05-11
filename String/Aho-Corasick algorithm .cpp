/*
https://www.youtube.com/watch?v=O7_w001f58c  //pictorial representation
https://www.youtube.com/watch?v=ePafMI_rSJg  //nice tutorial
https://www.youtube.com/watch?v=NWFBNJP1j4A  //implementation 
https://github.com/johlits/ahocorasick

1. at each node  suffix link stores the link of longest suffix of current string which is the prefix 
2. end stores the id of word which are ending at respective node
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long


int K=52;
struct node
{
  int k;
  int suflink;
  vector<int> next;
  vector<int> end;
  node()
  {
    k=K;
    suflink=0;
    next=vector<int>(k);
  }
  void init()
  {
    suflink=0;
    for(int i=0;i<K;i++)
      next[i]=0;
    end.clear();
  }
};


class ahocorasick
{
    public:
    const int N=1e6+5,K=52;
    int ct=0;
    vector<node> bit;
    ahocorasick()
    {
        bit=vector<node>(N);
    }
    void init()
    {
       for(int i=0;i<=ct;i++)
       {
          bit[i].init();
       }
       ct=0;
    }
    void insert(string s,int id)
    {
      //cout<<s<<endl;
      int node=0;
      for(auto i:s)
      {
        if('a'<=i&&i<='z')
        i=i-'a';
        else
        i=i-'A'+26;
        if(!bit[node].next[i])
        {
          bit[node].next[i]=++ct;  //creating new node
        }
        node=bit[node].next[i];
        //cout<<char(i+'a')<<node<<endl;
      }

      bit[node].end.push_back(id);
    }

    void create_go(vector<string> &patt)
    {
          for(int i=0;i<patt.size();i++)
          {
            insert(patt[i],i);
          }
          create_failure();   //using bfs store the failure link
    }

    void create_failure()
    {
          queue<int> q;
          for(auto i:bit[0].next)
          {
            if(i)
            {
              q.push(i);
            }
          }
          
          while(!q.empty())
          {
             int node=q.front();
             //cout<<node<<":"<<bit[node].suflink<<endl;
             q.pop();
             for(int j=0;j<K;j++)
             {
                  if(bit[node].next[j])                        
                  {
                    int link=bit[node].suflink;

                    while(link>0&&!bit[link].next[j])
                    {
                      link=bit[link].suflink;
                    }
                    if(bit[link].next[j])
                    {
                      link=bit[link].next[j];
                    }
                    bit[bit[node].next[j]].suflink=link;
                    for(auto e:bit[link].end)
                    {
                       bit[bit[node].next[j]].end.push_back(e);
                    }
                    q.push(bit[node].next[j]);
                  }
             }
          }
    }
    vector<array<int,2>> patternSearch(string s)
    {
      vector<array<int,2>> ans;
      int node=0;
      int pos=-1;
      for(auto i:s)
      {
          if('a'<=i&&i<='z')
          i=i-'a';
          else
          i=i-'A'+26;
          
          ++pos;
          if(bit[node].next[i])
          {            
            node=bit[node].next[i];
            for(auto j:bit[node].end)
              ans.push_back({j,pos});
          }     
          else
          {
              while(node>0&&!bit[node].next[i])
              node=bit[node].suflink;
              if(bit[node].next[i])
              {
                node=bit[node].next[i];
                for(auto j:bit[node].end)
                {
                  ans.push_back({j,pos});
                }
              }
          }
      }
    //  for(auto i:ans)
    //    cout<<"string id ="<<i[0]<<"  - found at position="<<i[1]<<endl;
      return ans;
    }
};

signed main() {
  ahocorasick obj;
  vector<string> pat;
  int t;
  cin>>t;
  while(t--)
  {
    string a,b;
    cin>>a>>b;
    obj.init();
    pat.push_back(b);
    obj.create_go(pat);
    auto v=obj.patternSearch(a);
    pat.clear();
    if(v.size()>0)
    {
      cout<<"Yes\n";
    }
    else
    {
      cout<<"No\n";
    }


  }

}
/*
3
abc
b
abs
ab
abscd
scf

*/
