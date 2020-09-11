/*


Explanation :


N is the total number of shares which will generated 
K is the number of share required to reconstruct the secret key

for each charater of secret key we will use Shamir Secret Sharing Algorithm 
now let the ASCII value of first character be s
then for generation of N share ,we will use following equation
(By K share we can recover the character s)



we can generate N share(from i=1 to i=N)
for Ith share we will generate pair(xi,y(x1)) which satisfy the equation   

y(x)=a1*(x^(k-1))+a2*(x^(k-2))+.....+ s*(x^0) 

Note : if for y(0), we can recover the ASCII value



Lagrange’s Interpolation
we can recovery of the value of s using K pair of (xj,y(xj)) where j>=1&&j<=k
we can do the following



X=0
y(X) =summation for each i(  y(xi)*(X-xj)/(xi-xj)  )
      
      i>=1 and i<=K
      j!=i and j>=1 and j<=K



*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;


class SSS
{
  int GF=256;
private:
  string secret_key;
  int N,K; 

public:
  SSS(string s,int n,int k):secret_key(s),N(n),K(k){

  };

vector<vector<array<int,2>>> getNshare()
{
      vector<vector<array<int,2>>> keys(N,vector<array<int,2>>(secret_key.size()));
      for(int i=0;i<secret_key.size();i++)
      {
        int a=rand()%GF;
        for(int x=1;x<=N;x++){
          int x1=x;
          int y1=a*x+secret_key[i];
          keys[x-1][i]={x1,y1};
        }
      }
    return keys;
}


  
string getSecretKey(vector<vector<array<int,2>>> keys)
{
  if(keys.size()<K)
    return "";
  string ans;
  //Langrange Interpolation

  for(int i=0;i<secret_key.size();i++)
  {
      int X=0;
      int Y=0;
      for(int ax=1;ax<=K;ax++)
      {
          int ax_th_Term=keys[ax-1][i][1];
          for(int bx=1;bx<=K;bx++)
          {
            if(ax==bx)
              continue;
          
            ax_th_Term=ax_th_Term*(X-keys[bx-1][i][0])/(keys[ax-1][i][0]-keys[bx-1][i][0]);
          }
          Y+=ax_th_Term;
      }
    
      ans.push_back(char(Y));

  }

  return ans;
}



};


signed main() {
 srand(time(0));

 SSS obj("Hello",4,2);
 auto keys=obj.getNshare();

 cout<<"N Shares:\n";
 for(auto i:keys)
 {
  for(auto j:i)
    cout<<"{"<<j[0]<<","<<j[1]<<"} ";
  cout<<endl;
 }


 vector<vector<array<int,2>>> tmp;
 tmp.push_back(keys[0]);
 tmp.push_back(keys[2]);

 string ans=obj.getSecretKey(tmp);
 cout<<"Secret Key : "<<ans<<endl;

}
