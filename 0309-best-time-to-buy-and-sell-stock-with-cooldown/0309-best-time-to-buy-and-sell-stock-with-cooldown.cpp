class Solution {
    int solve(int i,int buy,vector<int>& nums,vector<vector<int>>&dp){
        if(i>=nums.size())return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy){
            return dp[i][buy]= max(solve(i+1,0,nums,dp)-nums[i],solve(i+1,1,nums,dp));
        }
        else return dp[i][buy]= max(solve(i+2,1,nums,dp)+nums[i],solve(i+1,0,nums,dp));
    }
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
return solve(0,1,nums,dp);
    }
};