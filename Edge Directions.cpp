/*
https://cses.fi/problemset/task/1756/

https://codeforces.com/contest/1385/submission/87178622

Proof is simple,we can go from x to y if and only if x<y then we cannot go from y to x
*/

void solve()
{
  int n,m,x,y;
  cin>>n>>m;

  for(int i=1;i<=m;i++)
  {
    cin>>x>>y;
    if(x>y)
      swap(x,y);
    cout<<x<<" "<<y<<endl;
  }

}
