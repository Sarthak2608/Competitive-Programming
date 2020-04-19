/*
https://leetcode.com/problems/kth-largest-element-in-an-array/
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        long lw=INT_MIN;
        long hg=INT_MAX;
        while(lw<=hg)
        {
            long mid=(lw+hg)/2;
            int ct=0,e=0;
            for(auto i:nums)
            {
                if(i>mid)
                    ct++;
                else if(i==mid)
                    e++;
            }
            if(ct<k&&ct+e>=k)
            {
                return mid;
            }
            else if(ct+e<k)
            {
                hg=mid-1;
            }
            else  
            {
                lw=mid+1;
            }
            
        }
        return 0;
    }
};
