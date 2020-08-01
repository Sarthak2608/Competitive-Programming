/*
https://leetcode.com/problems/candy/
*/
class Solution {
public:
    int candy(vector<int>& r) {
        int n=r.size();
        vector<int> v[n+1],indeg(n+1);
        for(int i=0;i<n;i++)
        {
            if(i+1<n&&r[i]<r[i+1])
            {
                v[i].push_back(i+1);
                indeg[i+1]++;
            }
            if(i+1<n&&r[i]>r[i+1])
            {
                v[i+1].push_back(i);
                indeg[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0)
                q.push(i);
        }
        int ans[n+1];
        for(int i=0;i<n;i++)
            ans[i]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            //cout<<node<<" "<<ans[node]<<endl;
            for(auto i:v[node])
            {
                indeg[i]--;
                ans[i]=max(ans[node]+1,ans[i]);
                if(indeg[i]==0)
                    q.push(i);
            }
        }
        int tot=0;
        for(int i=0;i<n;i++)
        {
            tot+=ans[i];
        }
        return tot;
    }
};
