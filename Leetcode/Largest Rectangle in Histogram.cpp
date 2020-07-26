class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
     h.push_back(0);
     stack<array<int,2>> st;
     int ans=0;
     for(int i=0;i<h.size();i++){
         if(st.size()==0)
         {
             st.push({h[i],i});
             continue;
         }
         if(st.size()>0&&st.top()[0]<=h[i])
         {
             st.push({h[i],i});
             continue;
         }
         int x=i;
         while(st.size()>0&&st.top()[0]>=h[i])
         {
             ans=max(ans,(i-st.top()[1])*st.top()[0]);
             x=st.top()[1];
             st.pop();
         }
         st.push({h[i],x});
     }
     return ans;
        
    }
};
