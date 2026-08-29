class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int ans = 1;

        for (int r = 0; r < n; r++) {
            int low = 0, high = r;

            while (low <= high) {
                int l = low + (high - low) / 2;

                long long len = r - l + 1;

                long long sum = prefix[r + 1] - prefix[l];

                long long operations = nums[r] * len - sum;

                if (operations <= k) {
                    ans = max(ans, (int)len);
                    high = l - 1;  
                } else {
                    low = l + 1;
                }
            }
        }

        return ans;
    }
};