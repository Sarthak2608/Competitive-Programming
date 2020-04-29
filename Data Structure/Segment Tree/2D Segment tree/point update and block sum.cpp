/*
https://www.codechef.com/viewsolution/32424020
https://www.youtube.com/watch?v=kKlZ9B3cS14
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int a[1005][1005];
class segmentTree2d
{
public:
   int n,m;
   vector<vector<array<int,2>>> bit;
   vector<vector<int>> grid;
   segmentTree2d(int N,int M)
   {
      n=N;
      m=M;
      grid=vector<vector<int>>(n+1,vector<int>(m+1));
      bit=vector<vector<array<int,2>>>(4*n+5,vector<array<int,2>>(4*m+5));
   }
   void input()
   {
        //vector<vector<int>> &Grid
        for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                        grid[i][j]=a[i][j]; //=Grid[i][j];
   }
   void init(int N,int M)
   {
     n=N;
     m=M;
     for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
          grid[i][j]=0;
     for(int i=1;i<=4*n;i++)
      for(int j=1;j<=4*m;j++)
        bit[i][j][0]=0;
   }
   int set(int r,int c,int val)
   {
     int x=-grid[r][c]+val;
     grid[r][c]=val;
     return x;
   }
   void print()
   {
         for(int i=1;i<=n;i++,cout<<endl)
                for(int j=1;j<=m;j++)
                        cout<<grid[i][j]<<" ";
   }
   void generate()
   {
        //generate segment tree from r1 to rn
        genSeg_r1_rn(1,1,n);
   }
   void propagate(int T,int id)
   {
        bit[T][2*id][1]+=bit[T][id][1];
        bit[T][2*id+1][1]+=bit[T][2*id+1][1];
        bit[T][id][1]=0;
   }
   void merge(int id1,int id2,int id3,int id,int l,int r)
   {
      bit[id1][id][0]=bit[id2][id][0]+bit[id3][id][0];
      //cout<<id<<" "<<l<<" "<<r<<" "<<bit[id1][id]<<endl;
      if(l==r)
      {
        return;
      }
      int mid=(l+r)/2;
      merge(id1,id2,id3,2*id,l,mid);
      merge(id1,id2,id3,2*id+1,mid+1,r);
   }
   void genSeg_r1_rn(int id,int l,int r)
   {
        if(l==r)
        {
       //         cout<<" "<<id<<" "<<r<<":\n";
                genSeg_c1_cm(1,1,m,id,l);
                return;
        }
        int mid=(l+r)/2;
        genSeg_r1_rn(2*id,l,mid);
        genSeg_r1_rn(2*id+1,mid+1,r);
     //   cout<<"Merge: "<<l<<" "<<r<<endl;
        merge(id,2*id,2*id+1,1,1,m);
//        bit[++tm]=m
   }
   
   void genSeg_c1_cm(int id,int l,int r,int T,int R)
   {
        
        if(l==r)
        {
            bit[T][id][0]=grid[R][l];
         //    cout<<id<<" "<<l<<" "<<r<<" "<<bit[T][id]<<endl;
            return;
        }
        int  mid=(l+r)/2;
        genSeg_c1_cm(2*id,l,mid,T,R);
        genSeg_c1_cm(2*id+1,mid+1,r,T,R);
        bit[T][id][0]=bit[T][2*id][0]+bit[T][2*id+1][0];
       // cout<<id<<" "<<l<<" "<<r<<" "<<bit[T][id]<<endl;
   }
   int getc(int id,int l,int r,int c1,int c2,int T)
   {
        if(l>c2||r<c1)
                return 0;
        if(c1<=l&&r<=c2)
        {
                return bit[T][id][0]+bit[T][id][1];
        }
        int mid=(l+r)/2;
        //propagate(T,id);
        return getc(2*id,l,mid,c1,c2,T)+getc(2*id+1,mid+1,r,c1,c2,T);
   }
   int getr(int id,int l,int r,int r1,int r2,int c1,int c2)
   {
        if(l>r2||r<r1)
                return 0;
        if(r1<=l&&r<=r2)
        {
                return getc(1,1,m,c1,c2,id);
        }
        int mid=(l+r)/2;
        return getr(2*id,l,mid,r1,r2,c1,c2)+getr(2*id+1,mid+1,r,r1,r2,c1,c2);
   }
   void updatec(int id,int l,int r,int c1,int delta,int T)
   {
        if(c1<l||r<c1)
                return;
        if(l==r&&l==c1)
        {
                bit[T][id][0]+=delta;
                return ;
        }
        int mid=(l+r)/2;
        updatec(2*id,l,mid,c1,delta,T);
        updatec(2*id+1,mid+1,r,c1,delta,T);
        bit[T][id][0]=bit[T][2*id][0]+bit[T][2*id+1][0];
   }
   void mergeUpdater(int id1,int id2,int id3,int id,int l,int r,int c1)
   {
        bit[id1][id][0]=bit[id2][id][0]+bit[id3][id][0];
        if(c1<l||r<c1)
                return;
        if(l==r)
                return;
        int mid=(l+r)/2;
        mergeUpdater(id1,id2,id3,2*id,l,mid,c1);
        mergeUpdater(id1,id2,id3,2*id+1,mid+1,r,c1);

   }
   void updater(int id,int l,int r,int r1,int c1,int delta)
   {
       if(r1<l||r<r1)
        return ;
       if(l==r&&l==r1)
       {
        //cout<<l<<" "<<r<<endl;
           updatec(1,1,m,c1,delta,id);
           if(l==r)
           {
                return;
           }
       }
       int mid=(l+r)/2;
       updater(2*id,l,mid,r1,c1,delta);
       updater(2*id+1,mid+1,r,r1,c1,delta);
       mergeUpdater(id,2*id,2*id+1,1,1,m,c1);
   }
};



signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
    cin>>a[i][j];
 //Update:
segmentTree2d s(n,m);
s.input();
s.print();  //to print 
s.generate();

int q,r1,r2,c1,c2,k;
cin>>q;

r1=1;
c1=1;
k=5;   
s.updater(1,1,n,1,1,s.set(r1,c1,k));  //point update at (r1,c1)->k

while(q--)
{
  cin>>r1>>c1>>r2>>c2;
  int ans=s.getr(1,1,n,r1,r2,c1,c2);
  cout<<ans<<endl;
}

}

/*
3 3
3 4 3
2 2 -1
3 -3 1
3
1 1 2 2
1 1 3 3
2 2 3 3
*/
