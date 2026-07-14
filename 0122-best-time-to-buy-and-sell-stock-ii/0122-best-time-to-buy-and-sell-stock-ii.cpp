class Solution {
    int solve(int i,vector<int>& nums,int cnt,vector<vector<int>>&dp){
        if(i==nums.size())return 0;
        if(dp[i][cnt]!=-1)return dp[i][cnt];
        if(cnt){
            return dp[i][cnt]= max(nums[i]+solve(i+1,nums,0,dp),solve(i+1,nums,1,dp));
        }
        else{
            return dp[i][cnt]= max(solve(i+1,nums,1,dp)-nums[i],solve(i+1,nums,0,dp));
        }
    }
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
return solve(0,nums,0,dp);
    }
};