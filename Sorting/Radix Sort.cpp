/*
https://www.geeksforgeeks.org/radix-sort/
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long


void countsort(vector<int> &v,int exp)
{
   vector<int> nv(v.size());
   int freq[10]={0};
   for(int i=0;i<v.size();i++)
   {
      freq[(v[i]/exp)%10]++;
   }
   for(int i=1;i<10;i++)
    freq[i]+=freq[i-1];
   for(int i=v.size()-1;i>=0;i--)
   {
      freq[(v[i]/exp)%10]--;
      nv[freq[(v[i]/exp)%10]]=v[i];
   }
   v=nv;
}

void radixSort(vector<int> &v)
{
    int mxdigit=17; //maximum number of digit in any number
    int exp=1;
    for(int d=0;d<20;d++)
    {
        countsort(v,exp);  //sorting according to (d+1)th digit from right ,If there is a tie no swaps done
        exp*=10;
    }
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

 int n;
 cin>>n;
 vector<int> v(n);
 for(int i=0;i<n;i++)
 {
    cin>>v[i];
 }
 radixSort(v);
 for(auto &i:v){
  cout<<i<<" ";
 }


  
}

/*
8
170 45 75 90 802 24 2 66
*/
