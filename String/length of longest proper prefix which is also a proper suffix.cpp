/*

Watch geeksforgeeks video or abdul bari kmp video

*/


#include <iostream>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    
	    int n=s.size();
	    int lps[n+1];
	    lps[0]=0;
	   // cout<<s<<endl;
	    int len=0,ans=0;
	    for(int i=1;i<n;i++)
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
	                continue;
	            }
	            else
	            {
	               len=lps[len-1];
	               i--;
	            }
	        }
	       
	    }
	    cout<<lps[n-1]<<endl;
	}
	
	return 0;
}
