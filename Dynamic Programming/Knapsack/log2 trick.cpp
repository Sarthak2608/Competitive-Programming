/*
https://www.youtube.com/watch?v=wy4e_mXWxQ8
https://codeforces.com/blog/entry/84925
https://szkopul.edu.pl/problemset/problem/klvaggzD-q4Acz_WLtkn0JXJ/site/?key=statement

*/

#include <bits/stdc++.h>                                                        
using namespace std;                                                            
#define endl "\n"                                                               
//#define int long long                                                         
#define ar array<int,2>                                                         
#define inf 1000000000000000000                                                 
#define deb(x) cerr << "\n" << (#x) << " is " << (x) << endl                    
int mod=1e9+7;                                                                  
int min(int a,int b){return (a<b)?a:b;}                                         
int max(int a,int b){return (a>b)?a:b;}                                         
int fp(int a,int b){if(b==0) return 1;int x=fp(a,b/2);x=(x*x)%mod;if(b&1) x=(x*a
)%mod;return x;}                                                                
auto random_add = [] { char *p = new char; delete p; return uint64_t(p); };     
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (
random_add() | 1);                                                              
mt19937_64 rng(SEED);                                                           
                                                                                
                                                                                
const int N=2e5+5,K=20006;                                                      
short dp[1002][K+1];                                                            
//dp[i] represent if we can pay i rupees                                        
short id[N];                                                                    
short v[N];                                                                     
signed main() {                                                                 
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);                 
                                                                                
 int n;                                                                         
 cin>>n;                                                                        
                                                                                
 int b[n+1];                                                                    
 int c[n+1];                                                                    
                                                                                
 for(int i=1;i<=n;i++){                                                         
  cin>>b[i];                                                                    
 }                                                                              
 for(int i=1;i<=n;i++){                                                         
  cin>>c[i];                                                                    
 }                                                                              
 int k;                                                                         
 cin>>k;                                                                        
 int idx=0;                                                                     
                                                                                
 for(int i=1;i<=n;i++)                                                          
 {                                                                              
   int x=1;                                                                     
   while(c[i]>0)                                                                
   {                                                                            
    int y;                                                                      
    if(x<=c[i])                                                                 
    {                                                                           
      y=x;                                                                      
    }                                                                           
    else                                                                        
      y=c[i];                                                                   
                                                                                
    ++idx;                                                                      
    v[idx]=y;                                                                   
    c[i]-=y;                                                                    
    id[idx]=i;                                                                  
    x*=2;                                                                       
   }                                                                            
 }                                                                              
                                                                                
                                                                                
 memset(dp,-1,sizeof(dp));                                                      
 dp[0][0]=0;                                                                    
 for(int i=1;i<=idx;i++)                                                        
 {                                                                              
 // cout<<v[i]<<" ";                                                            
  int w=b[id[i]];                                                               
  dp[i][0]=0;                                                                   
  for(int j=1;j<=k;j++)                                                         
  {                                                                             
    dp[i][j]=dp[i-1][j];                                                        
    if(j-v[i]*w>=0&&dp[i-1][j-v[i]*w]!=-1){                                     
      if(dp[i][j]==-1)                                                          
        dp[i][j]=dp[i-1][j-v[i]*w]+v[i];                                        
      else                                                                      
        dp[i][j]=min(dp[i][j],v[i]+dp[i-1][j-v[i]*w]);                          
    }                                                                           
  }                                                                             
 }                                                                              
                                                                                
 cout<<dp[idx][k]<<endl;                                                        
                                                                                

 int ans[n+1]={0};                                                              
// cout<<k<<":\n";                                                              
 int cur=k;                                                                     
 for(int i=idx;i>=1;i--)                                                        
 {                                                                              
//  cout<<cur<<endl;                                                            
  if(dp[i][cur]==dp[i-1][cur])                                                  
    continue;                                                                   
  cur-=v[i]*b[id[i]];                                                           
  ans[id[i]]+=v[i];                                                             
 }                                                                              
                                                                                
 for(int i=1;i<=n;i++)                                                          
  cout<<ans[i]<<" ";                                                            
cout<<endl;                                                                     
                                                                                
                                                                                
}               
