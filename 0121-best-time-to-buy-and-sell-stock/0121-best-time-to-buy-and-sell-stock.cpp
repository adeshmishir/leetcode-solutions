class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int ans= INT_MIN;
        int mini = nums[0];
        for(int i=0;i<n;i++){
            ans = max(ans,nums[i]-mini);
            if(nums[i]<mini){
                mini=nums[i];
            }
        }
        return ans;
    }
};