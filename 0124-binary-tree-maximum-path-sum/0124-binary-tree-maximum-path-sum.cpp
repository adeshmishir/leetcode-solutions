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
    int sum(TreeNode* root,int &ans){
        if(!root)return 0;
        int left = max(0,sum(root->left,ans));
        int right = max(0,sum(root->right,ans));
        int val = root->val;

        ans = max(ans,left+right+val);
        //  val = max(0,root->val);
        return max(val+right,val+left);

    }
public:
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        int a = sum(root,ans);
        return ans;
    }
};