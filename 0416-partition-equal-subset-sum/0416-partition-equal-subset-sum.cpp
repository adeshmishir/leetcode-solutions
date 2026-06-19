class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int tsum=0;
        for(int i=0;i<n;i++)tsum+=nums[i];
        if(tsum&1)return false;
        int sum=tsum/2;
        vector<bool>dp(sum+1,false);
        dp[0]=true;
        for(int num:nums){
            for(int s=sum;s>=num;s--){
                dp[s]=dp[s]||dp[s-num];
                if(dp[sum])return true;
            }
            
        }
        return dp[sum];

    }
};