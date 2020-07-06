/*
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3330/
*/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n=A.size(),ans=-1e8;
        for(int i=0;i<n;i++)
            A.push_back(A[i]);
        multiset<int> s;
        s.insert(0);
        
        int x=0;
        int pref[2*n];
        deque<int> q;
        q.push_back(0);
        for(int i=0;i<2*n;i++)
        {
            x+=A[i];
            q.push_back(x);
            if(i>=n)
            {
                s.erase(s.find(q.front()));
                q.pop_front();
            }
            ans=max(ans,x-(*s.begin()));
            s.insert(x);
        }
        
        return ans;
    }
};
