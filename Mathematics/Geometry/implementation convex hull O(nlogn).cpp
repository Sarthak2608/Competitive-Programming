/*
https://leetcode.com/problems/erect-the-fence/
https://cp-algorithms.com/geometry/grahams-scan-convex-hull.html
https://cp-algorithms.com/geometry/oriented-triangle-area.html
https://www.youtube.com/watch?v=gfZUkFf3kVA&list=PLubYOWSl9mIuVdf6VnLIrtF9Y0Sa4Dvoq&index=4
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int mod=1e9+7;
int min(int a,int b){
  return (a<b)?a:b;
}
int max(int a,int b){
  return (a>b)?a:b;
}
 //p1->p2->p3
bool clockwise(vector<int> p1,vector<int> p2,vector<int> p3)
{
  //  |p2[0]-p1[0]  p3[0]-p2[0]|  determinant
  //  |p2[1]-p1[1]  p3[1]-p2[1]|
  int x=(p2[0]-p1[0])*(p3[1]-p2[1])-(p3[0]-p2[0])*(p2[1]-p1[1]);
  return (x<0);
}

bool anticlockwise(vector<int> p1,vector<int> p2,vector<int> p3)
{
  int x=(p2[0]-p1[0])*(p3[1]-p2[1])-(p3[0]-p2[0])*(p2[1]-p1[1]);
  return (x>0);
}
bool collinear(vector<int> p1,vector<int> p2,vector<int> p3)
{
  int x=(p2[0]-p1[0])*(p3[1]-p2[1])-(p3[0]-p2[0])*(p2[1]-p1[1]);
  return (x==0);
}

vector<vector<int>> convexHull(vector<vector<int>>& points) {
    vector<vector<int>> ans; 
    if(points.size()==1)
    {
      ans.push_back(points.back());
      return ans;
    }
    sort(points.begin(),points.end(),[&](vector<int> p,vector<int> q){
      if(p[0]==q[0])
        return p[1]<q[1];
      return p[0]<q[0];
    });
    auto a=points.front();  //leftmost points
    auto b=points.back();   //rightmost point
    
    vector<vector<int>> up,down;
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
      if(i==points.size()-1||clockwise(a,b,points[i]))
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
    return up;


}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 int n,x,y;
 cin>>n;
 vector<vector<int>> points;
 for(int i=1;i<=n;i++)
 {
  cin>>x>>y;
  points.push_back({x,y});
 }
 auto ans=convexHull(points);
 for(auto i:ans)
  cout<<i[0]<<" "<<i[1]<<endl;
}

/*

6
1 1
2 2 
2 0
2 4
3 3
4 2


3
1 1
2 2
4 2

*/
