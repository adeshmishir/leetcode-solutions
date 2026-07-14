// class Solution {
//     //  int solve(int i,vector<int>& nums,int cnt,int buy,vector<vector<vector<int>>>&dp){
//     //     if(i==nums.size())return 0;
//     //     if(dp[i][cnt][buy]!=-1)return dp[i][cnt][buy];
//     //     if(buy){
//     //         if(cnt>0){
//     //             return dp[i][cnt][buy]= max(solve(i+1,nums,cnt-1,0,dp)-nums[i],solve(i+1,nums,cnt,1,dp));
//     //         }
//     //         else{
//     //             return dp[i][cnt][buy]= solve(i+1,nums,cnt,1,dp);
//     //         }
           
//     //     }
//     //     else{
//     //         return dp[i][cnt][buy]= max(solve(i+1,nums,cnt,1,dp)+nums[i],solve(i+1,nums,cnt,0,dp));
//     //     }
//     // }
//       int maxProfit1(int j,int n,vector<int>& nums) {
//         if(j>=nums.size())return 0;
//         int ans= 0;
//         int mini = nums[j];
//         for(int i=j;i<n;i++){
//             ans = max(ans,nums[i]-mini);
//             if(nums[i]<mini){
//                 mini=nums[i];
//             }
//         }
//         return ans;
//     }
// public:
//     int maxProfit(vector<int>& nums) {
//         int n = nums.size();
//         // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(2,-1)));
//         // return solve(0,nums,2,1,dp);
//         int ans =0;
//         for(int i=0;i<n;i++){
//        int a = maxProfit1(0,i+1,nums);
//        int b = maxProfit1(i+1,n,nums);
//         ans= max(ans,a+b);
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> one(n, 0);
        vector<int> two(n, 0);

        int mini = nums[0];

        for (int i = 1; i < n; i++) {
            mini = min(mini, nums[i]);
            one[i] = max(one[i - 1], nums[i] - mini);
        }

        int maxi = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            maxi = max(maxi, nums[i]);
            two[i] = max(two[i + 1], maxi - nums[i]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, one[i] + two[i]);
        }

        return ans;
    }
};