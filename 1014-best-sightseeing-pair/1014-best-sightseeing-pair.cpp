class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n);
        int maxi = INT_MIN;
        for(int i=n-1;i>=0;i--){
            maxi  = max(maxi,nums[i]-i);
            dp[i]=maxi;
        }
        int ans  = INT_MIN;
        for(int i=0;i<n-1;i++){
            ans = max(ans,nums[i]+i+dp[i+1]);
        }
        return ans;
    }
};