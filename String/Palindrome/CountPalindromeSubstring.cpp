/*
Time Complexity : O(n^2)
Idea:DP
dp[i][j] represents the palindrome string from i to j 
if s[i]==s[j]
   then if dp[i+1][j-1] is palindrome 
        then dp[i][j]= s[i] + dp[i+1][j-1] +s[j]
       otherwise 
       dp[i][j]=""
*/
int countSubstrings(string s) {
         
        s=" "+s;
	    int n=s.size()-1;
	    string dp[n+1][n+1];
	    for(int i=1;i<=n;i++)
	    dp[i][i]=s[i];   
        
        for(int d=2;d<=n;d++)
        {
            for(int i=1;i+d-1<=n;i++)
            {
                if(s[i]==s[i+d-1])
                {
                    if(d==2)
                    {
                        dp[i][i+d-1]=s[i];
                        dp[i][i+d-1]+=s[i+d-1];
                    }
                    else if(dp[i+1][i+d-2].size()!=0)
                    {
                        dp[i][i+d-1]=s[i]+dp[i+1][d-1]+s[i+d-1];
                    }
                    
                }
            }
        }
        int count=0;
         for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++){
                if(dp[i][j].size()!=0)
                    count++;
            cout<<dp[i][j]<<" ";
            cout<<endl;
            }
        }
        return count;
    }
