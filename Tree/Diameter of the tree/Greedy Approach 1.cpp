/*
Greedy Approach to find the diameter of the tree.
for every node ,assume that it is on the diameter

Time Complexity :O(n)
Problem Link:https://leetcode.com/problems/diameter-of-binary-tree/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {  
public:
    TreeNode* rt;
    int ans;
    int dfs(TreeNode* node)
    {
        if(node==NULL)
            return -1;
        
        int x=dfs(node->left);  //Returns the deepest node length in a left subtree
        int y=dfs(node->right);
        
        if(x!=-1&&y!=-1)       //if the node has both left and right child
        {
             ans=max(x+y+2,ans);
            return max(x,y)+1;
        }
        
        if(x==-1&&y==-1)    //for leaf node 
        {
            return 0;
        }
        else              //if the node has exactly one child and it is the root then it may be the one end of diameter
        {
            if(node==rt)
            ans=max(ans,max(x,y)+1);
            return max(x,y)+1;
        }
        return 0;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans=0;
        rt=root;
        dfs(root);
        return ans;
    }
};
