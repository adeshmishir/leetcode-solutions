class Solution {
    int solve(int i, int sum, vector<int>& nums, int val, vector<vector<int>>&dp) {
        if (i == nums.size()) {
            if (sum == val)
                return 1;
            else
                return 0;
        }
        if (sum > val)
            return 0;
            if(dp[i][sum]!=-1)return dp[i][sum];
        return dp[i][sum]= solve(i, sum + nums[i], nums, val,dp) +
               solve(i + 1, sum, nums, val,dp);
    }

public:
    vector<int> findCoins(vector<int>& numWays) {

        vector<int> ans;
        for (int i = 0; i < numWays.size(); i++) {
            int req = numWays[i];
            int n = ans.size();
            vector<vector<int>>dp(n+1,vector<int>(i+2,-1));
            int have = solve(0, 0, ans, i + 1,dp);
            if (req - have == 0)
                continue;
            else if (req - have == 1)
                ans.push_back(i + 1);
            else
                return {};
        }
        return ans;
    }
};