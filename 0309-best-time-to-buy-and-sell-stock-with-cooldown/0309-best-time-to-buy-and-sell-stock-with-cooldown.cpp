class Solution {
    int solve(vector<int>&nums,int i,int buy,vector<vector<int>>&dp){
        if(i>=nums.size())return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy==1){
            int a = -nums[i]+solve(nums,i+1,0,dp);
            int b = solve(nums,i+1,1,dp);
            return dp[i][buy]= max(a,b);
        }
        else{
            int a = nums[i]+solve(nums,i+2,1,dp);
            int b = solve(nums,i+1,0,dp);
            return dp[i][buy]= max(a,b);
        }
    }
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(nums,0,1,dp);
    }
};