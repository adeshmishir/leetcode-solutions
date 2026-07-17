class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int>dp(n,1),cnt(n,1);
        int mx = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++ ){
                if(nums[j]<nums[i]){
                  if(dp[i]==dp[j]+1){
                    cnt[i]+=cnt[j];
                  }
                  else if(dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    cnt[i]=cnt[j];
                  }
                }
            }
           
        if(dp[i]>mx){
            mx = dp[i]; 
        }
        }
        for(int i=0;i<n;i++){
            cout<<dp[i]<<" ";
            if(dp[i]==mx){
                ans+=cnt[i];
            }
        }
        cout<<endl;
            for(int i=0;i<n;i++){
            cout<<cnt[i]<<" ";
           
        }
return ans;
    }
};