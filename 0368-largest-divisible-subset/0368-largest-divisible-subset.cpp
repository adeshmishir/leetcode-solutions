class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // vector<int> dp(nums.size(), 1), prev(nums.size(), -1);
        // int maxi = 0;
        // for (int i = 1; i < nums.size(); i++) {
        //     for (int j = 0; j < i; j++) {
        //         if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
        //             dp[i] = dp[j] + 1;
        //             prev[i] = j;
        //         }
        //     }
        //     if (dp[i] > dp[maxi]) maxi = i;
        // }
        // vector<int> res;
        // for (int i = maxi; i >= 0; i = prev[i]) {
        //     res.push_back(nums[i]);
        // }
        // return res;

        int n = nums.size();
        vector<vector<int>>dp(n);
        for(int i=0;i<n;i++){
            vector<int>v={};
            int maxi = dp[i].size();
            int ind=-1;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[j].size()+1>maxi){
                        maxi=dp[j].size()+1;
                        ind=j;
                    }
                }
            }
            if(ind!=-1){
                dp[i]=dp[ind];
            }
            dp[i].push_back(nums[i]);
        }
        int mx=0;
        int ind=0;
        for(int i=0;i<n;i++){
            if(dp[i].size()>mx){
                mx=dp[i].size();
                ind=i;
            }
        }
        return dp[ind];
    }
};