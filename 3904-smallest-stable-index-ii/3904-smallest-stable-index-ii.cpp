class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>ans(n,nums[0]);
        for(int i=1;i<n;i++){
            ans[i] = max(nums[i],ans[i-1]);
        }
        int mini = INT_MAX;
        int val = INT_MAX;
        for(int i=n-1;i>=0;i--){
            mini = min(mini,nums[i]);
            ans[i]-=mini;
            if(ans[i]<=k){
                val=min(val,i);
            }
        }
        if(val==INT_MAX)return -1;
return val;
    }
};