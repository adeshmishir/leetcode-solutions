class Solution {
    int solve(vector<int>& nums, int target,int sum,int i,vector<vector<int>>&dp){
        if(sum==target)return 1;
        if(sum>target)return 0;
        if(i==nums.size())return 0;
        if(dp[i][sum]!=-1)return dp[i][sum];
        
        
       return dp[i][sum]=solve(nums,target,sum+nums[i],0,dp)+solve(nums,target,sum,i+1,dp);

    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(nums,target,0,0,dp);
    }
};