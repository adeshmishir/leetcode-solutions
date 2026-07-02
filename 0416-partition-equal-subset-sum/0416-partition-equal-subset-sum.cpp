class Solution {
    bool solve(int i,int sum,vector<int>& nums,vector<vector<int>>&dp){
        if(sum==0)return true;
        if(i>=nums.size() || sum<0)return false;
        if(dp[i][sum]!=-1)return dp[i][sum];
        return dp[i][sum]= solve(i+1,sum,nums,dp)||solve(i+1,sum-nums[i],nums,dp);
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=  nums.size();
        int sum=0;
        for(int it:nums)sum+=it;
        if(sum&1)return false;
        sum=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(100*n+1,-1));
       return solve(0,sum,nums,dp);

    }
};