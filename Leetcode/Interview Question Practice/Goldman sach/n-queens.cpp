/*
https://leetcode.com/problems/n-queens/
*/
class Solution {
public:
    vector<string> mat;
    int n;
    vector<vector<string>> ans;
    void solve(int r,int c,int k,int m1)
    {
        if(k==0)
        {
            ans.push_back(mat);
            return;
        }
        
        if(r==n)
            return;
        int f=1;
        if((m1>>c)&1)
        {
            f=0;
        }
        if(f)
        for(int i=0;i<r;i++)
            for(int j=0;j<n;j++)
                if(abs(i-r)==abs(j-c)&&mat[i][j]=='Q'&&!(i==r&&i==c))
                {
                        f=0;
                        i=9;
                        break;
                }
    
        if(c<n-1)
        solve(r,c+1,k,m1);
        if(f){
            mat[r][c]='Q';
            solve(r+1,0,k-1,m1|(1ll<<c));
            mat[r][c]='.';
        }
        
    }
    vector<vector<string>> solveNQueens(int n1) {
        n=n1;
        ans.clear();
        vector<string> t;
        mat.clear();
        for(int i=0;i<n;i++)
        {
            string s(n,'.');
            mat.push_back(s);
        }
        
        solve(0,0,n,0);
        
        return ans;
    }
};
