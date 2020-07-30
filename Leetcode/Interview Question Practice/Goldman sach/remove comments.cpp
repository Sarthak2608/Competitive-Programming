//https://leetcode.com/problems/remove-comments/
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
            int f=0;
        vector<string> ans;
            string buf;
            for(auto  i:source)
            {
                int j=-1;
                string a;
                while(++j<i.size())
                {
                    
                    if(f==0&&j+1<i.size()&&i[j]=='/'&&i[j+1]=='*')
                    {
                        buf=a;
                        f=1;
                        a.clear();
                        j++;
                        continue;
                    }
                    else if(f&&j+1<i.size()&&i[j]=='*'&&i[j+1]=='/')
                    {
                        f=0;
                        a=buf;
                        buf.clear();
                        j++;
                        continue;
                    }
                    if(f)
                        continue;
                    
                    if(j+1<i.size()&&i[j]==i[j+1]&&i[j]=='/')
                    {
                        break;
                    }
                    a.push_back(i[j]);
                }
                if(a.size()>0)
                    ans.push_back(a);
            }
            if(buf.size()>0)
                ans.push_back(buf);
        return ans;
        
    }
};
