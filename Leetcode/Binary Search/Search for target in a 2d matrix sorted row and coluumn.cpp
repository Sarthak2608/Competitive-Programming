/*
https://leetcode.com/problems/search-a-2d-matrix-ii/

using binary search ,25% area decreasing for finding target
*/
class Solution {
public:
    int n,m;
    bool solve(int r1,int r2,int c1,int c2,vector<vector<int>> &g,int t)
    {
        if(r1>=0&&r2>=0&&r1<n&&r2<n&&c1<m&&c2<m&&r1<=r2&&c1<=c2);
        else return false;
        
        int mr=(r1+r2)/2;
        int mc=(c1+c2)/2;
        if(g[mr][mc]==t)
            return true;
        if(r1==r2&&c1==c2)
            return false;
        
        if(g[mr][mc]<t)
        return solve(r1,r2,mc+1,c2,g,t)|solve(mr+1,r2,c1,mc,g,t);
        else
        return solve(r1,r2,c1,mc-1,g,t)|solve(r1,mr-1,mc,c2,g,t);
    }
    bool searchMatrix(vector<vector<int>>& g, int t) {
        n=g.size();
        if(n==0)
            return false;
        m=g[0].size();
        
        return solve(0,n-1,0,m-1,g,t);
    }
};
