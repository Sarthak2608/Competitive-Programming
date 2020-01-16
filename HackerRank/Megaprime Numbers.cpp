#include <bits/stdc++.h>

using namespace std;
#define int long long int
vector<int> prime;
int mod=1e9+7;

int idx(char ch)
{
    if(ch=='2')
    return 0;
    else if(ch=='3')
    return 1;
    else if(ch=='5')
    return 2;
    return 3;
}

char charat(int i)
{
    if(i==0)
    return '2';
    else if(i==1)
    return '3';
    else if(i==2)
    return '5';
    return '7';
}
string toString(int n)
{
    string s="";
    while(n>0)
    {
       s=char(n%10+'0')+s;
       n/=10;
    }
    return s;
}
int StoNum(string s)
{
    int num=0;
    for(int i=0;i<s.size();i++)
    {
       num*=10;
       num+=(s[i]-'0');
    }
    return num;
}
int add(int n)
{
    int x=0,c=1,c1;
    string s=toString(n);
    for(int i=s.size();i>=1;i--)
    {
        c1=(idx(s[i-1])+c)/4;
        s[i-1]=charat((idx(s[i-1])+c)%4);
        c=c1;
    }
    if(c!=0)
    {
        c-=1;
        s=charat(c)+s;
    }
    return StoNum(s);
}

int mul(int a,int b,int mod)
{
    int ans=0;
    while(b>0)
    {
        if(b&1)
        {
            ans=(ans+a)%mod;
        }
        a=(a*2)%mod;
        b/=2;
    }
    return ans;
}
int fp(int a,int b,int mod)
{
    if(b==0)
    return 1;
    int x=fp(a,b/2,mod);
    x=mul(x,x,mod);
    if(b&1)
    x=mul(x,a,mod);
    return x;
}
int test(int a,int s,int d,int n)
{
    int b=fp(a,d,n);
    if(b==1||b==n-1)
    {
        return 1;
    }
  
    for(int i=1;i<s;i++)
    {
        b=mul(b,b,n);
        if(b==n-1)
        return 1;
    }
    return 0;
    
}
int myran(int mod){
     int a=rand()%mod;
     int b=rand()%mod;
     return (mul(a,(RAND_MAX+1),mod)+b)%mod;
}
int MillerRabin(int n)
{
    if(n==1)
    return 0;
    for(auto p:prime)
    {
        if(p*p>n)
        {
            return 1;
        }
        if(n%p==0)
        return 0;
    }
    
    int s=0;
    int d=n-1;
    while(d%2==0)
    {
        d/=2;
        s++;
    }
   
    
    for(int i=1;i<=1;i++)
    {
         int a=2+myran(n-3)%(n-3);
        if(test(a,s,d,n)==0)
        return 0;
    }
    return 1;
}


signed main(){
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int mxn=5000,visit[5005]={0};
for(int i=2;i<=mxn;i++)
{
    if(visit[i]==0)
    {
        prime.push_back(i);
        for(int j=2;j*i<=mxn;j++)
        visit[j*i]=1;
    }
}

int l,r;
cin>>l>>r;
char ch;
string s=toString(l);
string s2=s;
int f=0;
for(int i=0;i<s.size();i++)
{
    if(f)
    {
        s2[i]='2';
        continue;
    }
  if('7'<=s[i])
  {
      s2[i]='7';
  }
  else if ('5'<=s[i]) {
      s2[i]='5';
  }
  else if ('3'<=s[i]) {
      s2[i]='3';
  }
  else {
      s2[i]='2';
  }
  if(s2[i]!=s[i])
  {
      f=1;
  }
}
int n=StoNum(s2);
//cout<<r-n<<endl;
//cout<<n<<endl;
//return 0;
int count=0;
for(;n<=r;)
{
    if(n>=l)
    {
         if(MillerRabin(n)){
        // //cout<<"prime ";
         count++;
          }
        //cout<<n<<endl;
    }
    n=add(n);
}
cout<<count;

}
