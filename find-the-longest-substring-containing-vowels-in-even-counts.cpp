class Solution {
public:
    int findTheLongestSubstring(string s) {
       
        int mask=0,ans=0;
        map<char,int> mp,mp2;
        mp['a']=0;
        mp['e']=1;
        mp['i']=2;
        mp['o']=3;
        mp['u']=4;
        mp2[0]=-1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            {
                mask=mask^(1ll<<mp[s[i]]);    
            }
            if(mp2.find(mask)==mp2.end())
            {
                mp2[mask]=i;
            }
            else
            {
                ans=max(ans,i-mp2[mask]);
            }
            
        }
        return ans;
    }
};
