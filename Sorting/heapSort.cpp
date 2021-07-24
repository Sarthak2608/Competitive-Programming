/*
https://leetcode.com/problems/sort-an-array/

construction of Tree: First we will build the subtree then we will build the whole tree.
       r1
    r2    r3
  r4 r5  r6  r7
  
If subtree contains maximum value=mx
then root should contains the maximum value


root child index=i
left child node index=2*i
right child node index=2*i+1

whenever condition is not satisfied, swap the value of nodes between root and child.
  
the depth of the tree is logN

Time complexity is O(NlogN for building the tree + NLogN for sorting the array)
Space complexity: O(logN) because we are using recursion.

*/


class Solution {
public:
    
    
    void heapify(vector<int>&nums,int root,int mx){
        if(root>mx)
            return;
        int l=2*root;
        int r=2*root+1;
        if(l<=mx&&r<=mx){
            if(nums[l]>=nums[r]){
                if(nums[root]<nums[l]){
                    swap(nums[root],nums[l]);
                    heapify(nums,l,mx);
                }
            }
            else{
                if(nums[root]<nums[r]){
                   swap(nums[root],nums[r]);
                    heapify(nums,r,mx);
                }
            }
            return;
            
        }
        
        if(l<=mx&&nums[root]<nums[l]){
            swap(nums[root],nums[l]);
            heapify(nums,l,mx);
        }
        
        if(r<=mx&&nums[root]<nums[r]){
            swap(nums[root],nums[r]);
            heapify(nums,r,mx);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        
        for(int i=nums.size()-1;i>=0;i--){
            heapify(nums,i,nums.size()-1);
        }
        
        
        for(int i=nums.size()-1;i>=0;i--){
            swap(nums[i],nums[0]);
            heapify(nums,0,i-1);
        }
        
        return nums;
    }
};
