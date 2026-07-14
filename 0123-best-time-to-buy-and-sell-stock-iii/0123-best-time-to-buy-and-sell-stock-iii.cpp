class Solution {
     int solve(int i,vector<int>& nums,int cnt,int buy,vector<vector<vector<int>>>&dp){
        if(i==nums.size())return 0;
        if(dp[i][cnt][buy]!=-1)return dp[i][cnt][buy];
        if(buy){
            if(cnt>0){
                return dp[i][cnt][buy]= max(solve(i+1,nums,cnt-1,0,dp)-nums[i],solve(i+1,nums,cnt,1,dp));
            }
            else{
                return dp[i][cnt][buy]= solve(i+1,nums,cnt,1,dp);
            }
           
        }
        else{
            return dp[i][cnt][buy]= max(solve(i+1,nums,cnt,1,dp)+nums[i],solve(i+1,nums,cnt,0,dp));
        }
    }
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(4,vector<int>(2,-1)));
        return solve(0,nums,2,1,dp);
    }
};