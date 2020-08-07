/*
https://cses.fi/problemset/task/1146/
*/
void solve()
{
       int n,ans=0,prev=-1,x=2;
       cin>>n;
       n++;
       while(prev!=ans)
       {
          int cycle=n/x;
          int y=x/2;
          prev=ans;
          ans+=y*cycle;  //we are adding the contribution of log2(x)-1 bit of no from 1 to n 
          ans+=max(0,n%x-y);
          x*=2;
       }
       
       cout<<ans<<endl;
}
