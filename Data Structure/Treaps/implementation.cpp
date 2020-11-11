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



class Treap
{
public:
    int n;
    struct node
    {
        int x;
        node *child[2];

        int subtreeSize,priority;

        node(int x,int priority):x(x),priority(priority){
            subtreeSize=1;
            child[0]=NULL;
            child[1]=NULL;
        }
    }*root;


    int sz(node *head)
    {
        return (head==NULL)?0:head->subtreeSize;
    }


    node* build(int l,int r,vector<int> &a,vector<int> &priority)
    {
        if(l>r)
            return NULL;
        int x=l;
        for(int i=l;i<=r;i++)
        {
            if(priority[i]>priority[x])
                x=i;
        }
        node *nd=new node(a[x],priority[x]);
        nd->child[0]=build(l,x-1,a,priority);
        nd->child[1]=build(x+1,r,a,priority);
        recal(nd);
        return nd;
    }

    void dfs(node *head,int level=0)
    {
        if(head==NULL)
            return;

        dfs(head->child[0],level+1);
        cout<<(head->x)<<" ";
        dfs(head->child[1],level+1);
    }

    void prop(node *head)
    {
        if(head==NULL)
            return;
    }

    void recal(node *head)
    {
        if(head==NULL)
            return;
        head->subtreeSize=1;
        if(head->child[0]!=NULL){
            head->subtreeSize+=head->child[0]->subtreeSize;
        }
        if(head->child[1]!=NULL){
            head->subtreeSize+=head->child[1]->subtreeSize;
        }
    }

    array<node*,2> split(node *head,int prefix) //return {x,y} and sz(x)=prefix
    {
        if(head==NULL)
            return {NULL,NULL};

        prop(head);

        if(sz(head->child[0])>=prefix)
        {
            auto r=split(head->child[0],prefix);
            head->child[0]=r[1];
            recal(head);
            return {r[0],head};
        }
        else
        {
            auto r=split(head->child[1],prefix-sz(head->child[0])-1);
            head->child[1]=r[0];
            recal(head);
            return {head,r[1]};
        }
        return {NULL,NULL};
    }


    node *merge(node *head1,node* head2)
    {
        if(head1==NULL)
            return head2;
        if(head2==NULL)
            return head1;
        if(head1->priority>head2->priority)
        {
            prop(head1);
            head1->child[1]=merge(head1->child[1],head2);
            recal(head1);
            return head1;
        }
        else
        {
            prop(head2);
            head2->child[0]=merge(head1,head2->child[0]);
            recal(head2);
            return head2;
        }
        return NULL;
    }

    void init(vector<int> &a)
    {
        int n=a.size();
        this->n=n;
        vector<int> p(n);
        for(int i=0;i<n;i++)
        {
            p[i]=i;
        }
        for(int i=0;i<n;i++)
        {
            int x=rng()%(n-i);
            swap(p[x],p[n-i-1]);
        }
        root=build(0,n-1,a,p);
    }




    void solve()
    {
       //code here
    }

};


signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 Treap obj;
 
 int n;
 cin>>n;
 vector<int> a(n);
 for(int i=0;i<n;i++)
    cin>>a[i];
 obj.init(a);


}
