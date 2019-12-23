#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double

void dft(vector<complex<double>> &a,int n,int invert)
{   
    if(n==1)
    return ;
    
    vector<complex<double>> a0(n/2),a1(n/2);
    for(int i=0;i<n/2;i++)
    {
        a0[i]=a[2*i];
        a1[i]=a[2*i+1];
    }
    dft(a0,n/2,invert);
    dft(a1,n/2,invert);
    
    double ang=(2*M_PI/n);
    if(invert)
    ang*=-1;
    complex<double> w(cos(ang),sin(ang)),start(1);
    
    
    for(int i=0;i<n/2;i++)
    {
        a[i]=a0[i]+start*a1[i];
        a[i+n/2]=a0[i]-start*a1[i];
        if(invert)
        {
            a[i]/=2;
            a[i+n/2]/=2;
        }
        start*=w;
    }
}

void multiply(vector<int> a,vector<int> b)
{
  int n=1; 
  while(n<a.size()+b.size())
  n<<=1;

  vector<complex<double>> a1(a.begin(),a.end()),b1(b.begin(),b.end());
  a1.resize(n);
  b1.resize(n);
  
  dft(a1,n,0);
  dft(b1,n,0);

  vector<complex<double>> res(n);
  for(int i=0;i<n;i++)
  res[i]=a1[i]* b1[i];
//   for(int i=0;i<n;i++)
//   cout<<res[i]<<" ";
//   cout<<endl;
  
  dft(res,n,1);
  
  int n1=a.size()+b.size()-1;
  for(int i=0;i<n1;i++)
  cout<<unsigned(res[i].real()+0.5)<<" ";
  cout<<endl;
}


signed main() {
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       n++;
       vector<int> a(n),b(n);
       for(int i=0;i<n;i++)
       {
           cin>>a[i];
       }
       for(int i=0;i<n;i++)
       {
           cin>>b[i];
       }
       multiply(a,b);
   }
    
	return 0;
}
