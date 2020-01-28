#include <bits/stdc++.h>
using namespace std;
int lps[1000008];
int lps1(string &s)
{
     int len=0,n;
     n=s.size();
     
     lps[0]=0;
     for(int i=1;i<s.size();i++)
     {
          if(s[i]==s[len])
          {
               len++;
               lps[i]=len;
          }
          else
          {
               if(len==0)
               {
                    lps[i]=0;
               }
               else
               {
                    len=lps[len-1];
                    i--;
               }
          }
     }
     return lps[n-1];
}

int main(){
     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
     int n,x,y,j;
     cin>>n;
     string s,temp,s2,spref,ssuff;
     cin>>s;
     for(int i=2;i<=n;i++)
     {
          cin>>s2;
          spref="";
          ssuff="";
          x=s.size();
          y=min(s.size(),s2.size());
          temp=s2.substr (0,y)+"#"+s.substr(x-y);
          y=lps1(temp);
          for(int k=y;k<s2.size();k++)
          s.push_back(s2[k]);
     }
     cout<<s<<'\n';
     return 0;
}
