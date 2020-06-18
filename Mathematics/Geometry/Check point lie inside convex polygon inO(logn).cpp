/*
https://www.youtube.com/watch?v=8nNg2KlwyRY
https://cp-algorithms.com/geometry/point-in-convex-polygon.html
https://www.codechef.com/viewsolution/34511916
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int mod=1e9+7;
#define int long long 
int min(int a,int b){
  return (a<b)?a:b;
}
int max(int a,int b){
  return (a>b)?a:b;
}

#define ar array<int,2>

class convexPolygon
{
public:
    vector<ar> vertices;
 //p1->p2->p3
bool clockwise(ar p1,ar p2,ar p3)
{
  //  |p2[0]-p1[0]  p3[0]-p2[0]|  determinant
  //  |p2[1]-p1[1]  p3[1]-p2[1]|
  int x=(p2[0]-p1[0])*(p3[1]-p2[1])-(p3[0]-p2[0])*(p2[1]-p1[1]);
  return (x<0);
}

bool anticlockwise(ar p1,ar p2,ar p3)
{
  int x=(p2[0]-p1[0])*(p3[1]-p2[1])-(p3[0]-p2[0])*(p2[1]-p1[1]);
  return (x>0);
}
bool collinear(ar p1,ar p2,ar p3)
{
  int x=(p2[0]-p1[0])*(p3[1]-p2[1])-(p3[0]-p2[0])*(p2[1]-p1[1]);
  return (x==0);
}

vector<ar> convexHull(vector<ar>& points) {
    vector<ar> ans; 
    if(points.size()==1)
    {
      ans.push_back(points.back());
      return ans;
    }
    sort(points.begin(),points.end(),[&](ar p,ar q){
      if(p[0]==q[0])
        return p[1]<q[1];
      return p[0]<q[0];
    });
    auto a=points.front();  //leftmost points
    auto b=points.back();   //rightmost point
    
    vector<ar> up,down;
    up.push_back(points[0]);
    down.push_back(points[0]);
    for(int i=1;i<points.size();i++)
    {
      if(collinear(a,b,points[i])||anticlockwise(a,b,points[i]))
      {
        while(up.size()>1&&clockwise(up[up.size()-2],points[i],up.back()))
        {
          up.pop_back();
        }
        up.push_back(points[i]);   
      }
      if(collinear(a,b,points[i])||clockwise(a,b,points[i]))
      {
        while(down.size()>1&&anticlockwise(down[down.size()-2],points[i],down.back()))
        {
          down.pop_back();
        }
        down.push_back(points[i]);
      }
    }
 
        
  
    down.pop_back();
    reverse(down.begin(),down.end());
    down.pop_back();
    for(auto i:down){
        up.push_back(i);
    }
    vertices=up;

    return up;
}


bool equal(ar a,ar b)
{
  if(a[0]==b[0]&&a[1]==b[1])
    return 1;
  return 0;
}
void print(ar a)
{
  cout<<a[0]<<" "<<a[1]<<endl;
}

bool insideTriangle(ar a,ar b,ar c,ar p)
{
  // print(a);
  // print(b);
  // print(c);
  // print(p);
  // cout<<endl;
     if(!clockwise(b,c,p)||collinear(a,b,c)||equal(a,p))
    return 0;
    if(!collinear(a,vertices[1],p)&&collinear(a,b,p)&&a[0]<=p[0]&&p[0]<=b[0])
      return 1;
    if(!collinear(a,vertices[vertices.size()-1],p)&&collinear(a,c,p)&&a[0]<=p[0]&&p[0]<=c[0])
      return 1;
    if(clockwise(a,b,p)&&clockwise(c,a,p))
      return 1;
    return 0;
}

bool insideConvexHull(ar p)
{
        int lw=1,hg=vertices.size()-1;
      
        while(hg-lw>1)
        {
          int mid=(lw+hg)/2;
          if(clockwise(vertices[0],vertices[mid],{p[0],p[1]}))
          {
            lw=mid;
          }
          else
          {
            hg=mid;
          }
        }

        if(insideTriangle(vertices[0],vertices[lw],vertices[hg],p))
        {
          return 1;
        }
        return 0;

}


};

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n,q,x,y;
  convexPolygon obj;
  cin>>n>>q;
  vector<array<int,2>> points;
  for(int i=1;i<=n;i++)
  {
   cin>>x>>y;
   points.push_back({x,y});
  }
  auto hull=obj.convexHull(points);
  for(auto i:hull)
    cout<<i[0]<<" "<<i[1]<<endl;
  cout<<endl;
  while(q--)
  {
    cin>>x>>y;
    cout<<obj.insideConvexHull({x,y})<<endl;
  }




 }



/*

4 4
1 1
5 1
5 5
1 5
2 2
0 0
5 5
4 3



*/
