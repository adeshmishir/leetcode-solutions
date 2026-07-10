class Solution {
public:
    vector<int> dp;

    bool solve(int i, vector<int>& nums) {
        int n = nums.size();

        if (i == n)
            return true;

        if (dp[i] != -1)
            return dp[i];

        bool ans = false;

        if (i + 1 < n && nums[i] == nums[i + 1]) {
            ans = ans || solve(i + 2, nums);
        }

        if (i + 2 < n) {
            if (nums[i] == nums[i + 1] &&
                nums[i + 1] == nums[i + 2]) {
                ans = ans || solve(i + 3, nums);
            }

            if (nums[i + 1] == nums[i] + 1 &&
                nums[i + 2] == nums[i] + 2) {
                ans = ans || solve(i + 3, nums);
            }
        }

        return dp[i] = ans;
    }

    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, -1);

        return solve(0, nums);
    }
};