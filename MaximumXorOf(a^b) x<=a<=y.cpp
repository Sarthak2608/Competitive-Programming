#include<iostream>
using namespace std;
int main () {
    int a,b;
	cin>>a>>b;
    int f=0,ans=0;
	for(int i=20;i>=0;i--)
	{
           if(f!=2){
			if(f==1)
			{
				if(  (a&(1ll<<i))==0 && (b&(1ll<<i))==0 )
				f=2;
			}

			if( (a&(1ll<<i))!=(b&(1ll<<i)) )
			{
				ans+=(1ll<<i);
				f=1;
			}
		   }
		if(f==2)
		{
            ans+=(1ll<<i);
		}
	}
    cout<<ans;
	return 0;
}
