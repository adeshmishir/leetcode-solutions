/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* solve(vector<int>& nums,int start,int end){
        if(start>end)return NULL;
        if(start==end){
            TreeNode* node =new TreeNode(nums[start]);
            return node;
        }
        int maxi = INT_MIN;
        int ind = -1;
        for(int i=start;i<=end;i++){
            if(maxi<nums[i]){
                ind = i;
                maxi = nums[i];
            }
        }
        TreeNode* node = new TreeNode(maxi);
        node->left = solve(nums,start,ind-1);
        node->right = solve(nums,ind+1,end);
        return node;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return solve(nums,0,n-1);
    }
};